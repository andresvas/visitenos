/*
 Author:© 2017 Mastercard. Proprietary. All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 This protocol provide an interface for asymmetric key pair.
 */
@protocol IHCAsymmetricKeyPair <NSObject>

/**
 Public key of asymmetric key pair.
 */
@property (nonatomic, readonly, nonnull) SecKeyRef publicKey;

/**
 Private key of asymmetric key pair.
 */
@property (nonatomic, readonly, nonnull) SecKeyRef privateKey;

@end
