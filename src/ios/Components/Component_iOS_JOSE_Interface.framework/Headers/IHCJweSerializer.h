/*
 Author:© 2017 Mastercard. Proprietary. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import "IHCJweEnvelope.h"
#import "IHCCompression.h"
#import "IHCJweAlgorithms.h"
/**
 Interface for Serializes and deserializes objects into and   from the JSON format.
 */
@protocol IHCJweSerializer <NSObject>

/**
 Encodes given json string to JWT   token and applies requested encryption/compression algorithms.

 @param payload        JSON string to encode (not null or whitespace).
 @param key            Key for encryption(CEK).
 @param aad            Defines JWE aad.
 @param algorithmType  Key Wrap Algorithm Types.
 @param encryptionType Encryption Algorithm Types.
 @param compression    Compression implementation.
 @param error           On input, a pointer to variable for an NSError object. If an error occurs, this pointer is set to an NSError object containing information about the error. You may specify nil for this parameter if you do not want the error information.

 @return Compact serialization form, encrypted and/or compressed.
 */
- (id <IHCJweEnvelope>)encodeWithPayload:(NSString *)payload
                                 key:(NSData *)key
                                 aad:(NSData *)aad
                       algorithmType:(HCKeyEncryptionAlgorithm)algorithmType
                      encryptionType:(HCContentEncryptionAlgorithm)encryptionType
                         compression:(id<IHCCompression>)compression
                               error:(NSError **)error;

/**
 Decodes the specified envelope data.

 @param envelopeData Defines HCJweEnvelope.
 @param key          Key for encryption, suitable for provided JWS algorithm, can be null.
 @param compression  Compression implementation.
 @param error        On input, a pointer to variable for an NSError object. If an error occurs, this pointer is set to an NSError object containing information about the error. You may specify nil for this parameter if you do not want the error information.

 @return Decrypted envelope data.
 */
- (NSString *)decodeWithEnveopeData:(id <IHCJweEnvelope>)envelopeData
                                key:(NSData *)key
                        compression:(id<IHCCompression>)compression
                              error:(NSError **)error;
@end
