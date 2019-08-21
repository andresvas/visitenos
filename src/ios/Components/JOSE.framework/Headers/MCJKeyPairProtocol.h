//
//  MCJKeyPairProtocol.h
//  JOSE
//
//  Created by Malkan, Marmik on 5/9/17.
//  Copyright © 2017 MasterCard. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 This protocol contains an abstract methods to get public key and private key.
 */
@protocol MCJKeyPairProtocol <NSObject>

/**
 @abstract           This method is called to get the private key using the cryptographic algorithm.
 @return             Returns the private key in form of NSData object.
 */
- (NSData *)getPrivateKey;

/**
 @abstract           This method is called to get the public key using cryptographic algorithm.
 @return             Returns the public key in form of NSData object.
 */
- (NSData *)getPublicKey;

@end
