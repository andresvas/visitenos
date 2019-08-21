/*
 Author:© 2017 Mastercard. Proprietary. All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 Represents content secured with digital signatures   or Message Authentication Codes (MACs) using JavaScript Object Notation   (JSON) based data structure.
 */
@protocol IHCJwsAlgorithm <NSObject>

/**
 Signs given cipher text with   input Key (KEY).

 @param securedInput Encrypted Cipher text.
 @param key          Key to be used for digital signature.
 @param error        On input, a pointer to variable for an NSError object. If an error occurs, this pointer is set to an NSError object containing information about the error. You may specify nil for this parameter if you do not want the error information.

 @return Signed cipher data.
 */
- (NSData *)sign:(NSData *)securedInput
             key:(NSData *)key
           error:(NSError **)error;

/**
 Verifies cipher data signature.

 @param signedCipherInput Signed Cipher text.
 @param key               Key to be used for digital signature.
 @param error             On input, a pointer to variable for an NSError object. If an error occurs, this pointer is set to an NSError object containing information about the error. You may specify nil for this parameter if you do not want the error information.

 @return integrity verfication   of signed cipher data.
 */
- (BOOL)verify:(NSData *)signedCipherInput
           key:(NSData *)key
         error:(NSError **)error;

@end
