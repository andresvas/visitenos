//
//  MCJSecretKeyPair.h
//  JOSE
//
//  Created by Malkan, Marmik on 5/9/17.
//  Copyright © 2017 MasterCard. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MCJSecretKeyPairProtocol.h"

@interface MCJSecretKeyPair : NSObject<MCJSecretKeyPairProtocol>

- (instancetype)initWithPrivateKey:(NSData *)privateKey
                         publicKey:(NSData *)publicKey
                        xComponent:(NSData *)xComp
                        yComponent:(NSData *)yComp
                       xBComponent:(NSData *)xBComp
                       yBComponent:(NSData *)yBComp;

@end
