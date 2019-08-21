/*
 Author:© 2017 Mastercard. Proprietary. All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 This protocol provides an interface to communicate with repository (For exmaple: DB), where wallet information is stored.
 */
@protocol IHCWalletRepository <NSObject>

/**
 This method provides an interface to create a wallet instance in repository.

 @param walletId             Unique id of wallet.
 @param walletStatus         Status of wallet.
 @param walletReferenceId    Unique reference id of wallet.
 @param paymentAppInstanceId Unique id of app instance.
 @param deviceReferenceId    Reference id of device
 */
- (void)createWalletWithWalletId:(NSString *)walletId
                    walletStatus:(NSString *)walletStatus
               walletReferenceId:(NSString *)walletReferenceId
            paymentAppInstanceId:(NSString *)paymentAppInstanceId
            andDeviceReferenceId:(NSString *)deviceReferenceId;

/**
 This method provides an interface to delete wallet's instance from repository.
 */
- (void)deleteWallet;

/**
 This method provides an interface to get walletId.

 @return Unique id of wallet.
 */
- (NSString *)getWalletId;

/**
 This method provides an interface to update walletId in repository.

 @param walletId Updated walletId.
 */
- (void)updateWalletId:(NSString *)walletId;

/**
 This method provides an interface to get walletStatus.

 @return Status of wallet.
 */
- (NSString *)getWalletStatus;

/**
 This method provides an interface to update walletStatus.

 @param walletStatus updated walletStatus.
 */
- (void)updateWalletStatus:(NSString *)walletStatus;

/**
 This method provids an interface to get walletReferenceId.

 @return Unique reference id of wallet.
 */
- (NSString *)getWalletReferenceId;

/**
 This method provides an interface to update walletReferenceId.

 @param walletReferenceId updated walletReferenceId.
 */
- (void)updateWalletReferenceId:(NSString *)walletReferenceId;

/**
 This method provides an interface to get paymentAppInstanceId.

 @return Unique id of app instance.
 */
- (NSString *)getPaymentAppInstanceId;

/**
 This method provides an interface to update paymentAppInstanceId.

 @param paymentAppInstanceId updated paymentAppInstanceId.
 */
- (void)updatePaymentAppInstanceId:(NSString *)paymentAppInstanceId;

/**
 This method provides an interface to get deviceReferenceId.

 @return Reference id of device.
 */
- (NSString *)getDeviceReferenceId;

/**
 This method provides an interface to update deviceReferenceId.

 @param deviceReferenceId Updated deviceReferenceId.
 */
- (void)updateDeviceReferenceId:(NSString *)deviceReferenceId;

@end
