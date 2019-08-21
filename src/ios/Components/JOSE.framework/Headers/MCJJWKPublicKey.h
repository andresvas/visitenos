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

/**
 A JSON Web Key (JWK) is a JavaScript Object Notation (JSON) data structure that represents a cryptographic key.  This specification also defines a JWK Set JSON data structure that represents a set of JWKs. For more information refer: https://tools.ietf.org/html/rfc7517.
 */
@interface MCJJWKPublicKey : NSObject

/**
 @abstract  The "kty" (key type) member identifies the cryptographic algorithm family used with the key. "kty" values should either be registered in the IANA JSON Web Key Types registry defined in [JWA] or be a value that contains a Collision-Resistant Name.  The "kty" value is a case-sensitive string.  This member MUST be present in a JWK.
 */
@property (nonatomic, strong) NSString *kty;

/**
 @abstract  The "use" (public key use) member identifies the intended use of the public key.  The "use" parameter is intended for use cases in which it is useful to distinguish between public signing keys and public encryption keys.
 */
@property (nonatomic, strong) NSString *use;

/**
 @abstract  The "kid" (key ID) member can be used to match a specific key.  This can be used, for instance, to choose among a set of keys within a JWK Set during key rollover.  The structure of the "kid" value is unspecified.  When "kid" values are used within a JWK Set, different keys within the JWK Set SHOULD use distinct "kid" values.  (One example in which different keys might use the same "kid" value is if they have different "kty" (key type) values but are considered to be equivalent alternatives by the application using them.)  The "kid" value is a case-sensitive string.  Use of this member is OPTIONAL.
 */
@property (nonatomic, strong) NSString *kid;

/**
 @abstract Initialization method for JWK public key.
 @param dictionary There can be multiple JWK public keys in dictionary format.
 @return MCJJWKPublicKey object.
 */
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

/**
 @abstract This method is used to return JOSE specific params of the JWK public key.
 @return NSDictionary object.
 */
- (NSDictionary *)toJoseSpecificParams;

@end
