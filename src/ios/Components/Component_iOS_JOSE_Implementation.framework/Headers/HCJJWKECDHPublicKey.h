//
//  HCJJWKECDHPublicKey.h
//  Component_iOS_JOSE_Implementation
//
//  Created by Shah, Harshit on 5/25/17.
//  Copyright © 2017 Malkan, Marmik. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <JOSE/MCJJWKECDHPublicKey.h>
#import <JOSE/MCJJWKServerPublicKey.h>

@interface HCJJWKECDHPublicKey : NSObject
@property (nonatomic, strong) MCJJWKECDHPublicKey *ecdhPublicKey;
@property (nonatomic,strong) MCJJWKServerPublicKey *serverPublicKey;
@property (nonatomic, strong) NSData *pubKeyData;
-(instancetype)initWithPublicKeyData:(NSData*)publicKeyData;
-(instancetype)initWithECDHPublicKey:(MCJJWKECDHPublicKey*)ecdhPublicKey;
-(instancetype)initWithServerPublicKey:(MCJJWKServerPublicKey*)serverPublicKey;
@end


