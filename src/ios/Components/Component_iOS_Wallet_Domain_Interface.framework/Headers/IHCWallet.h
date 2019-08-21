/*
 Author:© 2017 Mastercard. Proprietary. All rights reserved.
 */

#import <Foundation/Foundation.h>

static NSString *kHCWalletStatusInactive    =  @"INACTIVE";
static NSString *kHCWalletStatusActive      =  @"ACTIVE";
static NSString *kHCWalletStatusLocked      =  @"LOCKED";
static NSString *kHCWalletStatusSuspended   =  @"SUSPENDED";
static NSString *kHCWalletStatusTerminated  =  @"TERMINATED";
static NSString *kHCWalletStatusLost        =  @"LOST";

/**
 This protocol provides an interface to define properties a wallet.
 */
@protocol IHCWallet <NSObject>

/**
 This property provides an interface to define an unique id of wallet.
 */
@property (nonatomic, readonly) NSString *walletId;

/**
 This property provides an interface to define status of wallet.
 */
@property (nonatomic, readonly) NSString *walletStatus;

/**
 This property provides an interface to define an unique reference id of wallet.
 */
@property (nonatomic, readonly) NSString *walletReferenceId;

/**
 This property provides an interface to define reference id of device.
 */
@property (nonatomic, readonly) NSString *deviceReferenceId;

/**
 This property provides an interface to define an unique id of app instance.
 */
@property (nonatomic, readonly) NSString *paymentAppInstanceId;

@end
