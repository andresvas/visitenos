/*
 Author:© 2017 Mastercard. Proprietary. All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 This protocol provide an interface for HMAC generation.
 */
@protocol IHCHMACGenerator <NSObject>

/**
 This method provides a interface to generate hashed message authentication code (HMAC) of size 20.

 @param data Input data to be used for generating HMAC.
 @param key  Key to be used for generating HMAC.

 @return HMAC with 20 byte length.
 */
+ (NSData * _Nullable)generateSHA1HMACForData:(NSData * _Nonnull)data
                                     usingKey:(NSData * _Nonnull)key;

/**
 This method provides a interface to generate hashed message authentication code (HMAC) of size 32.
 
 @param data Input data to be used for generating HMAC.
 @param key  Key to be used for generating HMAC.
 
 @return HMAC with 32 byte length.
 */
+ (NSData * _Nullable)generateSHA256HMACForData:(NSData * _Nonnull)data
                                       usingKey:(NSData * _Nonnull)key;

@end
