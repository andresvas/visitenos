//
//  CardListInfoResDto.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 6/12/18.
//  Copyright © 2018 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CardResDto.h"

@interface CardListInfoResDto : NSObject

/*!
 *  @discussion This property knows was card basic information.
 */
@property (nonatomic, strong) NSArray<CardResDto *> *cardBasicInfo;

/*!
 *  @discussion This method knows transform this class to response for DTO.
 *  @param response provide data web service response object.
 *  @return card list information response data transfer object.
 */
+ (CardListInfoResDto *)mapResponseToDTO:(id)response;

@end
