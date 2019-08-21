/*
 Author:© 2017 Mastercard. Proprietary. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import "IHCAsymmetricKeyPair.h"

/**
 This protocol provide an interface for asymmetric key pair generation.
 */
@protocol IHCAsymmetricKeyGenerator <NSObject>

/**
 This method provides an interface to generate asymmetric key pair.

 @param keySize Size of keys to be generated.

 @return Object of asymmetric key pair, following <IHCAsymmetricKeyPair> protocol.
 */
+ (id <IHCAsymmetricKeyPair> _Nonnull)generateKeyPair:(int)keySize;

@end
