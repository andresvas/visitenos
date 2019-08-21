//
//  QRCodeDataReqDto.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 2/26/18.
//  Copyright © 2018 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CardInfoReqDto.h"

@interface QRCodeDataReqDto : NSObject

/*!
 *  @discussion  This property knows qr code type.
 */
@property (nullable, nonatomic, strong) NSString *qrCodeType;
/*!
 *  @discussion This property knows transaction id.
 */
@property (nullable, nonatomic, strong) NSString *transactionId;
/*!
 *  @discussion This property knows channel.
 */
@property (nullable, nonatomic, strong) NSString *channel;
/*!
 *  @discussion This property knows trade code.
 */
@property (nullable, nonatomic, strong) NSString *tradeCode;
/*!
 *  @discussion This property knows trade name.
 */
@property (nullable, nonatomic, strong) NSString *tradeName;
/*!
 *  @discussion This property knows address.
 */
@property (nullable, nonatomic, strong) NSString *address;
/*!
 *  @discussion This property knows client number.
 */
@property (nullable, nonatomic, strong) NSString *clientNumber;
/*!
 *  @discussion This property knows total price.
 */
@property (nullable, nonatomic, strong) NSString *totalPrice;
/*!
 *  @discussion This property knows purchase value.
 */
@property (nullable, nonatomic, strong) NSString *purchaseValue;
/*!
 *  @discussion This property knows INC is required.
 */
@property (nullable, nonatomic, strong) NSString *incRequired;
/*!
 *  @discussion This property knows INC maximum percent.
 */
@property (nullable, nonatomic, strong) NSString *incMaxPercent;
/*!
 *  @discussion This property knows INC value.
 */
@property (nullable, nonatomic, strong) NSString *incValue;
/*!
 *  @discussion This property knows IVA is required.
 */
@property (nullable, nonatomic, strong) NSString *ivaRequired;
/*!
 *  @discussion This property knows IVA maximum percent.
 */
@property (nullable, nonatomic, strong) NSString *maxIvaPercent;
/*!
 *  @discussion This property knows IVA value.
 */
@property (nullable, nonatomic, strong) NSString *ivaValue;
/*!
 *  @discussion This property knows TIP is required.
 */
@property (nullable, nonatomic, strong) NSString *tipRequired;
/*!
 *  @discussion This property knows TIP maximum percent.
 */
@property (nullable, nonatomic, strong) NSString *maxTipPercent;
/*!
 *  @discussion This property knows TIP value.
 */
@property (nullable, nonatomic, strong) NSString *tipValue;
/*!
 *  @discussion This property knows devolution value.
 */
@property (nullable, nonatomic, strong) NSString *devolutionValue;

/*!
 *  @discussion This property knows client type.
 */
@property (nullable, nonatomic, strong) NSString *clientType;

/*!
 *  @discussion This property knows installments.
 */
@property (nullable, nonatomic, strong) NSNumber *installments;
/*!
 *  @discussion This property knows payment card.
 */
@property (nullable, nonatomic, strong) CardInfoReqDto *paymentCard;

/*!
 *  @discussion This property knows transaction approval number.
 */
@property (nullable, nonatomic, strong) NSString *transactionApprovalNumber;
/*!
 *  @discussion This property knows formatted transaction time.
 */
@property (nullable, nonatomic, strong) NSString *formattedTransactionTime;

/*!
 *  @discussion This property knows transaction departament.
 */
@property (nullable, nonatomic, strong) NSString *transactionDepartment;
/*!
 *  @discussion This property knows transaction city.
 */
@property (nullable, nonatomic, strong) NSString *transactionCity;

/*!
 *  @discussion This method knows is static QR code.
 *  @return boolean for is or not static QR code.
 */
- (BOOL)isStatic;

/*!
 *  @discussion This method knows is TIP Requested.
 *  @return boolean for is or not TIP requested.
 */
- (BOOL)isTIPRequested;

/*!
 *  @discussion This method knows is IVA Requested.
 *  @return boolean for is or not IVA requested.
 */
- (BOOL)isIVARequested;

/*!
 *  @discussion This method knows is INC Requested.
 *  @return boolean for is or not INC requested.
 */
- (BOOL)isINCRequested;

/*!
 *  @discussion This method knows is constructor for this class with parameters:
 *  @param ecryptedQRCodeString provide data ecrypted QR code string.
 *  @param interpreter provide interpreter for decrypt QR code.
 */
- (instancetype)initWithQRCodeString:(nonnull NSString *)ecryptedQRCodeString
                      andInterpreter:(nonnull id)interpreter;

/*!
 *  @discussion This method knows is constructor for this class with parameter:
 *  @param qrCodeString provide data QR code string.
 */
- (instancetype)getQRCodeData:(NSString *)qrCodeString;

/*!
 *  @discussion This method knows transform this class to request for web service.
 *  @param dto provide QR code data request data transfer object.
 *  @return web service request object.
 */
+ (id)mapDTOToRequest:(QRCodeDataReqDto *)dto;

@end
