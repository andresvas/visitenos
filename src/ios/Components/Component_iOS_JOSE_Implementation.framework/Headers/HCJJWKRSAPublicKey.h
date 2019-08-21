//
//  HCJJWKRSAPublicKey.h
//  Component_iOS_JOSE_Implementation
//
//  Created by Shah, Chetan on 4/18/17.
//  Copyright © 2017 Malkan, Marmik. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Contains RSA related JWK public key.
 */

@interface HCJJWKRSAPublicKey : NSObject

/**
 The modulus value for the RSA key.
 */
@property (nonatomic, strong) NSString *n;

/**
 The public exponent of the RSA key.
 */
@property (nonatomic, strong) NSString *e;

-(instancetype)initWithNComponent:(NSString*)n eComponent:(NSString*)e;

@end
