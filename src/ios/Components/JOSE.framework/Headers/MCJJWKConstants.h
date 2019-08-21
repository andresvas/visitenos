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
 Contains JWK related constants.
 */
@interface MCJJWKConstants : NSObject

/**
 Represents JWE constant "apv".
 */
extern NSString * const APV;

/**
 Represents JWE constant "apu".
 */
extern NSString * const APU;

/**
 Represents JWE constant "alg".
 */
extern NSString * const ALG;

/**
 Represents JWE constant "epk".
 */
extern NSString * const EPK;

/**
 Represents JWE constant "p2c".
 */
extern NSString * const P2C;

/**
 Represents JWE constant "p2s".
 */
extern NSString * const P2S;

/**
 Represents JWE constant "jwk".
 */
extern NSString * const JWK;

/**
 Represents JWE constant "enc".
 */
extern NSString * const ENC;

/**
 Represents constant "kid".
 */
extern NSString * const KEY_ID;

/**
 Represents constant "kty".
 */
extern NSString * const KEY_TYPE;

/**
 Represents constant "x".
 */
extern NSString * const KEY_X;

/**
 Represents constant "y".
 */
extern NSString * const KEY_Y;

/**
 Represents constant "n".
 */
extern NSString * const KEY_N;

/**
 Represents constant "e".
 */
extern NSString * const KEY_E;

/**
 Represents constant "crv".
 */
extern NSString * const KEY_CURVE;

/**
 Represents constant "use".
 */
extern NSString * const KEY_USE;

/**
 Represents constant "typ".
 */
extern NSString * const TYPE;

/**
 Represents constant "cty".
 */
extern NSString * const CONTENT_TYPE;

/**
 Represents constant "jku".
 */
extern NSString * const JWK_SET_URL;

/**
 Represents constant "x5t".
 */
extern NSString * const X509_CERTIFICATE_THUMBPRINT;

/**
 Represents constant "x5u".
 */
extern NSString * const X509_URL;

/**
 Represents constant "epk".
 */
extern NSString * const EPHEMERAL_PUBLIC_KEY;

/**
 Represents constant "apu".
 */
extern NSString * const AGREEMENT_PARTY_U_INFO;

/**
 Represents constant "apv".
 */
extern NSString * const AGREEMENT_PARTY_V_INFO;

/**
 Represents constant "zip".
 */
extern NSString * const ZIP;

/**
 Represents constant "p2s".
 */
extern NSString * const PBES2_SALT_INPUT;

/**
 Represents constant "p2c".
 */
extern NSString * const PBES2_ITERATION_COUNT;

/**
 Represents constant "iv".
 */
extern NSString * const INITIALIZATION_VECTOR;

/**
 Represents constant "tag".
 */
extern NSString * const AUTHENTICATION_TAG;

/**
 Represents constant "key_ops".
 */
extern NSString * const KEY_OPERATIONS;

@end
