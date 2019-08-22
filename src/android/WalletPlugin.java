package com.todo1.plugins.wallet;

import android.Manifest;
import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.graphics.Color;
import android.support.annotation.NonNull;
import android.util.DisplayMetrics;


import android.util.TypedValue;
import android.view.SurfaceView;
import android.view.ViewGroup;
import android.view.ViewParent;
import android.widget.FrameLayout;

import com.google.gson.Gson;
import com.google.gson.JsonObject;
import com.intergrupo.bancolombia.bancolombialibrary.Location.MonitoringControl;
import com.intergrupo.bancolombia.bancolombialibrary.Presentation.Map.implementations.MapsActivity;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.CordovaInterface;
import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.CordovaWebView;
import org.apache.cordova.PermissionHelper;
import org.apache.cordova.PluginResult;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.UUID;

import co.com.bancolombia.walletsdk.WalletApplication;
import co.com.bancolombia.walletsdk.business.capture.CaptureServiceManager;
import co.com.bancolombia.walletsdk.business.capture.ICaptureEvent;
import co.com.bancolombia.walletsdk.business.cardlist.CardListServiceManager;
import co.com.bancolombia.walletsdk.business.cardlist.ICardListEvent;
import co.com.bancolombia.walletsdk.business.payment.IPayment;
import co.com.bancolombia.walletsdk.business.payment.PaymentServiceManager;
import co.com.bancolombia.walletsdk.business.registry.IRegistryEvent;
import co.com.bancolombia.walletsdk.business.registry.RegistryServiceManager;
import co.com.bancolombia.walletsdk.business.security.authenticate.AuthenticateServiceManager;
import co.com.bancolombia.walletsdk.business.security.authenticate.IAuthEvent;
import co.com.bancolombia.walletsdk.business.termsnconditions.ITermsNConditions;
import co.com.bancolombia.walletsdk.business.termsnconditions.TermsNConditionsServiceManager;
import co.com.bancolombia.walletsdk.data.model.dto.request.AcceptTnCReqDto;
import co.com.bancolombia.walletsdk.data.model.dto.request.AuthenticateReqDto;
import co.com.bancolombia.walletsdk.data.model.dto.request.CardListReqDto;
import co.com.bancolombia.walletsdk.data.model.dto.request.QRPurchaseReqDto;
import co.com.bancolombia.walletsdk.data.model.dto.request.RegisterWalletReqDto;
import co.com.bancolombia.walletsdk.data.model.dto.request.WalletRegisteredReqDto;
import co.com.bancolombia.walletsdk.data.model.dto.response.AcceptTnCResDto;
import co.com.bancolombia.walletsdk.data.model.dto.response.AuthenticateResDto;
import co.com.bancolombia.walletsdk.data.model.dto.response.CVCVerificationResDto;
import co.com.bancolombia.walletsdk.data.model.dto.response.FinishRegisterResDto;
import co.com.bancolombia.walletsdk.data.model.dto.response.GetTnCResDto;
import co.com.bancolombia.walletsdk.data.model.dto.response.HideCardResDto;
import co.com.bancolombia.walletsdk.data.model.dto.response.PreferredCardResDto;
import co.com.bancolombia.walletsdk.data.model.dto.response.QrValidationResDto;
import co.com.bancolombia.walletsdk.data.model.dto.response.RegisterWalletResDto;
import co.com.bancolombia.walletsdk.data.model.dto.response.UnHideCardResDto;
import co.com.bancolombia.walletsdk.data.model.dto.response.WalletRegisteredResDto;
import co.com.bancolombia.walletsdk.data.model.dto.response.cardlist.CardListResDto;
import co.com.bancolombia.walletsdk.data.model.dto.response.qrpayment.QRPurchaseResDto;
import co.com.bancolombia.walletsdk.data.model.dto.transversal.CardInfo;
import co.com.bancolombia.walletsdk.data.model.dto.transversal.QRCodeData;
import co.com.bancolombia.walletsdk.data.model.dto.transversal.StatusDto;
import co.com.bancolombia.walletsdk.data.model.wsdto.response.CVCParameterWSRes;



/**
 * This class echoes a string called from JavaScript.
 */
