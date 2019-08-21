//
//  HCJweECDHOrchastrator.h
//  Component_iOS_JOSE_Implementation
//
//  Created by Shah, Harshit on 5/25/17.
//  Copyright © 2017 Malkan, Marmik. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HCJweOrchestrator.h"
#import "HCJJWKECDHPublicKey.h"
#import <Component_iOS_JOSE_Interface/Component_iOS_JOSE_Interface.h>

@interface HCJweECDHOrchastrator : HCJweOrchestrator 

@property (nonatomic,strong) HCJJWKECDHPublicKey *ecdhKey;


-(instancetype)initWithECDHKey: (HCJJWKECDHPublicKey*) ecdhKey
       keyEncryptionAlgorithm: (HCKeyEncryptionAlgorithm)keyAlgorithm
   contentEncryptionAlgorithm: (HCContentEncryptionAlgorithm)contentAlgorithm;

@end
