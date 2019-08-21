//
//  NSData+Hex.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 3/5/18.
//  Copyright © 2018 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSData (Hex)

/*!
 *  @discussion This method get string hex.
 *  @return string hex.
 */
- (NSString *)hexString;

/*!
 *  @discussion This method get data from base 64 string.
 *  @param aString provide base 64 string.
 *  @return NSData of bsase 64 string.
 */
+ (NSData *)dataFromBase64String:(NSString *)aString;

@end
