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
 Contains constants for AES-HMAC based on JWA specification.
 */
@interface MCJAESHMacConstants : NSObject

/**
 Represents "HMacSHA" variants of ContentEncryptionAlgorithm#A192CBC_HS384
 */
extern NSString * const HS384;

/**
 Represents "HMacSHA" variants of ContentEncryptionAlgorithm#A256CBC_HS512
 */
extern NSString * const HS512;

/**
 Represents "HMacSHA" variants of ContentEncryptionAlgorithm#A128CBC_HS256
 */
extern NSString * const HS256;

/**
 Represents "AES/CBC" variants of ContentEncryptionAlgorithm#A192CBC_HS384
 */
extern NSString * const A192CBC;

/**
 Represents "AES/CBC" variants of ContentEncryptionAlgorithm#A256CBC_HS512
 */
extern NSString * const A256CBC;

/**
 Represents "AES/CBC" variants of ContentEncryptionAlgorithm#A128CBC_HS256
 */
extern NSString * const A128CBC;

@end
