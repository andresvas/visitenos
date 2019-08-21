/*
 Author:© 2017 Mastercard. Proprietary. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import "IHCExtractedEnvelope.h"
/**
 JWE represents encrypted content using JSON data structures and base64url encoding. The followings are the three types of serialization defined by JWE specifications:
 
 - JWE_JSON
 - JWE_FLATTENED
 - JWE_COMPACT
 */

typedef NS_ENUM (int, HCSerializationType)  {
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
    HC_JWE_JSON = 0,
    
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
    HC_JWE_FLATTENED,
    
    /** In the JWE Compact Serialization, no JWE Shared Unprotected Header or JWE Per-Recipient Unprotected Header are used. In the JWE Compact Serialization, a JWE is represented as the concatenation as shown below:
     
     - BASE64URL(UTF8(JWE Protected Header)) || '.' ||
     - BASE64URL(JWE Encrypted Key) || '.' ||
     - BASE64URL(JWE Initialization Vector) || '.' ||
     - BASE64URL(JWE Ciphertext) || '.' ||
     - BASE64URL(JWE Authentication Tag)
     */
    HC_JWE_COMPACT
};

@protocol IHCJweOrchestrator <NSObject>

/**
 Orchestrates request.
 
 @param requestHeader request header which is used as custom protected headers in JWE envelop.
 @param encodedBody request body which is used as JWEInput in JWE envelop.
 @param serializationType sets up JWE serialization pattern.
 @param error    On input, a pointer to variable for an NSError object. If an error occurs, this pointer is set to an NSError object containing information about the error. You may specify nil for this parameter if you do not want the error information.
 
 @return NSString of given input parameters.
 */

-(NSString * _Nullable) orchestrateRequestHeader: (NSDictionary* _Nullable)requestHeader
                                     encodedBody: (NSData* _Nullable)encodedBody
                               serializationType: (HCSerializationType)serializationType
                                           error: (NSError * _Nullable * _Nullable)error;

/**
 Orchestrates response.
 
 @param responseData response data received from the server which needs to deserialized.
 @param serializationType sets up JWE serialization pattern.
 @param error    On input, a pointer to variable for an NSError object. If an error occurs, this pointer is set to an NSError object containing information about the error. You may specify nil for this parameter if you do not want the error information.
 
 @return deserialized id object of given response data.
 */

-(id <IHCExtractedEnvelope> _Nullable) orchestrateResponse: (NSData* _Nonnull)responseData
        serializationType: (HCSerializationType)serializationType
                    error: (NSError * _Nullable * _Nullable)error;

@end

