//
//  RegisterWalletReqDto.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 4/11/18.
//  Copyright © 2018 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RegisterWalletReqDto : NSObject

/*!
 *  @discussion This property knows user information.
 */
@property (nonatomic, strong) NSString *userInfo;

/*!
 *  @discussion This method knows transform this class to request for web service.
 *  @param dto provide register wallet request data transfer object.
 *  @return web service request object.
 */
+ (id)mapDTOToRequest:(RegisterWalletReqDto *)dto;

@end
