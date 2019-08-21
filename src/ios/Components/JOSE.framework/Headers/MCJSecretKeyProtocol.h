//
//  MCJSecretKeyProtocol.h
//  JOSE
//
//  Created by Malkan, Marmik on 5/9/17.
//  Copyright © 2017 MasterCard. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 SecretKey is a protocol for symmetric key provider.
 */
@protocol MCJSecretKeyProtocol <NSObject>

/**
 @abstract   The secret key generated using cryptographic algorithm.
 @return    NSData   The secret key in bytes.
 */
- (NSData *)key;

/**
 @abstract   The size of the secret key generated using cryptographic algorithm.
 @return    Integer   The secret key length.
 */
- (int)keySize;

@end
