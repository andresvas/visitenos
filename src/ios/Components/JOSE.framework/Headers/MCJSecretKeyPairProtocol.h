//
//  MCJSecretKeyPairProtocol.h
//  JOSE
//
//  Created by Malkan, Marmik on 5/9/17.
//  Copyright © 2017 MasterCard. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MCJKeyPairProtocol.h"

@protocol MCJSecretKeyPairProtocol <MCJKeyPairProtocol>

/**
 @abstract            This is the X component of the EC public key in decimal format.
 @return              Returns the X component of the EC public key in decimal format in form of NSData object.
 */
- (NSData *)getXcomponent;

/**
 @abstract            The Y component of the EC public key in decimal format.
 @return              Returns the Y component of the EC public key in decimal format in form of NSData object.
 */
- (NSData *)getYcomponent;

/**
 @abstract            This is the binary representation of X component (Two's complement) of the EC public key in decimal format.
 @return              Returns the X component of the EC public key in binary format in form of NSData object.
 */
- (NSData *)getBinaryXcomponent;

/**
 @abstract            This is the binary representation of Y component (Two's complement) of the EC public key in decimal format.
 @return              Returns the Y component of the EC public key in binary format in form of NSData object.
 */
- (NSData *)getBinaryYcomponent;


@end
