/********* WalletPlugin.m Cordova Plugin Implementation *******/
//
//  WalletPlugin.h
//
#import <Foundation/Foundation.h>
#import "WalletPlugin.h"

@implementation WalletPlugin

CDVInvokedUrlCommand * lastCommandCallback;

- (void)pluginInitialize{
    self.tnCService = [TnCService sharedInstance];
    self.registerService = [RegisterService sharedInstance];
    self.authenticateService = [AuthenticateService sharedInstance];
    self.runcheckService = [RuncheckService sharedInstance];
    self.cardListService = [CardListService sharedInstance];
    self.qrPurchaseService = [QRPurchaseService sharedInstance];
    //self.scanQrCodeViewController =[[UIStoryboard storyboardWithName:@"Main" bundle:nil] instantiateViewControllerWithIdentifier:@"QRScanViewController"];
    self.scanQrCodeViewController = [[QrScanViewController alloc]init];
}

- (void)AUTHENTICATION:(CDVInvokedUrlCommand*)command  {
    [self.commandDelegate runInBackground:^{
        @try{
            if( [command.arguments count] == 2
               && [command.arguments objectAtIndex:0] != (id)[NSNull null]
               && [command.arguments objectAtIndex:1] != (id)[NSNull null]){
                AuthenticateReqDto *authenticate = [AuthenticateReqDto new];
                authenticate.userInfo = [command.arguments objectAtIndex:0];//authenticate.userInfo = @"BIM";
                authenticate.authorizationCode = [command.arguments objectAtIndex:1];//self.authorizationCode ? self.authorizationCode : @"";
                [self.authenticateService authenticate:authenticate
                                             onSuccess:^(AuthenticateResDto *authenticateRes) {
                                                 [self sendSuccessResult: [NSDictionary dictionaryWithObjectsAndKeys: [self parseStatus:authenticateRes],@"status", nil] callbackId:command.callbackId];
                                             }
                                             onFailure:^(ResponseDto *response) {
                                                 [self sendErrorResult:response.status.message callbackId:command.callbackId];
                                             }];
            } else {
                [self sendErrorResult:@"Invalid arguments" callbackId:command.callbackId];
            }
        }@catch (NSException *exception) {
            NSLog(@"%@", exception.reason);
            [self sendErrorResult:exception.reason callbackId:command.callbackId];
        }
    }];
}

- (void)IS_WALLET_REGISTERED:(CDVInvokedUrlCommand*)command  {
    [self.commandDelegate runInBackground:^{
        @try{
            if( [command.arguments count] == 1
               && [command.arguments objectAtIndex:0] != (id)[NSNull null]){
                WalletRegisteredReqDto *walletRegistered = [WalletRegisteredReqDto new];
                walletRegistered.userInfo = command.arguments[0];
                [self.registerService walletRegistered:walletRegistered
                                             onSuccess:^(WalletRegisteredResDto *walletRegisteredRes) {
                                                 [self sendSuccessResult:
                                                  [NSDictionary dictionaryWithObjectsAndKeys:
                                                   [self parseStatus:walletRegisteredRes],@"status",
                                                   (walletRegisteredRes.walletStatus.registered ? @"true" : @"false"),@"walletRegistered",
                                                   (walletRegisteredRes.showTnC ? @"true" : @"false"),@"showTnC",
                                                   nil
                                                   ]
                                                              callbackId:command.callbackId];
                                             } onFailure:^(WalletRegisteredResDto *response) {
                                                 [self sendSuccessResult: [NSDictionary dictionaryWithObjectsAndKeys:
                                                                           [self parseStatus:response],@"status",
                                                                           (response.walletStatus.registered ? @"true" : @"false"),@"walletRegistered",
                                                                           (response.showTnC ? @"true" : @"false"),@"showTnC",
                                                                           nil
                                                                           ] callbackId:command.callbackId];
                                             }];
            } else {
                [self sendErrorResult:@"Invalid arguments" callbackId:command.callbackId];
            }
        }@catch (NSException *exception) {
            NSLog(@"%@", exception.reason);
            [self sendErrorResult:exception.reason callbackId:command.callbackId];
        }
    }];
}

