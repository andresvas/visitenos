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
#import "MCJJWEEnvelope.h"
#import "MCJJWEFlattenedEnvelope.h"

/**
 JWE represents encrypted content using JSON data structures and base64url encoding. The followings are the three types of serialization defined by JWE specifications: 
 
    - JWE_JSON
    - JWE_FLATTENED
    - JWE_COMPACT
 */
typedef NS_ENUM (int, SerializationType)  {
    /** In the JWE JSON Serialization, a JWE is represented as a JSON object containing some or all of these eight members:
     
        - "protected", with the value BASE64URL(UTF8(JWE Protected Header))
        - "unprotected", with the value JWE Shared Unprotected Header
        - "header", with the value JWE Per-Recipient Unprotected Header
        - "encrypted_key", with the value BASE64URL(JWE Encrypted Key)
        - "iv", with the value BASE64URL(JWE Initialization Vector)
        - "ciphertext", with the value BASE64URL(JWE Ciphertext)
        - "tag", with the value BASE64URL(JWE Authentication Tag)
        - "aad", with the value BASE64URL(JWE AAD)
     
     Note: header and encrypted_key will be part of Recipients array.
     */
    JWE_JSON = 0,
    
    /** The Flattened JWE JSON Serialization is optimized for the single-recipient case. The flattened serialization does not hold "recipients" member and places the "header" and "encrypted_key" members. The syntax of a JWE using the Flattened JWE JSON Serialization is as follows:
     
    - "protected":"integrity-protected header contents",
    - "unprotected":non-integrity-protected header contents,
    - "header":more non-integrity-protected header contents,
    - "encrypted_key":"encrypted key contents",
    - "aad":"additional authenticated data contents",
    - "iv":"initialization vector contents",
    - "ciphertext":"ciphertext contents",
    - "tag":"authentication tag contents"
     */
    JWE_FLATTENED,
    
    /** In the JWE Compact Serialization, no JWE Shared Unprotected Header or JWE Per-Recipient Unprotected Header are used. In the JWE Compact Serialization, a JWE is represented as the concatenation as shown below:
     
        - BASE64URL(UTF8(JWE Protected Header)) || '.' ||
        - BASE64URL(JWE Encrypted Key) || '.' ||
        - BASE64URL(JWE Initialization Vector) || '.' ||
        - BASE64URL(JWE Ciphertext) || '.' ||
        - BASE64URL(JWE Authentication Tag)
     */
    JWE_COMPACT
};


/**
 Provides JWE JSON serialization and de-serialization. This class supports following three types of serialization based on JWE Specification (https://tools.ietf.org/html/rfc7516#section-7):
 
    - JWE Compact Serialization
    - General JWE JSON Serialization
    - Flattened JWE JSON Serialization
 */
@interface MCJJWESerializerDeserializer : NSObject

/**
 @abstract                      Serializes JWEEnvelope with the given SerializationType into JSON string.
 @param     jweEnvelope         Declares encrypted content using JavaScript Object Notation (JSON) based data structures.
 @param     serializationType   Specifies the SerializationType for JWEEnvelope object.
 @param     error               If any error arises during serialization of JWEEnvelope object, then error parameter will be populated with proper error code and message.
 @return                        Serialized JSON string.
 */
- (nullable NSString *)serialize:(MCJJWEEnvelope * _Nullable)jweEnvelope serializationType:(SerializationType)serializationType error:(NSError * __autoreleasing _Nullable * _Nullable)error;

/**
 @abstract                      De-serializes JWE serialized JSON string into JWEEnvelope object.
 @param     object              JSON data to be deserialized.
 @param     serializationType   Specifies the SerializationType for JWEEnvelope object.
 @param     error               If any error arises during de-serialization of JWEEnvelope object, then error parameter will be populated with proper error code and message.
 @return                        De-serialized JWEEnvelope object from JSON data.
 */
- (nullable MCJJWEEnvelope *)deserialize:(NSData * _Nullable)object serializationType:(SerializationType)serializationType error:(NSError * __autoreleasing _Nullable * _Nullable)error;

@end
