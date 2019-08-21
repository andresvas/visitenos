/*
 Author:© 2017 Mastercard. Proprietary. All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 This protocol provide an interface for symmetric key wrapping/unwrapping.
 */
@protocol IHCSymmetricKeyWrapper <NSObject>

/**
 This method provides an interface to wrap symmetric key using Key-Encryption-Key(KEK).
 The algorithm chosen is determined by the algorithm parameter and the size of the key being wrapped. It returns nil if an error occurs. Error may result from bad values for KeK and rawKey.
 Currently only AES Keywrapping (rfc3394) is available via kCCWRAPAES. Described in <CommonCrypto/CommonSymmetricKeywrap.h>.
 
 @param key                  Key bytes to be wrapped.
 @param keyEncryptionKey     Key-Encryption-Key to be used to wrap the key.
 @param initializationVector Initialization value to be used.
 
 @return Wrapped key.
 */
+ (NSData * _Nullable)wrapKey:(NSData * _Nonnull)key
                     usingKEK:(NSData * _Nonnull)keyEncryptionKey
                        andIV:(NSData * _Nullable)initializationVector;


/**
 This method provides an interface to unwrap a symmetric key using Key-Encryption-Key(KEK)..
 The algorithm chosen is determined by the algorithm parameter and the size of the key being unwrapped. It returns nil if an error occurs. Error may result from bad values for KeK and wrappedKey.
 Currently only AES Keywrapping (rfc3394) is available via kCCWRAPAES. Described in <CommonCrypto/CommonSymmetricKeywrap.h>.
 
 @param wrappedKey           Wrapped key.
 @param keyEncryptionKey     Key-Encryption-Key to be used to unwrap the raw key.
 @param initializationVector Initialization value to be used.
 
 @return Unwrapped key.
 */
+ (NSData * _Nullable)unwrapKey:(NSData * _Nonnull)wrappedKey
                       usingKEK:(NSData * _Nonnull)keyEncryptionKey
                          andIV:(NSData * _Nullable)initializationVector;

@end
