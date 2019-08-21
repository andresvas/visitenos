//
//  AcceptTnCResDto.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 4/11/18.
//  Copyright © 2018 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import "ResponseDto.h"

@interface AcceptTnCResDto : ResponseDto

/*!
 *  @discussion This method knows transform this class to response for DTO.
 *  @param response provide data web service response object.
 *  @return accept terms and conditions response data transfer object.
 */
+ (AcceptTnCResDto *)mapResponseToDTO:(id)response;
/*!
 *  @discussion This method knows transform this class to response for status.
 *  @param status provide data web service response object.
 *  @return accept terms and conditions response data transfer object.
 */
+ (AcceptTnCResDto *)mapStatusResToDTO:(id)status;

@end
