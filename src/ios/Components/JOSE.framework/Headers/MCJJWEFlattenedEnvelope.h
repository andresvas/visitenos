/*******************************************************************************
 * Copyright (c) 2016, MasterCard International Incorporated and/or its
 * affiliates. All rights reserved.
 *
 * TO THE EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS", WITHOUT
 * WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NON INFRINGEMENT. TO THE EXTENT PERMITTED BY LAW, IN NO EVENT SHALL
 * MASTERCARD OR ITS AFFILIATES BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *******************************************************************************/

#import <Foundation/Foundation.h>
#import "MCJRecipientInfo.h"

/**
 The flattened JWE JSON Serialization syntax is based upon the general syntax, but flattens it, optimizing it for the single-recipient case. It flattens it by removing the "recipients" member and instead placing those members defined for use in the "recipients" array (the "header" and "encrypted_key" members) in the top-level JSON object (at the same level as the "ciphertext" member).
 
 The "recipients" member MUST NOT be present when using this syntax. Other than this syntax difference, JWE JSON Serialization objects using the flattened syntax are processed identically to those using the general syntax.
 */
@interface MCJJWEFlattenedEnvelope : NSObject

/**
 @abstract Describes JWE Protected Header. JSON object that contains the Header Parameters that are integrity protected by the authenticated encryption operation.  These parameters apply to all recipients of the JWE.  For the JWE Compact Serialization, this comprises the entire JOSE Header.  For the JWE JSON Serialization, this is one component of the JOSE Header.
 */
@property (nonatomic, strong) NSString *protectedHeader;

/**
 @abstract JSON object that contains the Header Parameters that apply to all recipients of the JWE that are not integrity protected.  This can only be present when using the JWE JSON Serialization.
 */
@property (nonatomic, strong) NSDictionary *unprotected;

/**
 This member must be present and contain the value JWE Per-Recipient Unprotected Header when the JWE Per-Recipient Unprotected Header value is non-empty; otherwise, it must be absent. This value is represented as an unencoded JSON object, rather than as a string.  These Header Parameter values are not integrity protected.
 */
@property (nonatomic, strong) NSDictionary *header;

/**
 This member must be present and contain the value BASE64URL(JWE Encrypted Key) when the JWE Encrypted Key value is non-empty; otherwise, it must be absent.
 */
@property (nonatomic, strong) NSData *encrypted_key;

/**
 @abstract Initialization Vector value used when encrypting the plaintext. Note that some algorithms may not use an Initialization Vector, in which case this value is the empty octet sequence.
 */
@property (nonatomic, strong) NSData *iv;

/**
 @abstract Describes an input to an Authenticated Encryption with Associated Data (AEAD) operation that is integrity protected but not encrypted.
 */
@property (nonatomic, strong) NSString *aad;

/**
 @abstract Ciphertext value resulting from authenticated encryption of the plaintext with Additional Authenticated Data.
 */
@property (nonatomic, strong) NSData *ciphertext;

/**
 @abstract Describes Authentication Tag value resulting from authenticated encryption of the plaintext with Additional Authenticated Data.
 */
@property (nonatomic, strong) NSData *tag;

@end
