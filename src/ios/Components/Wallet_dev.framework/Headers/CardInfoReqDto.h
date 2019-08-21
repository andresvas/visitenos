//
//  CardInfoReqDto.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 2/27/18.
//  Copyright © 2018 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CardInfoReqDto : NSObject

/*!
 *  @discussion This property knows card id.
 */
@property (nonatomic, strong) NSString *cardId;
/*!
 *  @discussion This property knows card type.
 */
@property (nonatomic, strong) NSString *cardType;

/*!
 *  @discussion This method knows create copy for this class with parameters:
 *  @param zone provide card information request data transfer object.
 *  @return class copy of this object.
 */
- (id)copyWithZone:(nullable NSZone *)zone;

@end
