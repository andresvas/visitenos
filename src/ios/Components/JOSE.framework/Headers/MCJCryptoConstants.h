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
 Contains crypto constants used in crypto function.
 */
@interface MCJCryptoConstants : NSObject

/**
 Represents "ECDH" algorithm.
 */
extern NSString * const ECDH;

/**
 Represents "AES" algorithm.
 */
extern NSString * const AES;

/**
 Represents "EC" algorithm.
 */
extern NSString * const EC;

/**
 Represents "AESWrap" algorithm.
 */
extern NSString * const AES_WRAP;

/**
 Represents "RSA" algorithm.
 */
extern NSString * const RSA;

/**
 Represents EC curve "prime256v1".
 */
extern NSString * const PRIME256V1;

/**
 Represents hashing algorithm "SHA-1".
 */
extern NSString * const SHA_1;

/**
 Represents hashing algorithm "HMacSHA384".
 */
extern NSString * const H_MAC_SHA384;

/**
 Represents hashing algorithm "HMacSHA256".
 */
extern NSString * const H_MAC_SHA256;

/**
 Represents hashing algorithm "HMacSHA512".
 */
extern NSString * const H_MAC_SHA512;

/**
 Represents "AES/CBC/PKCS7Padding" algorithm.
 */
extern NSString * const AES_CBC_PKCS7_PADDING;

/**
 Represents "RSA/ECB/PKCS1Padding" algorithm.
 */
extern NSString * const RSA_ECB_PKCS1_PADDING;

/**
 Represents "RSA/ECB/OAEPWithSHA-256AndMGF1Padding" algorithm.
 */
extern NSString * const RSA_ECB_OAEP_WITH_SHA_256_AND_MGF1_PADDING;

/**
 Represents "RSA/ECB/OAEPWithSHA-1AndMGF1Padding" algorithm.
 */
extern NSString * const RSA_ECB_OAEP_WITH_SHA_1_AND_MGF1_PADDING;

@end
