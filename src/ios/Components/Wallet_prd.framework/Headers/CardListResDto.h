//
//  CardListResDto.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 4/12/18.
//  Copyright © 2018 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import "ResponseDto.h"
#import "CardListInfoResDto.h"
#import "CardListUserInfoResDto.h"

@interface CardListResDto : ResponseDto

/*!
 *  @discussion This property knows cards information.
 */
@property (nonatomic, strong) CardListInfoResDto *cardsInfo;
/*!
 *  @discussion This property knows user information.
 */
@property (nonatomic, strong) CardListUserInfoResDto *userInfo;

/*!
 *  @discussion This method knows transform this class to response for DTO.
 *  @param response provide data web service response object.
 *  @return card list response data transfer object.
 */
+ (CardListResDto *)mapResponseToDTO:(id)response;
/*!
 *  @discussion This method knows transform this class to response for status.
 *  @param status provide data web service response object.
 *  @return card list response data transfer object.
 */
+ (CardListResDto *)mapStatusResToDTO:(id)status;

@end