- (void)REGISTER_WALLET:(CDVInvokedUrlCommand*)command  {
    [self.commandDelegate runInBackground:^{
        @try{
            if( [command.arguments count] == 1
               && [command.arguments objectAtIndex:0] != (id)[NSNull null]){
                RegisterWalletReqDto *registerWallet = [RegisterWalletReqDto new];
                registerWallet.userInfo = command.arguments[0];
                [self.registerService registerWallet:registerWallet onSuccess:^(RegisterWalletResDto *registerWalletRes) {
                    [self sendSuccessResult:
                     [NSDictionary dictionaryWithObjectsAndKeys:
                      [self parseStatus:registerWalletRes],@"status",
                      (registerWalletRes.walletStatus.registered ? @"true" : @"false"),@"walletRegistered",
                      registerWalletRes.walletStatus.status,@"walletStatus",
                      registerWalletRes.walletId, @"walletId",
                      registerWalletRes.appInstanceId, @"appInstanceId",
                      registerWalletRes.paymentAppInstanceId, @"paymentAppInstanceId",
                      registerWalletRes.salt,@"salt",
                      nil
                      ] callbackId:command.callbackId];
                } onFailure:^(ResponseDto *response) {
                    [self sendErrorResult:response.status.message callbackId:command.callbackId];
                }];
            } else {
                [self sendErrorResult:@"Invalid arguments" callbackId:command.callbackId];
            }
        }@catch (NSException *exception) {
            NSLog(@"%@", exception.reason);
            [self sendErrorResult:exception.reason callbackId:command.callbackId];
        }
    }];
}

- (void)GET_TERMS_AND_CONDITIONS:(CDVInvokedUrlCommand*)command  {
    [self.commandDelegate runInBackground:^{
        @try{
            [self.tnCService tnCOnSuccess:^(TnCResDto *tnC) {
                [self sendSuccessResult:
                 [NSDictionary dictionaryWithObjectsAndKeys:
                  [self parseStatus:tnC],@"status",
                  tnC.version, @"version",
                  tnC.legalDocType, @"legalDocType",
                  tnC.content, @"content",
                  nil
                  ] callbackId:command.callbackId];
            } onFailure:^(ResponseDto *response) {
                [self sendErrorResult:response.status.message callbackId:command.callbackId];
            }];
        }@catch (NSException *exception) {
            NSLog(@"%@", exception.reason);
            [self sendErrorResult:exception.reason callbackId:command.callbackId];
        }
    }];
}

- (void)RUN_CHECK:(CDVInvokedUrlCommand*)command  {
    [self.commandDelegate runInBackground:^{
        @try{
            RuncheckResDto *runCheck = [self.runcheckService getRuncheck];
            [self sendSuccessResult:
             [NSDictionary dictionaryWithObjectsAndKeys:
              runCheck.deviceOEM,@"deviceOEM",
              runCheck.deviceName,@"deviceName",
              runCheck.modelName,@"modelName",
              runCheck.modelNumber,@"modelNumber",
              runCheck.deviceUniqueIdentifier,@"deviceUniqueIdentifier",
              runCheck.screenHeight,@"screenHeight",
              runCheck.screenWidth,@"screenWidth",
              runCheck.osName,@"osName",
              runCheck.osVersion,@"osVersion",
              runCheck.osAlias,@"osAlias",
              runCheck.isDeviceRooted,@"isDeviceRooted",
              runCheck.isDeviceSecureLockEnabled,@"isDeviceSecureLockEnabled",
              runCheck.isDataNetworkAvailable,@"isDataNetworkAvailable",
              nil
              ] callbackId:command.callbackId];
        }@catch (NSException *exception) {
            NSLog(@"%@", exception.reason);
            [self sendErrorResult:exception.reason callbackId:command.callbackId];
        }
    }];
}

