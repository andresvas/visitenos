//
//  IBindObject.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 2/27/18.
//  Copyright © 2018 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NSDictionary+JSON.h"

@protocol IBindObject <NSObject>

/*!
 *  @discussion This method knows is constructor of any class that implements.
 *  @param dictionary provide data json response.
 */
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end
