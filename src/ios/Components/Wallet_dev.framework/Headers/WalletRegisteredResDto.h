//
//  WalletRegisteredResDto.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 4/12/18.
//  Copyright © 2018 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import "ResponseDto.h"
#import "WalletStatusResDto.h"

@interface WalletRegisteredResDto : ResponseDto

/*!
 *  @discussion This property knows show terms and conditions.
 */
@property (nonatomic) BOOL showTnC;
/*!
 *  @discussion This property knows wallet status.
 */
@property (nonatomic, strong) WalletStatusResDto *walletStatus;

/*!
 *  @discussion This method knows transform this class to response for DTO.
 *  @param response provide data web service response object.
 *  @return wallet registered response data transfer object.
 */
+ (WalletRegisteredResDto *)mapResponseToDTO:(id)response;
/*!
 *  @discussion This method knows transform this class to response for status.
 *  @param status provide data web service response object.
 *  @return wallet registered response data transfer object.
 */
+ (WalletRegisteredResDto *)mapStatusResToDTO:(id)status;

@end
