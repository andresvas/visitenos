//
//  StatusResDto.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 4/11/18.
//  Copyright © 2018 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface StatusResDto : NSObject

/*!
 *  @discussion This property knows code.
 */
@property (nullable, nonatomic, strong) NSString *code;
/*!
 *  @discussion This property knows transaction.
 */
@property (nullable, nonatomic, strong) NSString *transaction;
/*!
 *  @discussion This property knows message.
 */
@property (nullable, nonatomic, strong) NSString *message;

/*!
 *  @discussion This method knows transform this class to response for DTO.
 *  @param response provide data web service response object.
 *  @return status response data transfer object.
 */
+ (StatusResDto *)mapResponseToDTO:(id)response;

@end