- (void)ACCEPT_TNC:(CDVInvokedUrlCommand*)command  {
    [self.commandDelegate runInBackground:^{
        @try{
            if( [command.arguments count] == 1
               && [command.arguments objectAtIndex:0] != (id)[NSNull null]){
                AcceptTnCReqDto *acceptTnC = [AcceptTnCReqDto new];
                acceptTnC.userInfo = command.arguments[0];
                [self.tnCService acceptTnC:acceptTnC
                                 onSuccess:^(AcceptTnCResDto *acceptTnCRes) {
                                     
                                     [self sendSuccessResult:
                                      [NSDictionary dictionaryWithObjectsAndKeys:
                                       [self parseStatus:acceptTnCRes],@"status",
                                       nil
                                       ] callbackId:command.callbackId];
                                 }
                                 onFailure:^(ResponseDto *response) {
                                     [self sendErrorResult:response.status.message callbackId:command.callbackId];
                                 }];
            } else {
                [self sendErrorResult:@"Invalid arguments" callbackId:command.callbackId];
            }
        }@catch (NSException *exception) {
            NSLog(@"%@", exception.reason);
            [self sendErrorResult:exception.reason callbackId:command.callbackId];
        }
    }];
}

- (void)CAPTURE_PAYMENT_QR:(CDVInvokedUrlCommand *)command {
    //    [self.commandDelegate runInBackground:^{
    //check camera permission
    NSString *mediaType = AVMediaTypeVideo;
    AVAuthorizationStatus authStatus = [AVCaptureDevice authorizationStatusForMediaType:mediaType];
    if(authStatus == AVAuthorizationStatusAuthorized) {
        @try{
            lastCommandCallback = command;
            NSDictionary * inputObject = [command.arguments objectAtIndex:0];
            _qrCodeData = nil;
            [self addCaptureView:inputObject];
            
            CDVPluginResult *pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_NO_RESULT
                                                              messageAsString:@"Capture initialized"];
            pluginResult.keepCallback = [NSNumber numberWithBool:true];
            [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
            //                [self.viewController presentViewController:_scanQrCodeViewController animated:YES completion:nil];
        }@catch (NSException *exception) {
            NSLog(@"%@", exception.reason);
            [self sendErrorResult:exception.reason callbackId:command.callbackId];
        }
    } else {
        [AVCaptureDevice requestAccessForMediaType:mediaType completionHandler:^(BOOL granted) {
            if(granted){
                [self CAPTURE_PAYMENT_QR:command];
            } else {
                [self sendErrorResult:@"Camera permission denied" callbackId:command.callbackId];
            }
        }];
    }
    //    }];
}

- (void)CANCEL_CAPTURE_QR:(CDVInvokedUrlCommand *)command {
    @try{
        [self removeCaptureView];
        _qrCodeData = nil;
        [self sendSuccess:@"Capture Cancelled"];
    }@catch (NSException *exception) {
        NSLog(@"%@", exception.reason);
        [self sendErrorResult:exception.reason callbackId:command.callbackId];
    }
}

