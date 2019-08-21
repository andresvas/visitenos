//
//  RegisterWalletResDto.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 4/11/18.
//  Copyright © 2018 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import "ResponseDto.h"
#import "WalletStatusResDto.h"

@interface RegisterWalletResDto : ResponseDto

/*!
 *  @discussion This property knows wallet id.
 */
@property (nonatomic, strong) NSString *walletId;
/*!
 *  @discussion This property knows app instance id.
 */
@property (nonatomic, strong) NSString *appInstanceId;
/*!
 *  @discussion This property knows payment app instance id.
 */
@property (nonatomic, strong) NSString *paymentAppInstanceId;
/*!
 *  @discussion This property knows salt.
 */
@property (nonatomic, strong) NSString *salt;

@property (nonatomic, strong) WalletStatusResDto *walletStatus;

/*!
 *  @discussion This method knows transform this class to response for DTO.
 *  @param response provide data web service response object.
 *  @return register wallet response data transfer object.
 */
+ (RegisterWalletResDto *)mapResponseToDTO:(id)response;
/*!
 *  @discussion This method knows transform this class to response for status.
 *  @param status provide data web service response object.
 *  @return register wallet response data transfer object.
 */
+ (RegisterWalletResDto *)mapStatusResToDTO:(id)status;

@end
