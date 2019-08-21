/*
 Author:© 2017 Mastercard. Proprietary. All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 This protocol provide an interface for public key cryptography.
 */
@protocol IHCAsymmetricCipher <NSObject>

/**
 This method provides an interface to encrypt data using public key.

 @param plainTextData Data to be encrypted.
 @param publicKey     Public key to be used for encryption.
 @param padding       Padding to be used during encryption.

 @return Encrypted data.
 */
+ (NSData * _Nullable)encrypt:(NSData * _Nonnull)plainTextData
               usingPublicKey:(SecKeyRef _Nonnull)publicKey
                      padding:(SecPadding)padding;

/**
 This method provides an interface to decrypt data using private key.

 @param cipherTextData Data to be decrypted.
 @param privateKey     Private key to be used for decryption.
 @param padding        Padding used during encryption.

 @return Decrypted data.
 */
+ (NSData * _Nullable)decrypt:(NSData * _Nonnull)cipherTextData
              usingPrivateKey:(SecKeyRef _Nonnull)privateKey
                      padding:(SecPadding)padding;

@end
