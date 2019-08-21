/*
 Author:© 2017 Mastercard. Proprietary. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import "IHCWalletRepository.h"
#import "IHCWallet.h"

/**
 This protocolo provides an interface to execute wallet domain related operation.
 */
@protocol IHCWalletDomainService <NSObject>

/**
 This method provides an interface to initialize an object following to IHCWalletDomainService protocol.

 @param walletRepository An object following to IHCWalletRepository protocol.

 @return An object following to IHCWalletDomainService protocol.
 */
- (instancetype)initWithWalletRepository:(id <IHCWalletRepository>)walletRepository;

/**
 This method provides an interface to create a wallet localy in mobile application.

 @param walletId             Unique id of wallet.
 @param walletReferenceId    Unique reference id of wallet.
 @param deviceReferenceId    Reference id of device.
 @param paymentAppInstanceId Unique id of app instance.
 */
- (void)createWalletWithWalletId:(NSString *)walletId
               walletReferenceId:(NSString *)walletReferenceId
               deviceReferenceId:(NSString *)deviceReferenceId
         andPaymentAppInstanceId:(NSString *)paymentAppInstanceId;

/**
 This method provides an interface to get an object containing wallet info.

 @return An object following to IHCWallet protocol.
 */
- (id <IHCWallet>)getWallet;

/**
 This method provides an interface to clear wallet info from mobile application.
 */
- (void)clearWallet;

/**
 Thid method provides an interface to mark wallet as active.
 */
- (void)activateWallet;

/**
 This method provides an interface to mark wallet as inactive.
 */
- (void)inactivateWallet;

/**
 This method provides an interface to mark wallet as lock.
 */
- (void)lockWallet;

/**
 This method provides an interface to mark wallet as suspended.
 */
- (void)suspendWallet;

/**
 This method provides an interface to mark wallet as terminated.
 */
- (void)terminateWallet;

/**
 This method provides an interface to mark wallet as lost.
 */
- (void)markWalletAsLost;

/**
 This method provides an interface to check whether a wallet is active or not.

 @return A boolean value expressing whether wallet is active or not.
 */
- (BOOL)isWalletActive;

/**
 This method provides an interface to check whether a wallet is inactive or not.
 
 @return A boolean value expressing whether wallet is inactive or not.
 */
- (BOOL)isWalletInactive;

/**
 This method provides an interface to check whether a wallet is locked or not.
 
 @return A boolean value expressing whether wallet is locked or not.
 */
- (BOOL)isWalletLocked;

/**
 This method provides an interface to check whether a wallet is suspended or not.
 
 @return A boolean value expressing whether wallet is suspended or not.
 */
- (BOOL)isWalletSuspended;

/**
 This method provides an interface to check whether a wallet is terminated or not.
 
 @return A boolean value expressing whether wallet is terminated or not.
 */
- (BOOL)isWalletTerminated;

/**
 This method provides an interface to check whether a wallet is lost or not.
 
 @return A boolean value expressing whether wallet is lost or not.
 */
- (BOOL)isWalletLost;

@end
