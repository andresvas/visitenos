/*
 Author:© 2017 Mastercard. Proprietary. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <Component_iOS_Wallet_Domain_Interface/IHCWallet.h>

/**
 This class provides an implementation for IHCWallet protocol.
 */
@interface HCWallet : NSObject <IHCWallet>

/**
 This method provides an interface to intialize an object of HCWallet.

 @param walletId             Unique id of wallet.
 @param walletStatus         Status of wallet.
 @param walletReferenceId    Unique reference id of wallet.
 @param paymentAppInstanceId Unique id of app instance.
 @param deviceReferenceId    Reference id of device.

 @return Instance of HCWallet.
 */
- (instancetype)initWithWalletId:(NSString *)walletId
                    walletStatus:(NSString *)walletStatus
               walletReferenceId:(NSString *)walletReferenceId
            paymentAppInstanceId:(NSString *)paymentAppInstanceId
            andDeviceReferenceId:(NSString *)deviceReferenceId;

@end
