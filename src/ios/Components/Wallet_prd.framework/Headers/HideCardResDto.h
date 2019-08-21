//
//  HideCardResDto.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 5/4/18.
//  Copyright © 2018 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import "ResponseDto.h"

@interface HideCardResDto : ResponseDto

/*!
 *  @discussion This method knows transform this class to response for DTO.
 *  @param response provide data web service response object.
 *  @return hide card response data transfer object.
 */
+ (HideCardResDto *)mapResponseToDTO:(id)response;
/*!
 *  @discussion This method knows transform this class to response for status.
 *  @param status provide data web service response object.
 *  @return hide card response data transfer object.
 */
+ (HideCardResDto *)mapStatusResToDTO:(id)status;

@end
