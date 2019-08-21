//
//  HCJweCreater.h
//  Component_iOS_JOSE_Implementation
//
//  Created by Malkan, Marmik on 12/6/16.
//  Copyright © 2016 Malkan, Marmik. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Component_iOS_JOSE_Interface/Component_iOS_JOSE_Interface.h>
#import <JOSE/JOSE.h>
//#import "HCCryptoPseudoRandomAlgorithm.h"


/**
 Implements IHCJweCreater and provides pre-defined steps mentioned in JWE Specification for creating envelope and extracting content from it. This class should be used in producer side. It should first create HCJweEnvelope and protect content in it using createJWEEnvelope.
 */
@interface HCJweCreater : NSObject<IHCJweCreater>

/**
 Creates HCJweCreater using the given MCJCEKCryptoHandler. It uses MCJAESHMacContentCryptoHandler as MCJContentCryptoHandler.
 
 @param cekCryptoHandler Implementation of MCJCEKCryptoHandler.
 @param error            On input, a pointer to variable for an NSError object. If an error occurs, this pointer is set to an NSError object containing information about the error. You may specify nil for this parameter if you do not want the error information.
 
 @return HCJweCreater object.
 */
- (instancetype)initWithCEKCryptoHandler:(id <MCJCEKCryptoHandler> )cekCryptoHandler
                                   error:(NSError **)error;

/**
 Creates HCJweCreater using the given MCJCEKCryptoHandler. It uses MCJAESHMacContentCryptoHandler as MCJContentCryptoHandler.
 
 @param cekCryptoHandler     Implementation of MCJCEKCryptoHandler.
 @param contentCryptoHandler Implementation of MCJContentCryptoHandler.
 @param error                On input, a pointer to variable for an NSError object. If an error occurs, this pointer is set to an NSError object containing information about the error. You may specify nil for this parameter if you do not want the error information.
 
 @return HCJweCreater object.
 */
- (instancetype)initWithCEKCryptoHandler:(id <MCJCEKCryptoHandler> )cekCryptoHandler
                    contentCryptoHandler:(id <MCJContentCryptoHandler> )contentCryptoHandler
                                   error:(NSError **)error;

/**
 Intialize creater for ECDH based envelope processing.
 
 @param serverPublicKey Server public key.
 
 @return Instance of HCJweCreater.
 */
- (instancetype)initWithECDHBasedEnvelope:(id)serverPublicKey
                      andProtectedHeaders:(NSDictionary *)protectedHeaders;

/**
 Intialize creater for PBES2 based envelope processing.
 
 */
- (instancetype)initWithPBES2EnvelopeWithPIN:(NSData *)pin
                                        salt:(NSData *)salt
                              numberOfRounds:(int)count
                         andProtectedHeaders:(NSDictionary *)protectedHeaders;

- (nullable NSString *)createJWESerializedString:(id<IHCJweInput>)jweInput
                                           error:(NSError **)error;

- (NSData *)extractContentFrom:(NSData *)envelopeData
                         error:(NSError **)error;

@end
