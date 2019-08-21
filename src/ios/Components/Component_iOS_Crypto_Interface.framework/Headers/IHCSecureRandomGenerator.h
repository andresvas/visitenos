/*
 Author:© 2017 Mastercard. Proprietary. All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 This protocol provide an interface for secure random generation.
 */
@protocol IHCSecureRandomGenerator <NSObject>

/**
 This method provides an interface to generate cryptographically secure random number.

 @param size Size of random number that needs to be generated.

 @return Random number in bytes.
 */
+ (NSData * _Nullable)generateSecureRandom:(NSNumber * _Nonnull)size;

@end
