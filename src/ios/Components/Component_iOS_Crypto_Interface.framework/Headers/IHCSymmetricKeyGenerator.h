/*
 Author:© 2017 Mastercard. Proprietary. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import "IHCSymmetricKey.h"

/**
 This protocol provide an interface for symmetric key generation.
 */
@protocol IHCSymmetricKeyGenerator <NSObject>

/**
 Generates cryptographically secure key with specified size.

 @param keySize Size of the key to be generated.

 @return An object confirming to <IHCSymmetricKey> protocol
 */
+ (id <IHCSymmetricKey> _Nonnull)generateKey:(NSUInteger)keySize;

@end
