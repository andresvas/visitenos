//
//  CardListUserInfoResDto.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 6/12/18.
//  Copyright © 2018 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CardListUserInfoResDto : NSObject

/*!
 *  @discussion This property knows was user name.
 */
@property (nonatomic, strong) NSString *userName;

/*!
 *  @discussion This method knows transform this class to response for DTO.
 *  @param response provide data web service response object.
 *  @return card list user information response data transfer object.
 */
+ (CardListUserInfoResDto *)mapResponseToDTO:(id)response;

@end
