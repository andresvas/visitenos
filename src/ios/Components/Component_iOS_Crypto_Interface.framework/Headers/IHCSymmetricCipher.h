/*
 Author:© 2017 Mastercard. Proprietary. All rights reserved.
 */

#import <Foundation/Foundation.h>

/*!
 @enum       HCCryptoOptions
 @abstract   Options flags, passed to CCCryptorCreate().
 
 @constant   kHCCryptoOptionPKCS7Padding   Perform PKCS7 padding.
 @constant   kHCCryptoOptionECBMode        Electronic Code Book Mode.
 Default is CBC.
 */

/**
 Options flags, passed to HCCryptoOptions(), during encryption/decryption. Below are the options for Block chiher and default is CBC.
 NOTE: Stream ciphers currently have no options.

 - kHCCryptoOptionPKCS7Padding: Perform PKCS7 padding.
 - kHCCryptoOptionECBMode:      Electronic Code Book Mode.
 */
typedef NS_ENUM(uint32_t, HCCryptoOptions)
{
    kHCCryptoOptionPKCS7Padding   = 0x0001,
    kHCCryptoOptionECBMode        = 0x0002
};

/**
 This protocol provide an interface for symmetric key cryptography.
 */
@protocol IHCSymmetricCipher <NSObject>

/**
 This method provides an interface to encrypt data using key.

 @param plainTextData        Data to be encrypted.
 @param key                  Key to be used for encryption.
 @param initializationVector Initialization vector
 @param padding              Padding to be applied.

 @return Chiper data generated after encryption.
 */
+ (NSData * _Nullable)encrypt:(NSData * _Nonnull)plainTextData
                     usingKey:(NSData * _Nonnull)key
                           iv:(NSData * _Nullable)initializationVector
                   andPadding:(HCCryptoOptions * _Nonnull)padding;

/**
 This method provides an interface to decrypt data using key.

 @param cipherTextData       Data to be decrypted.
 @param key                  Key to be used for decryption.
 @param initializationVector Initialization vector.
 @param padding              Padding applied during encryption.

 @return Decrypted data.
 */
+ (NSData * _Nullable)decrypt:(NSData * _Nonnull)cipherTextData
                     usingKey:(NSData * _Nonnull)key
                           iv:(NSData * _Nullable)initializationVector
                   andPadding:(HCCryptoOptions * _Nonnull)padding;

@end
