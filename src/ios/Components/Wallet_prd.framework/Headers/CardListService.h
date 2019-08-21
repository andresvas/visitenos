//
//  CardListService.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 5/30/18.
//  Copyright © 2018 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CardListReqDto.h"
#import "CardListResDto.h"
#import "DefaultCardReqDto.h"
#import "DefaultCardResDto.h"
#import "HideCardReqDto.h"
#import "HideCardResDto.h"
#import "UnhideCardReqDto.h"
#import "UnhideCardResDto.h"
#import "CVCVerificationReqDto.h"
#import "CVCVerificationResDto.h"

@interface CardListService : NSObject

/*!
 *  @discussion This method knows is constructor for this class.
 */
+ (instancetype)sharedInstance;

/*!
 *  @discussion This method knows get card list.
 *  @param cardList provide data for get card list.
 *  @param success provide data for card list.
 *  @param failure provide status data with error information.
 */
- (void)cardList:(CardListReqDto *)cardList
       onSuccess:(void (^)(CardListResDto *cardListRes))success
       onFailure:(void (^)(CardListResDto *cardListRes))failure;

/*!
 *  @discussion This method change state of card to default.
 *  @param defaultCard provide data for set default card.
 *  @param success provide data for default card.
 *  @param failure provide status data with error information.
 */
- (void)defaultCard:(DefaultCardReqDto *)defaultCard
          onSuccess:(void (^)(DefaultCardResDto *defaultCardRes))success
          onFailure:(void (^)(DefaultCardResDto *defaultCardRes))failure;

/*!
 *  @discussion This method change state of card to hide.
 *  @param hideCard provide data for set hide card.
 *  @param success provide data for hide card.
 *  @param failure provide status data with error information.
 */
- (void)hideCard:(HideCardReqDto *)hideCard
       onSuccess:(void (^)(HideCardResDto *hideCardRes))success
       onFailure:(void (^)(HideCardResDto *hideCardRes))failure;

/*!
 *  @discussion This method change state of card unhide.
 *  @param unhideCard provide data for set unhide card.
 *  @param success provide data for unhide card.
 *  @param failure provide status data with error information.
 */
- (void)unhideCard:(UnhideCardReqDto *)unhideCard
         onSuccess:(void (^)(UnhideCardResDto *unhideCardRes))success
         onFailure:(void (^)(UnhideCardResDto *unhideCardRes))failure;

/*!
 *  @discussion This method verify if card security code is valid.
 *  @param cvcVerification provide data for card security code.
 *  @param success provide data for card security code.
 *  @param failure provide status data with error information.
 */
- (void)cvcVerification:(CVCVerificationReqDto *)cvcVerification
              onSuccess:(void (^)(CVCVerificationResDto *cvcVerificationRes))success
              onFailure:(void (^)(CVCVerificationResDto *cvcVerificationRes))failure;

@end
