//
//  HCJweRSAOrchestrator.h
//  Component_iOS_JOSE_Implementation
//
//  Created by Shah, Chetan on 4/26/17.
//  Copyright © 2017 Malkan, Marmik. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HCJJWKRSAPublicKey.h"
#import "HCJweOrchestrator.h"
#import <Component_iOS_JOSE_Interface/Component_iOS_JOSE_Interface.h>

@interface HCJweRSAOrchestrator : HCJweOrchestrator

@property (nonatomic,strong) HCJJWKRSAPublicKey *rsaPublicKeyProvider;

/**
 Initializes HCJweRSAOrchestrator.
 
 @param rsaPublicKey Implementation of HCJJWKRSAPublicKey.
 @param keyAlgorithm Key encryption algorithm from HCKeyEncryptionAlgorithm enum.
 @param contentAlgorithm Content encryption algorithm from HCContentEncryptionAlgorithm enum.
 
 */

-(instancetype)initWithRSAKey: (HCJJWKRSAPublicKey*) rsaPublicKey
       keyEncryptionAlgorithm: (HCKeyEncryptionAlgorithm)keyAlgorithm
   contentEncryptionAlgorithm: (HCContentEncryptionAlgorithm)contentAlgorithm;

@end
