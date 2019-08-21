/*
 Author:© 2017 Mastercard. Proprietary. All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 Represents JWE Content Encryption data
 */
@protocol IHCContentEncryptionParts <NSObject>

/**
 Initialization Vector
 */
@property (nonatomic, readwrite) NSData *iv;

/**
 Additional Authentication Data.
 */
@property (nonatomic, readwrite) NSData *aad;

/**
 Encrypted text.
 */
@property (nonatomic, readwrite) NSData *cipherText;

@end
