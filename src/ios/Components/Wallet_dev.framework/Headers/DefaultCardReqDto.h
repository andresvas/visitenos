//
//  DefaultCardReqDto.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 6/21/18.
//  Copyright © 2018 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DefaultCardReqDto : NSObject

/*!
 *  @discussion This property knows payment card id.
 */
@property (nonatomic, strong) NSString *paymentCardId;
/*!
 *  @discussion This property knows default card.
 */
@property (nonatomic, strong) NSString *setDefault;

/*!
 *  @discussion This method knows transform this class to request for web service.
 *  @param dto provide default card request data transfer object.
 *  @return web service request object.
 */
+ (id)mapDTOToRequest:(DefaultCardReqDto *)dto;

@end
