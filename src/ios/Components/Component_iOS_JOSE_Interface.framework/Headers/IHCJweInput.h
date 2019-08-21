/*
 Author:© 2017 Mastercard. Proprietary. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import "IHCJweAlgorithms.h"

/**
 Represents input required to produce a JSON Web Encryption (JWE).
 */
@protocol IHCJweInput <NSObject>

/**
 Data to be protected.
 */
@property (nonatomic, readwrite, nonnull) NSData *data;

/**
 Defines JWE aad.
 */
@property (nonatomic, readwrite, nullable) NSData *AAD;

/**
 Defines HCKeyEncryptionAlgorithm used.
 */
@property (nonatomic, readwrite) HCKeyEncryptionAlgorithm alg;

/**
 Defines HCContentEncryptionAlgorithm used.
 */
@property (nonatomic, readwrite) HCContentEncryptionAlgorithm enc;

@end
