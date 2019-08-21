/*
 Author:© 2017 Mastercard. Proprietary. All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 This protocol provide an interface for symmetric key.
 */
@protocol IHCSymmetricKey <NSObject>

/**
 Symmetric key in bytes.
 */
@property (nonatomic, readonly, nonnull) NSData *data;

/**
 Length of symmetric key.
 */
@property (nonatomic, readonly) NSUInteger size;

@end