- (void)QR_VALIDATE:(CDVInvokedUrlCommand *)command {
    [self.commandDelegate runInBackground:^{
        @try{
            if( [command.arguments count] == 1
               && [command.arguments objectAtIndex:0] != (id)[NSNull null]){
                if( _qrCodeData != nil){
                    NSDictionary * inputObject = [command.arguments objectAtIndex:0];
                    CardInfoReqDto *paymentCard = [[CardInfoReqDto alloc] init];
                    paymentCard.cardId = [inputObject objectForKey:@"cardId"];
                    paymentCard.cardType = [inputObject objectForKey:@"cardType"];
                    _qrCodeData.paymentCard = paymentCard;
                    if([inputObject objectForKey:@"tipValue"] != (id)[NSNull null]){
                        _qrCodeData.tipValue = [inputObject objectForKey:@"tipValue"];
                    }
                    if([inputObject objectForKey:@"purchaseValue"] != (id)[NSNull null]){
                        _qrCodeData.purchaseValue = [inputObject objectForKey:@"purchaseValue"];
                    }
                    if([inputObject objectForKey:@"installments"] != (id)[NSNull null]){
                        _qrCodeData.installments = [inputObject objectForKey:@"installments"];
                    }
                    
                    [self.qrPurchaseService validateQRCodeData:_qrCodeData onSuccess:^(QRCodeDataReqDto *qrCodeDataReq) {
                        [self sendSuccessResult:[self parseQrData:qrCodeDataReq] callbackId:command.callbackId];
                    } onFailure:^(QRCodeDataResDto *qrCodeDataRes) {
                        [self sendSuccessResult:[NSDictionary dictionaryWithObjectsAndKeys:
                                                 [self parseStatus:qrCodeDataRes] ,@"status",nil]
                                     callbackId:command.callbackId];
                    }];
                } else {
                    [self sendErrorResult:@"No QRCode Data captured!" callbackId:command.callbackId];
                }
            } else {
                [self sendErrorResult:@"Invalid arguments" callbackId:command.callbackId];
            }
        }@catch (NSException *exception) {
            NSLog(@"%@", exception.reason);
            [self sendErrorResult:exception.reason callbackId:command.callbackId];
        }
    }];
}

- (void)QR_PURCHASE:(CDVInvokedUrlCommand *)command {
    [self.commandDelegate runInBackground:^{
        @try{
            if( _qrCodeData != nil){
                [self.qrPurchaseService qrPurchase:_qrCodeData onSuccess:^(QRCodeDataResDto *response) {
                    [self sendSuccessResult:
                     [NSDictionary dictionaryWithObjectsAndKeys:
                      [self parseStatus:response],@"status",
                      response.approvalNumber,@"approvalNumber",
                      response.transactionDate,@"transactionDate",
                      response.tradeName,@"tradeName",
                      response.cardId,@"cardId",
                      response.totalAmount,@"totalAmount",
                      response.purchaseStatus,@"purchaseStatus",
                      response.city,@"city",
                      response.country,@"country",
                      response.state,@"state",
                      (response.reverseWasDone ? @"true" : @"false"),@"reverseWasDone",
                      (response.wasReverseSuccessful ? @"true" : @"false"),@"wasReverseSuccessful",
                      nil
                      ] callbackId:command.callbackId];
                    _qrCodeData = nil;
                }onFailure:^(ResponseDto *response) {
                    [self sendErrorResult:response.status.message callbackId:command.callbackId];
                }];
            } else {
                [self sendErrorResult:@"No QRCode Data captured!" callbackId:command.callbackId];
            }
        }@catch (NSException *exception) {
            NSLog(@"%@", exception.reason);
            [self sendErrorResult:exception.reason callbackId:command.callbackId];
        }
    }];
}

