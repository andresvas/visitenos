/*
 Author:© 2017 Mastercard. Proprietary. All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 Key encryption key management
 */
@protocol IHCKeyManagement <NSObject>

/**
 Generates new Encryption Key.

 @param keyLength Length of key to generate (bits).
 @param error     On input, a pointer to variable for an NSError object. If an error occurs, this pointer is set to an NSError object containing information about the error. You may specify nil for this parameter if you do not want the error information.

 @return Plain encryption key.
 */
- (NSData *)generateNewKey:(int)keyLength
                     error:(NSError **)error;

/**
  encrypt the CEK with the shared symmetric key using the symmetric Key Wrap algorithm to produce the JWE Encrypted Key.

 @param plainCEK Plain encryption key.
 @param KEK      KEK used to protected CEK.
 @param error    On input, a pointer to variable for an NSError object. If an error occurs, this pointer is set to an NSError object containing information about the error. You may specify nil for this parameter if you do not want the error information.

 @return wrapped(encrypted) CEK.
 */
- (NSData *)wrap:(NSData *)plainCEK
             key:(NSData *)KEK
           error:(NSError **)error;

/**
 Unwraps protected CEK using provided management key.

 @param encryptedCek Wrapped (encrypted) CEK.
 @param KEK          KEK used to protected CEK.
 @param error        On input, a pointer to variable for an NSError object. If an error occurs, this pointer is set to an NSError object containing information about the error. You may specify nil for this parameter if you do not want the error information.

 @return Unwrapped (decrypted) CEK.
 */
- (NSData *)unwrap:(NSData *)encryptedCek
               key:(NSData *)KEK
             error:(NSError **)error;

@end
