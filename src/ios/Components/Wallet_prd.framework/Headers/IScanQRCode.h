//
//  IScanQRCode.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 2/27/18.
//  Copyright © 2018 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol IScanQRCode <NSObject>

/*!
 *  @discussion This method get encrypted QR code data informartion request data transfer object.
 *  @param qrCodeData provide QR code data request data transfer object.
 */
- (void)getEncryptedQRCode:(QRCodeDataReqDto * _Nullable)qrCodeData;

/*!
 *  @discussion This method get status response information.
 *  @param status provide status response data transfer object.
 */
- (void)getStatusResponse:(StatusResDto * _Nullable)status;

@end
