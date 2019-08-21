//
//  AuthenticateResDto.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 4/12/18.
//  Copyright © 2018 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import "ResponseDto.h"

@interface AuthenticateResDto : ResponseDto

/*!
 *  @discussion This method knows transform this class to response for DTO.
 *  @param response provide data web service response object.
 *  @return authenticate response data transfer object.
 */
+ (AuthenticateResDto *)mapResponseToDTO:(id)response;

@end
