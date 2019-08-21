//
//  HCJweInput.h
//  Component_iOS_JOSE_Implementation
//
//  Created by Malkan, Marmik on 12/5/16.
//  Copyright © 2016 Malkan, Marmik. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Component_iOS_JOSE_Interface/Component_iOS_JOSE_Interface.h>

/**
 Represents input required to produce a JSON Web Encryption (JWE).
 */
@interface HCJweInput : NSObject<IHCJweInput>

/**
 Creates JWEInput object with the provided input data.

 @param data Data to be protected.
 @param aad  Defines JWE aad.
 @param alg  Defines HCKeyEncryptionAlgorithm used.
 @param enc  Defines HCContentEncryptionAlgorithm used.

 @return HCJweInput object
 */
- (instancetype)initWithData:(NSData *)data
                         AAD:(NSData *)aad
      keyEncryptionAlgorithm:(HCKeyEncryptionAlgorithm)alg
  contentEncryptionAlgorithm:(HCContentEncryptionAlgorithm)enc;

@end
