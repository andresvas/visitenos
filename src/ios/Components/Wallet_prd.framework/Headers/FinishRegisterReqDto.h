//
//  FinishRegisterReqDto.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 3/19/19.
//  Copyright © 2019 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FinishRegisterReqDto : NSObject

/*!
 *  @discussion This property knows user information.
 */
@property (nonatomic, strong) NSString *userInfo;

/*!
 *  @discussion This method knows transform this class to request for web service.
 *  @param dto provide wallet register request data transfer object.
 *  @return web service request object.
 */
+ (id)mapDTOToRequest:(FinishRegisterReqDto *)dto;

@end

NS_ASSUME_NONNULL_END
