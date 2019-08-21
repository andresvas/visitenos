#ifndef WalletPlugin_h
#define WalletPlugin_h
#import <Cordova/CDVPlugin.h>
#import "QrScanViewController.h"

@interface WalletPlugin : CDVPlugin <QrScanViewControllerDelegate>
- (void)AUTHENTICATION:(CDVInvokedUrlCommand*)command;
- (void)IS_WALLET_REGISTERED:(CDVInvokedUrlCommand*)command;
- (void)REGISTER_WALLET:(CDVInvokedUrlCommand*)command;
- (void)GET_TERMS_AND_CONDITIONS:(CDVInvokedUrlCommand*)command;
- (void)RUN_CHECK:(CDVInvokedUrlCommand*)command;
- (void)ACCEPT_TNC:(CDVInvokedUrlCommand*)command;
- (void)GET_CARD_LIST:(CDVInvokedUrlCommand*)command;
- (void)CAPTURE_PAYMENT_QR:(CDVInvokedUrlCommand*)command;


@property (nonatomic, strong) TnCService *tnCService;
@property (nonatomic, strong) RegisterService *registerService;
@property (nonatomic, strong) AuthenticateService *authenticateService;
@property (nonatomic, strong) RuncheckService *runcheckService;
@property (nonatomic, strong) CardListService *cardListService;
@property (nonatomic, strong) QRPurchaseService *qrPurchaseService;
@property (nonatomic, strong) QRCodeDataReqDto *qrCodeData;

@property (nonatomic, strong) QrScanViewController *scanQrCodeViewController;
@property (nonatomic, retain) UIView *scanQRCodeView;

#endif /* WalletPlugin_h */
@end
