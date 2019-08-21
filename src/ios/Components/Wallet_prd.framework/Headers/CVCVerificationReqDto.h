//
//  CVCVerificationReqDto.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 3/19/19.
//  Copyright © 2019 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CVCVerificationReqDto : NSObject

/*!
 *  @discussion This property knows user information.
 */
@property (nonatomic, strong) NSString *userInfo;
/*!
 *  @discussion This property knows card id.
 */
@property (nonatomic, strong) NSString *cardId;
/*!
 *  @discussion This property knows card security code.
 */
@property (nonatomic, strong) NSString *cvc;

/*!
 *  @discussion This method knows transform this class to request for web service.
 *  @param dto provide card security code request data transfer object.
 *  @return web service request object.
 */
+ (id)mapDTOToRequest:(CVCVerificationReqDto *)dto;

@end

NS_ASSUME_NONNULL_END
