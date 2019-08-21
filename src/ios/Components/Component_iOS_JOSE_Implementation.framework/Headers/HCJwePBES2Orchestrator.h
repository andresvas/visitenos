//
//  HCJwePBES2Orchestrator.h
//  Component_iOS_JOSE_Implementation
//
//  Created by Shah, Chetan on 4/26/17.
//  Copyright © 2017 Malkan, Marmik. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HCJweOrchestrator.h"
#import <Component_iOS_JOSE_Interface/Component_iOS_JOSE_Interface.h>

@interface HCJwePBES2Orchestrator : HCJweOrchestrator <IHCJweOrchestrator>

//Default salt will be applied incase no salt is set.
@property (nonatomic,strong)  NSData *salt;
//Default count will be applied incase no count is set.
@property (nonatomic,strong)  NSNumber *count;

@property (nonatomic,strong) NSString *walletPinKeyProvider;


/**
 Initializes HCJwePBES2Orchestrator.
 
 @param walletPin Initializes self with wallet PIN.
 @param keyAlgorithm Key encryption algorithm from HCKeyEncryptionAlgorithm enum.
 @param contentAlgorithm Content encryption algorithm from HCContentEncryptionAlgorithm enum.
 
 */

-(instancetype)initWithWalletPin: (NSString*) walletPin
          keyEncryptionAlgorithm: (HCKeyEncryptionAlgorithm)keyAlgorithm
      contentEncryptionAlgorithm: (HCContentEncryptionAlgorithm)contentAlgorithm;

@end