- (void)GET_CARD_LIST:(CDVInvokedUrlCommand *)command {
    [self.commandDelegate runInBackground:^{
        @try{
            if( [command.arguments count] == 1
               && [command.arguments objectAtIndex:0] != (id)[NSNull null]){
                CardListReqDto *cardList = [CardListReqDto new];
                cardList.userInfo = command.arguments[0];
                [self.cardListService cardList:cardList
                                     onSuccess:^(CardListResDto *response) {
                                         NSMutableDictionary * retDic =[NSMutableDictionary dictionaryWithObjectsAndKeys: [self parseStatus:response],@"status",nil];
                                         if (response.cardsInfo.cardBasicInfo != nil) {
                                             NSMutableArray * cardArray = [[NSMutableArray alloc]init];
                                             for (CardResDto *card in response.cardsInfo.cardBasicInfo) {
                                                 NSDictionary * cardObj = [NSDictionary dictionaryWithObjectsAndKeys:
                                                                           card.cardStatus,@"cardStatus",
                                                                           card.cardImage,@"cardImage",
                                                                           card.cardNumber,@"cardNumber",
                                                                           card.accountType,@"accountType",
                                                                           card.availableBalance,@"availableBalance",
                                                                           card.franchise,@"franchise",
                                                                           card.preferred,@"preferred",
                                                                           card.cardId,@"cardId",
                                                                           card.cardType,@"cardType",
                                                                           (card.hidden ? @"true" : @"false"),@"hidden",
                                                                           nil];
                                                 [cardArray addObject:cardObj];
                                             }
                                             [retDic setObject:cardArray forKey:@"cards"];
                                         }
                                         
                                         [self sendSuccessResult:retDic callbackId:command.callbackId];
                                     }
                                     onFailure:^(ResponseDto *response) {
                                         [self sendErrorResult:response.status.message callbackId:command.callbackId];
                                     }];
            } else {
                [self sendErrorResult:@"Invalid arguments" callbackId:command.callbackId];
            }
        }@catch (NSException *exception) {
            NSLog(@"%@", exception.reason);
            [self sendErrorResult:exception.reason callbackId:command.callbackId];
        }
    }];
}

#pragma Mark Scan QR Code Interface Methods
- (void)addCaptureView:(NSDictionary *)options {
    float windowHeight=  self.webView.bounds.size.height;
    float windowWidth =  self.webView.bounds.size.width;
    float height = ([options objectForKey:@"height"]) ? [[options objectForKey:@"height"] floatValue] : windowHeight;
    float width = ([options objectForKey:@"width"]) ? [[options objectForKey:@"width"] floatValue] : windowWidth;
    float x = ([options objectForKey:@"x"]) ? [[options objectForKey:@"x"] floatValue] : (windowWidth/ 2) - (width/ 2);
    float y = ([options objectForKey:@"y"]) ? [[options objectForKey:@"y"] floatValue] : (windowHeight/ 2) - (height/ 2);
    
    UIViewController * selfController = [self viewController];
    //    _scanQrCodeViewController = [selfController.storyboard instantiateViewControllerWithIdentifier:@"scanController"];
    
    [_scanQrCodeViewController setDelegate:self];
    _scanQrCodeViewController.view = [[UIView alloc] initWithFrame:CGRectMake(x,y,width,height)];
    [_scanQrCodeViewController configureScanQRCodeView:_scanQrCodeViewController.view];
    [_scanQrCodeViewController startCameraSession];
    
    _scanQRCodeView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    [selfController addChildViewController:_scanQrCodeViewController];
    [selfController didMoveToParentViewController:_scanQrCodeViewController];
    //    [_scanQrCodeViewController view].frame = [selfController view].bounds;
    [_scanQrCodeViewController willMoveToParentViewController:selfController];
    [[selfController view] addSubview:[_scanQrCodeViewController view]];
}

#pragma Mark Scan QR Code Interface Methods
- (void)removeCaptureView{
    [_scanQrCodeViewController.view removeFromSuperview];
    [_scanQrCodeViewController stopCameraSession];
    [_scanQrCodeViewController willMoveToParentViewController:nil];
    [_scanQrCodeViewController removeFromParentViewController];
}

- (void)onQrCodeDetected:(QRCodeDataReqDto *)qD {
    _qrCodeData = qD;
    //    lastCommandCallback = nil;
}


- (void)onStatusResponse:(StatusResDto *)data {
    [self removeCaptureView];
    NSDictionary * rectDict;
    if(_qrCodeData!= nil){
        NSDictionary * qrDataDict = [self parseQrData: _qrCodeData];
        rectDict = [NSDictionary dictionaryWithObjectsAndKeys:
                    [self parseStatusDto:data],@"status",
                    qrDataDict,@"qrData",
                    nil
                    ];
    }else{
        rectDict = [NSDictionary dictionaryWithObjectsAndKeys:
                    [self parseStatusDto:data],@"status",
                    nil,@"qrData",
                    nil
                    ];
    }
    [self sendSuccessResult:rectDict callbackId:lastCommandCallback.callbackId];
    lastCommandCallback = nil;
}

