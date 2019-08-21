//
//  RuncheckService.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 5/30/18.
//  Copyright © 2018 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RuncheckResDto.h"

@interface RuncheckService : NSObject

/*!
 *  @discussion This method knows is constructor for this class.
 */
+ (instancetype)sharedInstance;

/*!
 *  @discussion This method get data of runcheck information.
 *  @return Runcheck object.
 */
- (RuncheckResDto *)getRuncheck;

@end
