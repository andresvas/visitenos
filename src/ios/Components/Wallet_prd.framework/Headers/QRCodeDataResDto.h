//
//  QRCodeDataResDto.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 3/1/18.
//  Copyright © 2018 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ResponseDto.h"

@interface QRCodeDataResDto : ResponseDto

/*!
 *  @discussion This property knows approval number.
 */
@property (nonatomic, strong) NSString *approvalNumber;
/*!
 *  @discussion This property knows transaction date.
 */
@property (nonatomic) long long transactionDate;
/*!
 *  @discussion This property knows trade name.
 */
@property (nonatomic, strong) NSString *tradeName;
/*!
 *  @discussion This property knows card id.
 */
@property (nonatomic, strong) NSString *cardId;
/*!
 *  @discussion This property knows total amount.
 */
@property (nonatomic, strong) NSDecimalNumber *totalAmount;
/*!
 *  @discussion This property knows purchase status.
 */
@property (nonatomic, strong) NSString *purchaseStatus;
/*!
 *  @discussion This property knows city.
 */
@property (nonatomic, strong) NSString *city;
/*!
 *  @discussion This property knows country.
 */
@property (nonatomic, strong) NSString *country;
/*!
 *  @discussion This property knows state.
 */
@property (nonatomic, strong) NSString *state;
/*!
 *  @discussion This property knows reverse was done.
 */
@property (nonatomic) BOOL reverseWasDone;
/*!
 *  @discussion This property knows was reverse successful.
 */
@property (nonatomic) BOOL wasReverseSuccessful;

/*!
 *  @discussion This method knows transform this class to response for DTO.
 *  @param response provide data web service response object.
 *  @return QR code data response data transfer object.
 */
+ (QRCodeDataResDto *)mapResponseToDTO:(id)response;
/*!
 *  @discussion This method knows transform this class to response for status.
 *  @param status provide data web service response object.
 *  @return QR code data response data transfer object.
 */
+ (QRCodeDataResDto *)mapStatusResToDTO:(id)status;

@end
