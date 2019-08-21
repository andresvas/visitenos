//
//  TnCService.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 5/29/18.
//  Copyright © 2018 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TnCResDto.h"
#import "AcceptTnCReqDto.h"
#import "AcceptTnCResDto.h"

@interface TnCService : NSObject

/*!
 *  @discussion This method knows is constructor for this class.
 */
+ (instancetype)sharedInstance;

/*!
 *  @discussion This method knows get terms and conditions.
 *  @param success provide data for terms and conditions.
 *  @param failure provide status data with error information.
 */
- (void)tnCOnSuccess:(void (^)(TnCResDto *tnCRes))success
           onFailure:(void (^)(TnCResDto *tnCRes))failure;

/*!
 *  @discussion This method knows accept terms and conditions.
 *  @param acceptTnC provide data for send accept terms and conditions.
 *  @param success provide data for accepted terms and conditions.
 *  @param failure provide status data with error information.
 */
- (void)acceptTnC:(AcceptTnCReqDto *)acceptTnC
        onSuccess:(void (^)(AcceptTnCResDto *acceptTnCRes))success
        onFailure:(void (^)(AcceptTnCResDto *acceptTnCRes))failure;

@end
