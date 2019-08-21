//
//  CardListReqDto.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 4/12/18.
//  Copyright © 2018 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CardListReqDto : NSObject

/*!
 *  @discussion This property knows user information.
 */
@property (nonatomic, strong) NSString *userInfo;

/*!
 *  @discussion This method knows transform this class to request for web service.
 *  @param dto provide card list request data transfer object.
 *  @return web service request object.
 */
+ (id)mapDTOToRequest:(CardListReqDto *)dto;

@end
