//
//  UnhideCardReqDto.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 5/4/18.
//  Copyright © 2018 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UnhideCardReqDto : NSObject

/*!
 *  @discussion This property knows card id.
 */
@property (nonatomic, strong) NSString *cardId;

/*!
 *  @discussion This method knows transform this class to request for web service.
 *  @param dto provide unhide card request data transfer object.
 *  @return web service request object.
 */
+ (id)mapDTOToRequest:(UnhideCardReqDto *)dto;

@end
