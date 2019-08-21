/*
 Author:© 2017 Mastercard. Proprietary. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import "IHCContentEncryptionParts.h"

/**
 Interface for encryp and decrypt objects using encryption key   information
 */
@protocol IHCJweAlgorithm <NSObject>

/**
 Encrypts given plain text with   Content Encryption Key (KEY).

 @param aad       Additional   Authnetication Data.
 @param plainText Encoded text.
 @param cek       Content encryption key.
 @param error     On input, a pointer to variable for an NSError object. If an error occurs, this pointer is set to an NSError object containing information about the error. You may specify nil for this parameter if you do not want the error information.

 @return HCContentEncryptionParts
 */
- (id<IHCContentEncryptionParts>)encrypt:(NSData *)aad
                            plainText:(NSData *)plainText
                                  cek:(NSData *)cek
                                error:(NSError **)error;

/**
 @abstract
 @param  aad
 @param  cek
 @param  jweEnvelopeKey
*/

/**
 Decrypts the specified envelope   data.

 @param aad            Additional   Authnetication Data.
 @param cek            Content encryption key.
 @param jweEnvelopeKey iv, cipher text and   auth tag.
 @param error          On input, a pointer to variable for an NSError object. If an error occurs, this pointer is set to an NSError object containing information about the error. You may specify nil for this parameter if you do not want the error information.

 @return plain data.
 */
- (NSData *)decrypt:(NSData *)aad
                cek:(NSData *)cek
     jweEnvelopeKey:(id<IHCContentEncryptionParts>)jweEnvelopeKey
              error:(NSError **)error;

@end