- (NSDictionary*)parseQrData:(QRCodeDataReqDto*) qrData{
    return [NSDictionary dictionaryWithObjectsAndKeys:
            qrData.qrCodeType,@"qrCodeType",
            qrData.transactionId,@"transactionId",
            qrData.channel,@"channel",
            qrData.tradeCode,@"tradeCode",
            qrData.tradeName,@"tradeName",
            qrData.address,@"address",
            qrData.clientNumber,@"clientNumber",
            qrData.totalPrice,@"totalPrice",
            qrData.purchaseValue,@"purchaseValue",
            qrData.incRequired,@"incRequired",
            qrData.incMaxPercent,@"incMaxPercent",
            qrData.incValue,@"incValue",
            qrData.ivaRequired,@"ivaRequired",
            qrData.maxIvaPercent,@"maxIvaPercent",
            qrData.ivaValue,@"ivaValue",
            qrData.tipRequired,@"tipRequired",
            qrData.maxTipPercent,@"maxTipPercent",
            qrData.tipValue,@"tipValue",
            qrData.devolutionValue,@"devolutionValue",
            qrData.clientType,@"clientType",
            qrData.installments,@"installments",
            qrData.transactionApprovalNumber,@"transactionApprovalNumber",
            qrData.formattedTransactionTime,@"formattedTransactionTime",
            qrData.transactionDepartment,@"transactionDepartment",
            qrData.transactionCity,@"transactionCity",
            [NSDictionary dictionaryWithObjectsAndKeys:qrData.paymentCard.cardId,@"cardId",qrData.paymentCard.cardType,@"cardType",nil],"paymentCard",
            (qrData.isStatic? @"true" : @"false"),@"isStatic",
            (qrData.isTIPRequested? @"true" : @"false"),@"isTIPRequested",
            (qrData.isIVARequested? @"true" : @"false"),@"isIVARequested",
            (qrData.isINCRequested? @"true" : @"false"),@"isINCRequested",
            nil
            ];
}
-(void)sendErrorResult:(NSString *)message callbackId:(NSString *)callbackId {
    NSMutableDictionary *dictionary = [NSMutableDictionary dictionary];
    [dictionary setObject:message forKey:@"errorMessage"];
    [dictionary setObject:[NSNumber numberWithInt:1] forKey:@"errorCode"];
    [dictionary setObject:[NSNumber numberWithBool:false] forKey:@"success"];
    CDVPluginResult *pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR
                                                      messageAsString:[dictionary description]];
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:callbackId];
}

#pragma Utils
-(NSDictionary *) parseStatus:(ResponseDto *) response{
    return [self parseStatusDto:response.status];
}

-(NSDictionary *) parseStatusDto:(StatusResDto *) response{
    return [NSDictionary dictionaryWithObjectsAndKeys:
            response.code,@"code",
            response.transaction,@"transaction",
            response.message,@"message",
            nil
            ];
}

-(void)sendSuccessResult:(NSDictionary *)dictionary callbackId:(NSString *)callbackId {
    NSError *error;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:dictionary
                                                       options:0 //NSJSONWritingPrettyPrinted // Pass 0 if you don't care about the readability of the generated string
                                                         error:&error];
    NSString *jsonString = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
    CDVPluginResult *pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK
                                                      messageAsString:jsonString];
    [self.commandDelegate sendPluginResult:pluginResult callbackId:callbackId];
}

-(void)sendSuccess:(NSString *)callbackId {
    CDVPluginResult *pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    [self.commandDelegate sendPluginResult:pluginResult callbackId:callbackId];
}

-(void)sendSuccessMessage:(NSString *)message andCallbackId:(NSString *)callbackId {
    CDVPluginResult *pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:message];
    [self.commandDelegate sendPluginResult:pluginResult callbackId:callbackId];
}

@end
