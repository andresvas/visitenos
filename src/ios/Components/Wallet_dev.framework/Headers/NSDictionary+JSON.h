//
//  NSDictionary+JSON.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 2/27/18.
//  Copyright © 2018 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDictionary (JSON)

/*!
 *  @discussion This method get object for key from json object.
 *  @param aKey provide data for key.
 *  @return object or nil
 */
- (nullable id)objectOrNilForKey:(nonnull id)aKey;

@end
