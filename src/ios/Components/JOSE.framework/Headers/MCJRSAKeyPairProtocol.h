//
//  MCJRSAKeyPairProtocol.h
//  JOSE
//
//  Created by Malkan, Marmik on 5/9/17.
//  Copyright © 2017 MasterCard. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MCJKeyPairProtocol.h"

@protocol MCJRSAKeyPairProtocol <MCJKeyPairProtocol>

/**
 @abstract           This method is called to get the modulus component of RSA public key.
 @return             Returns the modulus of RSA public key in form of NSData object.
 */
- (NSData *)getModulus;  // n

/**
 @abstract           This method is called to generate the public key using cryptographic algorithm.
 @return             Returns the exponent of RSA public key in form of NSData object.
 */
- (NSData *)getExponent;  // e

/**
 @abstract           This method is called to generate the public key using cryptographic algorithm.
 @return             Returns the exponent of RSA public key in form of SecKeyRef type.
 */
- (SecKeyRef)getPublicKeyRef;

/**
 @abstract           This method is called to generate the public key using cryptographic algorithm.
 @return             Returns the exponent of RSA public key in form of SecKeyRef type.
 */
- (SecKeyRef)getPrivateKeyRef;


@end
