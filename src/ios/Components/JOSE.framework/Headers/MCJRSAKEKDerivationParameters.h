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
#import "MCJKeyEncryptionAlgorithmMapper.h"
#import "MCJKEKDerivationParameters.h"

/**
 Provides RSA based KEKDerivationParameters.
 */
@interface MCJRSAKEKDerivationParameters : NSObject <MCJKEKDerivationParameters>

/**
 JSON Web key. It contains RSA public key.
 */
@property (nonatomic, strong, readonly) NSString *jwk;

/**
 A Key Management Mode in which the CEK value is encrypted to the intended recipient using an asymmetric encryption algorithm.
 */
@property (nonatomic, readonly) MCJKeyEncryptionAlgorithm kekDerivationAlgorithm;

/**
 @abstract              Initialization method for RSA KEK derivation parameters.
 @param jwk             JSON Web Key.
 @param alg             MCJKeyEncryptionAlgorithm
 @return                MCJRSAKEKDerivationParameters object
 */
- (instancetype)initWithJWK:(NSString *)jwk keyEncryptionAlgorithm:(MCJKeyEncryptionAlgorithm)alg;

@end
