//
//  HCJweOrchestrator.h
//  Component_iOS_JOSE_Implementation
//
//  Created by Shah, Chetan on 4/26/17.
//  Copyright © 2017 Malkan, Marmik. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Component_iOS_JOSE_Interface/Component_iOS_JOSE_Interface.h>
#import <JOSE/JOSE.h>

@interface HCJweOrchestrator : NSObject <IHCJweOrchestrator>

@property (nonatomic,readwrite) HCKeyEncryptionAlgorithm keyEncryptionAlgo;
@property (nonatomic,readwrite) HCContentEncryptionAlgorithm contentEncryptionAlgo;

- (MCJKeyEncryptionAlgorithm)getKeyEncryptionAlgorithm:(HCKeyEncryptionAlgorithm)alg;
- (MCJContentEncryptionAlgorithm)getContentEncryptionAlgorithm:(HCContentEncryptionAlgorithm)enc;
- (SerializationType)getSerializationType:(HCSerializationType)serializationType;
- (NSDictionary * _Nullable )extractProtectedHeader:(NSString* _Nonnull)protectedHeaderEncoded  error:(NSError *_Nullable *_Nullable)error;
-(id  <MCJCEKCryptoHandler> _Nullable)deriveCEKCryptoHandler:(NSError *_Nullable *_Nullable)error;
@end
