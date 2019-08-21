//
//  RegisterService.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 5/25/18.
//  Copyright © 2018 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RegisterWalletReqDto.h"
#import "RegisterWalletResDto.h"
#import "WalletRegisteredReqDto.h"
#import "WalletRegisteredResDto.h"
#import "FinishRegisterReqDto.h"
#import "FinishRegisterResDto.h"

@interface RegisterService : NSObject

/*!
 *  @discussion This method knows is constructor for this class.
 */
+ (instancetype)sharedInstance;

/*!
 *  @discussion This method knows register wallet.
 *  @param registerWallet provide data for register wallet.
 *  @param success provide data for wallet registered.
 *  @param failure provide status data with error information.
 */
- (void)registerWallet:(RegisterWalletReqDto *)registerWallet
             onSuccess:(void (^)(RegisterWalletResDto *registerWalletRes))success
             onFailure:(void (^)(RegisterWalletResDto *registerWalletRes))failure;

/*!
 *  @discussion This method knows validate if wallet is registered.
 *  @param walletRegistered provide data for wallet registered.
 *  @param success provide data for wallet registered.
 *  @param failure provide status data with error information.
 */
- (void)walletRegistered:(WalletRegisteredReqDto *)walletRegistered
               onSuccess:(void (^)(WalletRegisteredResDto *walletRegisteredRes))success
               onFailure:(void (^)(WalletRegisteredResDto *walletRegisteredRes))failure;

/*!
 *  @discussion This method knows validate if finish register.
 *  @param finishRegister provide data for finish register.
 *  @param success provide data for finish register.
 *  @param failure provide status data with error information.
 */
- (void)finishRegister:(FinishRegisterReqDto *)finishRegister
             onSuccess:(void (^)(FinishRegisterResDto *finishRegisterRes))success
             onFailure:(void (^)(FinishRegisterResDto *finishRegisterRes))failure;

@end
