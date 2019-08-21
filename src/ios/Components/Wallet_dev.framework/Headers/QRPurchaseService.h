//
//  QRPurchaseService.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 5/30/18.
//  Copyright © 2018 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QRCodeDataReqDto.h"
#import "QRCodeDataResDto.h"

@interface QRPurchaseService : NSObject

/*!
 *  @discussion This method knows is constructor for this class.
 */
+ (instancetype)sharedInstance;

/*!
 *  @discussion This method send the QR code data for payment.
 *  @param qrCodeData provide data for payment.
 *  @param success provide data for detail purchase.
 *  @param failure provide status data with error information.
 */
- (void)qrPurchase:(QRCodeDataReqDto *)qrCodeData
         onSuccess:(void (^)(QRCodeDataResDto *qrCodeDataRes))success
         onFailure:(void (^)(QRCodeDataResDto *qrCodeDataRes))failure;

/*!
 *  @discussion This method validate and calculate TIP, IVA and INC.
 *  @param success provide provide QR Code data for payment.
 *  @param failure provide status data with error information.
 */
- (void)validateQRCodeData:(QRCodeDataReqDto *)qrCodeData
                 onSuccess:(void (^)(QRCodeDataReqDto *qrCodeDataReq))success
                 onFailure:(void (^)(QRCodeDataResDto *qrCodeDataRes))failure;

@end
