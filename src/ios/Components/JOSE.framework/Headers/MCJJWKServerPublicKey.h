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

#import <UIKit/UIKit.h>
#import "MCJJWKPublicKey.h"

/**
 Represents JWKEnvelope that will be received from server to get server's public key. This envelope contains trust chain of X509 certificates carrying server's public key. Client can validate certificate chain and extract server's public key from it.
 */
@interface MCJJWKServerPublicKey : MCJJWKPublicKey

/**
 @abstract  The "key_ops" (key operations) member identifies the operation(s) that the key is intended to be used for.  The "key_ops" parameter is intended for use cases in which public, private, or symmetric keys may be present.
 */
@property (nonatomic, strong) NSArray *key_ops;

/**
 @abstract  The "alg" (algorithm) member identifies the algorithm intended for use with the key.  The values used should either be registered in the IANA JSON Web Signature and Encryption Algorithms registry defined in [JWA] or be a value that contains a Collision-Resistant Name.  Use of this member is OPTIONAL.
 */
@property (nonatomic, strong) NSString *alg;

/**
 @abstract  The "x5u" (X.509 URL) member is a URI [RFC3986] that refers to a resource for an X.509 public key certificate or certificate chain [RFC5280].  The identified resource MUST provide a representation of the certificate or certificate chain that conforms to RFC 5280 [RFC5280] in PEM encoded form [RFC1421].  The key in the first certificate MUST match the public key represented by other members of the JWK.  The protocol used to acquire the resource MUST provide integrity protection; an HTTP GET request to retrieve the certificate MUST use TLS [RFC2818 and RFC5246]; the identity of the server MUST be validated, as per Section 6 of RFC 6125 [RFC6125].  Use of this member is OPTIONAL.
 */
@property (nonatomic, strong) NSString *x5u;

/**
 @abstract  The "x5c" (X.509 Certificate Chain) member contains a chain of one or more PKIX certificates [RFC5280].  The certificate chain is represented as a JSON array of certificate value strings.  Each string in the array is a base64 encoded ([RFC4648] Section 4 -- not base64url encoded) DER [ITU.X690.1994] PKIX certificate value.
 */
@property (nonatomic, strong) NSArray *x5c;

/**
 @abstract  The "x5t" (X.509 Certificate SHA-1 Thumbprint) member is a base64url encoded SHA-1 thumbprint (a.k.a. digest) of the DER encoding of an X.509 certificate [RFC5280].  The key in the certificate MUST match the public key represented by other members of the JWK.  Use of this member is OPTIONAL.
 */
@property (nonatomic, strong) NSString *x5t;

/**
 @abstract  Initiates MCJJWKServerPublicKey with the given dictionary with JWK server key received from server.
 @param     dictionary server key received from server.
 @return    MCJJWKServerPublicKey object.
 */
- (instancetype) initWithDictionary:(NSDictionary *)dictionary;

@end
