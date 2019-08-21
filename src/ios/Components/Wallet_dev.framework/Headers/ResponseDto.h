//
//  ResponseDto.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 4/11/18.
//  Copyright © 2018 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "StatusResDto.h"

@interface ResponseDto : NSObject

/*!
 *  @discussion This property knows status.
 */
@property (nonatomic, strong) StatusResDto *status;

/*!
 *  @discussion This method validate transaction code.
 *  @param wsTransactionCode provide data web service transaction code.
 *  @param localtTransactionCode provide data local transaction code.
 *  @return string transaction code.
 */
+ (NSString *)transactionCode:(NSString *)wsTransactionCode
         localTransactionCode:(NSString *)localtTransactionCode;

@end
