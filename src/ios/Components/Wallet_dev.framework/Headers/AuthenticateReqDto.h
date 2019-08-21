//
//  AuthenticateReqDto.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 4/12/18.
//  Copyright © 2018 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AuthenticateReqDto : NSObject

/*!
 *  @discussion This property knows user information.
 */
@property (nonatomic, strong) NSString *userInfo;
/*!
 *  @discussion This property knows authorization code.
 */
@property (nonatomic, strong) NSString *authorizationCode;

/*!
 *  @discussion This method knows transform this class to request for web service.
 *  @param dto provide authenticate request data transfer object.
 *  @return web service request object.
 */
+ (id)mapDTOToRequest:(AuthenticateReqDto *)dto;

@end
