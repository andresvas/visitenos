//
//  CVCVerificationResDto.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 3/19/19.
//  Copyright © 2019 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import "ResponseDto.h"

NS_ASSUME_NONNULL_BEGIN

@interface CVCVerificationResDto : ResponseDto

/*!
 *  @discussion This method knows transform this class to response for DTO.
 *  @param response provide data web service response object.
 *  @return card security code response data transfer object.
 */
+ (CVCVerificationResDto *)mapResponseToDTO:(id)response;
/*!
 *  @discussion This method knows transform this class to response for status.
 *  @param status provide data web service response object.
 *  @return card security code response data transfer object.
 */
+ (CVCVerificationResDto *)mapStatusResToDTO:(id)status;

@end

NS_ASSUME_NONNULL_END
