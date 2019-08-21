//
//  WalletUtility.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 10/4/18.
//  Copyright © 2018 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WalletUtility : NSObject

/*!
 *  @discussion This method get current version of wallet.
 *  @return string current version of wallet.
 */
+ (NSString *)getCurrentVersion;
/*!
 *  @discussion This method get build version of wallet.
 *  @return string build version of wallet.
 */
+ (NSString *)getCurrentBuildVersion;
/*!
 *  @discussion This method get current SDK wallet environment.
 *  @return string current SDK wallet environment.
 */
+ (NSString *)getCurrentSDKWalletEnvironment;

@end

NS_ASSUME_NONNULL_END
