//
//  DefaultCardResDto.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 6/21/18.
//  Copyright © 2018 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import "ResponseDto.h"

@interface DefaultCardResDto : ResponseDto

/*!
 *  @discussion This method knows transform this class to response for DTO.
 *  @param response provide data web service response object.
 *  @return default card response data transfer object.
 */
+ (DefaultCardResDto *)mapResponseToDTO:(id)response;
/*!
 *  @discussion This method knows transform this class to response for status.
 *  @param status provide data web service response object.
 *  @return default card response data transfer object.
 */
+ (DefaultCardResDto *)mapStatusResToDTO:(id)status;

@end
