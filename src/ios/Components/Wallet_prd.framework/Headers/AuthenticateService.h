//
//  AuthenticateService.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 5/23/18.
//  Copyright © 2018 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AuthenticateReqDto.h"
#import "AuthenticateResDto.h"

@interface AuthenticateService : NSObject

/*!
 *  @discussion This method knows is constructor for this class.
 */
+ (instancetype)sharedInstance;

/*!
 *  @discussion This method knows authenticate in wallet.
 *  @param authenticate provide data for authentication information.
 *  @param success provide data for authenticate.
 *  @param failure provide status data with error information.
 */
- (void)authenticate:(AuthenticateReqDto *)authenticate
           onSuccess:(void (^)(AuthenticateResDto *authRes))success
           onFailure:(void (^)(AuthenticateResDto *authRes))failure;

/*!
 *  @discussion This method clean data saved for authentication in wallet.
 */
- (void)logout;

@end
