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
 Declares encrypted content using JavaScript Object Notation (JSON) based data structures. It is a data structure representing an encrypted and integrity-protected message.
 */
@interface MCJJWEEnvelope : NSObject

/**
 @abstract Describes JWE Protected Header. JSON object that contains the Header Parameters that are integrity protected by the authenticated encryption operation.  These parameters apply to all recipients of the JWE.  For the JWE Compact Serialization, this comprises the entire JOSE Header.  For the JWE JSON Serialization, this is one component of the JOSE Header.
 */
@property (nonatomic, strong) NSString *protectedHeader;

/**
 @abstract JSON object that contains the Header Parameters that apply to all recipients of the JWE that are not integrity protected.  This can only be present when using the JWE JSON Serialization.
 */
@property (nonatomic, strong) NSDictionary *unprotected;

/**
 @abstract JSON object that contains Header Parameters that apply to a single recipient of the JWE.  These Header Parameter values are not integrity protected.  This can only be present when using the JWE JSON Serialization.
 */
@property (nonatomic, strong) NSArray<MCJRecipientInfo *> *recipients;

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