public class WalletPlugin extends CordovaPlugin implements IAuthEvent, IRegistryEvent, ITermsNConditions, ICardListEvent, IPayment, ICaptureEvent {
    private static final int CAPTURE_QR_REQ_CODE = 190;
    private static final int CAMERA_PERMISSION = 9;
    private CallbackContext lastCallback;
    private JSONArray lastArgs;
    private MonitoringControl controlMonitoreo;
    private AuthenticateServiceManager authenticateService;
    private RegistryServiceManager registerService;
    private CardListServiceManager getCardListService;
    private PaymentServiceManager paymentServiceManager;
    private TermsNConditionsServiceManager termsNConditionsServiceManager;
    private CaptureServiceManager captureServiceManager;
    private QRPurchaseReqDto lastpurchaseReq;
    private QRCodeData qrCodeData;
    private int cameraSurfaceViewId = -20;
    private ViewParent webViewParent;
    private FrameLayout containerView;

    public static String getUUID() {
        UUID value = UUID.randomUUID();
        return value.toString();
    }

    @Override
    public void initialize(CordovaInterface cordova, CordovaWebView webView) {
        super.initialize(cordova, webView);
        Context ctx = cordova.getActivity();
        WalletApplication.init(cordova.getActivity().getApplication());
        authenticateService = new AuthenticateServiceManager(ctx);
        registerService = new RegistryServiceManager(ctx, this);
        getCardListService = new CardListServiceManager(ctx, this);
        paymentServiceManager = new PaymentServiceManager(ctx);
        termsNConditionsServiceManager = new TermsNConditionsServiceManager(ctx, this);
    }

    private void returnAndKeepCallback(CallbackContext callbackContext) {
        PluginResult pr = new PluginResult(PluginResult.Status.NO_RESULT);
        pr.setKeepCallback(true);
        callbackContext.sendPluginResult(pr);
    }

    @Override
    public boolean execute(String action, JSONArray args, CallbackContext callbackContext) throws JSONException {
        try {
            if (lastCallback != null && !lastCallback.isFinished()) {
                lastCallback.error("Canceled");
            }
            lastCallback = callbackContext;
            lastArgs = args;
            Action ac = Action.fromString(action);
            if (isValidArguments(ac, args)) {
                switch (ac) {
                    case AUTHENTICATION:
                        authenticateService.authenticate(new AuthenticateReqDto(args.getString(0), args.getString(1)), this);
                        returnAndKeepCallback(callbackContext);
                        return true;
                    case IS_WALLET_REGISTERED:
                        WalletRegisteredReqDto walletRegisteredReqDto = new WalletRegisteredReqDto();
                        walletRegisteredReqDto.setUserInfo(args.getString(0));
                        registerService.isWalletRegistered(walletRegisteredReqDto);
                        returnAndKeepCallback(callbackContext);
                        return true;
                    case REGISTER_WALLET:
                        registerService.registerWallet(new RegisterWalletReqDto(args.getString(0)));
                        returnAndKeepCallback(callbackContext);
                        return true;
                    case GET_TERMS_AND_CONDITIONS:
                        termsNConditionsServiceManager.getTnC();
                        returnAndKeepCallback(callbackContext);
                        return true;
                    case ACCEPT_TNC:
                        termsNConditionsServiceManager.acceptTnC(new AcceptTnCReqDto(args.getString(0)));
                        returnAndKeepCallback(callbackContext);
                        return true;
                    case GET_CARD_LIST:
                        CardListReqDto cardListReqDto = new CardListReqDto();
                        cardListReqDto.setUserInfo(args.getString(0));
                        returnAndKeepCallback(callbackContext);
                        getCardListService.getCardList(cardListReqDto);
                        return true;
                    case QR_VALIDATE:
                        JSONObject jsonObject = args.getJSONObject(0);
                        String purchaseValue = jsonObject.optString("purchaseValue", "");
                        if (!purchaseValue.isEmpty()) {
                            qrCodeData.setPurchaseValue(purchaseValue);
                        }
                        String tipValue = jsonObject.optString("tipValue", "");
                        if (!tipValue.isEmpty()) {
                            qrCodeData.setTipValue(tipValue);
                        }
                        int installments = jsonObject.optInt("installments", 0);
                        lastpurchaseReq = new QRPurchaseReqDto(new CardInfo(jsonObject.getString("cardId"),
                                jsonObject.getString("cardType")),
                                qrCodeData,
                                installments);
                        paymentServiceManager.validateQRData(lastpurchaseReq, this);
                        returnAndKeepCallback(callbackContext);
                        return true;
                    case QR_PURCHASE:
                        paymentServiceManager.qrPurchase(lastpurchaseReq, this);
                        returnAndKeepCallback(callbackContext);
                        return true;
                    case CANCEL_CAPTURE_QR:
                        cancelCaptureQrCode(callbackContext);
                        return true;
                    case CAPTURE_PAYMENT_QR:
                        if (!PermissionHelper.hasPermission(this, Manifest.permission.CAMERA)) {
                            PermissionHelper.requestPermission(this, CAMERA_PERMISSION, Manifest.permission.CAMERA);
                        } else {
                            startCameraActivity(lastCallback, args);
                            returnAndKeepCallback(lastCallback);
                        }
                        return true;
                    case OPEN_VISIT_US:
                    CordovaPlugin cord = this;
                    this.cordova.getThreadPool().execute(new Runnable() {
                        @Override
                        public void run() {
                            callbackContext.success();
                            Intent intent = new Intent(cordova.getActivity(), MapsActivity.class);
                            cordova.startActivityForResult(cord, intent, 0);
                        }
                    });
                        return true;
                    case INIT_MONITORING_CONTROL:
                        String tokenId = getUUID() + "|" + getUUID();
                        controlMonitoreo = new MonitoringControl(tokenId, cordova.getActivity());
                        callbackContext.success();
                        return true;
                    default:
                        callbackContext.error("Action not implemented");
                        return false;
                }
            } else {
                callbackContext.sendPluginResult(new PluginResult(PluginResult.Status.INVALID_ACTION, "INVALID ARGUMENTS"));
                return false;
            }
        } catch (Exception e) {
            e.printStackTrace();
            callbackContext.error(e.getMessage());
            return false;
        }
    }

