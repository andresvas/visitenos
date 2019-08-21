/*
 Author:© 2017 Mastercard. Proprietary. All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 This protocol provide an interface for hash (message digest) generation.
 */
@protocol IHCMessageDigestGenerator <NSObject>

/**
 This method provides an interface to generate hash of size 20 using secure hashing algorithm - SHA1.

 @param input Input on which SHA1 is to be applied.

 @return Hash value of  20 byte length.
 */
+ (NSData * _Nullable)generateMessageDigestUsingSHA1:(NSData * _Nonnull)input;

/**
 This method provides an interface to generate hash of size 32 using secure hashing algorithm - SHA256.

 @param input Input on which SHA256 is to be applied.

 @return Hash value of 32 byte length.
 */
+ (NSData * _Nullable)generateMessageDigestUsingSHA256:(NSData * _Nonnull)input;

@end
