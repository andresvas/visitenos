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

/** @constant MCJJOSEErrorDomain constant Defines JOSE error domain constant. */
extern NSString * const MCJJOSEErrorDomain;

static NSString *ERROR_INVALID_DATA_PARAMETERS = @"Invalid parameters for given data.";
static NSString *ERROR_CEK_CRYPTO_HANDLER_NULL = @"CEK Crypto handler can not be null.";
static NSString *ERROR_CONTENT_CRYPTO_HANDLER_NULL = @"Content Crypto handler can not be null.";
static NSString *ERROR_KEY_ENCRYPTION_ALGORITHM_NULL = @"Null or empty value is not supported.";
static NSString *ERROR_CONTENT_ENCRYPTION_ALGORITHM_NULL = @"Null or empty value is not supported.";
static NSString *ERROR_CONTENT_ENC_ALGO_NOT_SUPPORTED = @"This implemetation only supports A***CBC-HS*** algorithms.";
static NSString *ERROR_KEY_NOT_FOUND = @"Handshake public key can not be null.";
static NSString *ERROR_PRIVATE_KEY_NOT_FOUND = @"Private key can not be null.";
static NSString *ERROR_INTEGRITY_CHECK_FAILED = @"Integrity check failed on received data.";
static NSString *ERROR_WRAP_SYMMETRIC_KEY_FAILED = @"Wrap symmetric key failed.";
static NSString *ERROR_UNWRAP_SYMMETRIC_KEY_FAILED = @"Unwrap symmetric key failed.";
static NSString *ERROR_INVALID_PARAMETERS_KDF = @"Invalid parameters for KDF.";
static NSString *ERROR_INVALID_OUTPUT_KDF = @"KDF's output is invalid.";
static NSString *ERROR_WRAP_SYMMETRIC_KEY_INVALID = @"Wrap symmetric key is invalid.";
static NSString *ERROR_UNWRAP_SYMMETRIC_KEY_INVALID = @"Unwrap symmetric key is invalid.";
static NSString *ERROR_ECDH_KEY_ENCRYPTION_ALGORITHM_NOT_SUPPORTED = @"This implemetation only supports ECDH-ES-A***KW algorithms.";
static NSString *ERROR_SHA_HMAC_HASHING_FAILED = @"SHA***HMAC hashing failed.";
static NSString *ERROR_CONTENT_ENCRYPTION_FAILED = @"Content encryption failed.";
static NSString *ERROR_CONTENT_DECRYPTION_FAILED = @"Content decryption failed.";
static NSString *ERROR_PBES2_KEY_ENCRYPTION_ALGORITHM_NOT_SUPPORTED = @"This implemetation only supports PBES-HS-A***KW algorithms.";
static NSString *ERROR_ALGORITHM_NOT_SUPPORTED = @"This algorithm is not supported.";
static NSString *ERROR_PIN_BLOCK_NULL = @"Provide pinBlock for PBES implementaion";
static NSString *ERROR_SALT_NULL = @"Provide salt for PBES implementaion";
static NSString *ERROR_EPK_NULL = @"Missing epk in protected header.";
static NSString *ERROR_INVALID_ITERATION_COUNT = @"Iteration count must be greate than or equals 1000";
static NSString *ERROR_CRYPTO = @"Internal crypto error";
static NSString *ERROR_INVALID_PROTECTED_HEADER = @"p2c/p2s is not provided in protected header map for PBES implementaion";
static NSString *ERROR_INVALID_KEY_SIZE = @"Invalid key size";
static NSString *ERROR_SHARED_SECRET_KEY_GENERATION = @"Shared secret key generation failed";
static NSString *ERROR_INVALID_SERIALIZED_JOSE_PACKET = @"Deserialization of JOSE packet failed due to invalid serialized JOSE packet.";
static NSString *ERROR_INVALID_JWE_ENVELOPE = @"Serialization of JWE Envelope failed due to invalid envelope.";
static NSString *ERROR_INVALID_SERIALIZATION_TYPE = @"Serialization type is not supported.";


/**
 Defines the error constants for JOSE. Also provides the localized keys used for error messages.
 */
@interface MCJJOSEErrorConstants : NSObject

@end