    private void startCameraActivity(CallbackContext callbackContext, JSONArray args) {
        Activity ctx = cordova.getActivity();
        ctx.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                containerView = ctx.findViewById(cameraSurfaceViewId);
                if (containerView == null) {
                    containerView = new FrameLayout(ctx.getApplicationContext());
                    DisplayMetrics metrics = ctx.getResources().getDisplayMetrics();
                    int x, y, width, height;

                    JSONObject jsonObject;
                    try {
                        jsonObject = args.getJSONObject(0);
                    } catch (JSONException e) {
                        e.printStackTrace();
                        callbackContext.error(e.getMessage());
                        return;
                    }
                    x = jsonObject.optInt("x", 0);
                    y = jsonObject.optInt("y", 0);
                    width = jsonObject.optInt("width", FrameLayout.LayoutParams.MATCH_PARENT);
                    height = jsonObject.optInt("height", FrameLayout.LayoutParams.MATCH_PARENT);
                    //calculate size
                    // offset
                    int computedX = (int) TypedValue.applyDimension(TypedValue.COMPLEX_UNIT_DIP, x, metrics);
                    int computedY = (int) TypedValue.applyDimension(TypedValue.COMPLEX_UNIT_DIP, y, metrics);

                    // size
                    int computedWidth = (int) TypedValue.applyDimension(TypedValue.COMPLEX_UNIT_DIP, width, metrics);
                    int computedHeight = (int) TypedValue.applyDimension(TypedValue.COMPLEX_UNIT_DIP, height, metrics);
                    containerView.setId(cameraSurfaceViewId);
                    containerView.setPadding(computedX, computedY, computedX, computedY);
                    FrameLayout.LayoutParams containerLayoutParams = new FrameLayout.LayoutParams(computedWidth, computedHeight);
                    ctx.addContentView(containerView, containerLayoutParams);
                }
                SurfaceView surfaceView = new SurfaceView(ctx);
                containerView.addView(surfaceView);
                containerView.setBackgroundColor(Color.TRANSPARENT);
                captureServiceManager = new CaptureServiceManager(ctx, surfaceView, WalletPlugin.this);
                captureServiceManager.startService();
                webView.getView().setBackgroundColor(0x00000000);
                webViewParent = webView.getView().getParent();
                webView.getView().bringToFront();
            }
        });

    }

    public void onRequestPermissionResult(int requestCode, String[] permissions,
                                          int[] grantResults) throws JSONException {
        for (int r : grantResults) {
            if (r == PackageManager.PERMISSION_DENIED) {
                lastCallback.sendPluginResult(new PluginResult(PluginResult.Status.ERROR, "Permissions Denied"));
                return;
            }
        }
        switch (requestCode) {
            case CAMERA_PERMISSION:
                startCameraActivity(lastCallback, lastArgs);
                returnAndKeepCallback(lastCallback);
                break;
        }
    }


    @Override
    public void captureQrResponse(QRCodeData qrData, StatusDto statusDto) {
        JsonObject jsonObject = new JsonObject();
        qrCodeData = qrData;
        jsonObject.add("qrCodeData", new Gson().toJsonTree(qrCodeData));
        jsonObject.add("status", new Gson().toJsonTree(statusDto));
        lastCallback.success(jsonObject.toString());
        cordova.getActivity().runOnUiThread(new Runnable() {
            @Override
            public void run() {
                removeSurfaceView();
            }
        });
    }

    public void cancelCaptureQrCode(CallbackContext cc) {
        cordova.getActivity().runOnUiThread(new Runnable() {
            @Override
            public void run() {
                removeSurfaceView();
                cc.success();
            }
        });
    }

    private void removeSurfaceView() {
        if (webViewParent != null) {
            ((ViewGroup) webView.getView()).bringToFront();
            webViewParent = null;
            containerView.removeAllViews();
        }
    }

    @Override
    public void authenticateResponse(AuthenticateResDto authenticateResDto) {
        if (!lastCallback.isFinished()) {
            lastCallback.success(new Gson().toJson(authenticateResDto));
        }
    }

    @Override
    public void isWalletRegisteredResponse(WalletRegisteredResDto response) {
        if (!lastCallback.isFinished()) {
            lastCallback.success(new Gson().toJson(response));
        }
    }

    @Override
    public void registerWalletResponse(RegisterWalletResDto response) {
        if (!lastCallback.isFinished()) {
            lastCallback.success(new Gson().toJson(response));
        }
    }

    @Override
    public void finishRegisterResponse(FinishRegisterResDto finishRegisterResDto) {
//IGNORE
    }

    @Override
    public void getTnCResponse(GetTnCResDto response) {
        if (!lastCallback.isFinished()) {
            lastCallback.success(new Gson().toJson(response));
        }
    }

    @Override
    public void acceptTnCResponse(AcceptTnCResDto response) {
        if (!lastCallback.isFinished()) {
            lastCallback.success(new Gson().toJson(response));
        }
    }

    private boolean isValidArguments(Action ac, JSONArray args) {
        try {
            switch (ac) {
                case AUTHENTICATION:
                    return args.length() == 2 && args.getString(0).length() > -1 && args.getString(1).length() > -1;
                case IS_WALLET_REGISTERED:
                case REGISTER_WALLET:
                case ACCEPT_TNC:
                case GET_CARD_LIST:
                    return args.length() == 1 && args.getString(0).length() > -1;
                case CANCEL_CAPTURE_QR:
                case GET_TERMS_AND_CONDITIONS:
                case RUN_CHECK:
                case OPEN_VISIT_US:
                case INIT_MONITORING_CONTROL:
                    return args.length() == 0;
                case QR_PURCHASE:
                case QR_VALIDATE:
                case CAPTURE_PAYMENT_QR:
                    return true;
                default:
                    return false;
            }
        } catch (JSONException e) {
            return false;
        }
    }

    @Override
    public void getCardListResponse(CardListResDto response) {
        if (!lastCallback.isFinished()) {
            lastCallback.success(new Gson().toJson(response));
        }
    }

    @Override
    public void hideCardResponse(HideCardResDto hideCardResDto) {
//IGNORE
    }

    @Override
    public void unHideCardResponse(UnHideCardResDto unHideCardResDto) {
//IGNORE
    }

    @Override
    public void setDefaultCardResponse(PreferredCardResDto preferredCardResDto) {
//IGNORE
    }

    @Override
    public void cvcParameterResponse(CVCParameterWSRes cvcParameterWSRes) {

    }

    @Override
    public void cvcVerificationResponse(CVCVerificationResDto cvcVerificationResDto) {

    }

    @Override
    public void qrPurchaseResponse(QRPurchaseResDto response) {
        if (!lastCallback.isFinished()) {
            lastCallback.success(new Gson().toJson(response));
            lastpurchaseReq = null;
        }
    }

    @Override
    public void qrDataValidationResponse(QrValidationResDto response) {
        if (!lastCallback.isFinished()) {
            lastCallback.success(new Gson().toJson(response));
            qrCodeData = response.getQrPurchaseReqDto().getQrCodeData();
        }
    }

    public enum Action {
        AUTHENTICATION,
        IS_WALLET_REGISTERED,
        REGISTER_WALLET,
        GET_TERMS_AND_CONDITIONS,
        RUN_CHECK,
        ACCEPT_TNC,
        GET_CARD_LIST,
        CAPTURE_PAYMENT_QR,
        CANCEL_CAPTURE_QR,
        QR_PURCHASE,
        QR_VALIDATE,
        OPEN_VISIT_US,
        INIT_MONITORING_CONTROL,
        INVALID;


        @NonNull
        public static Action fromString(String action) {
            try {
                return Action.valueOf(action);
            } catch (IllegalArgumentException e) {
                return INVALID;
            }
        }
    }

}
