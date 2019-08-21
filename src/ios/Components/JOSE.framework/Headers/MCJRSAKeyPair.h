//
//  MCJRSAKeyPair.h
//  JOSE
//
//  Created by Malkan, Marmik on 5/9/17.
//  Copyright © 2017 MasterCard. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MCJRSAKeyPairProtocol.h"

@interface MCJRSAKeyPair : NSObject<MCJRSAKeyPairProtocol>

- (instancetype)initWithPrivateKey:(NSData *)privateKey
                         publicKey:(NSData *)publicKey
                           modulus:(NSData *)modulus
                          exponent:(NSData *)exponent
                      publicKeyRef:(SecKeyRef)publicKeyRef
                     privateKeyRef:(SecKeyRef)privateKeyRef;

@end
