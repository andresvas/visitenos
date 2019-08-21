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
 Provides PBES2 based MCJKEKDerivationParameters.
 */
@interface MCJPBES2KEKDerivationParameters: NSObject<MCJKEKDerivationParameters>

/**
 The salt expands the possible keys that can be derived from a given password.  A Salt Input value containing 8 or more octets MUST be used.  A new Salt Input value MUST be generated randomly for every encryption operation
 */
@property (nonatomic, strong, readonly) NSData *saltValue;

/**
 The "p2c" (PBES2 count) Header Parameter contains the PBKDF2 iteration count, represented as a positive JSON integer. The iteration count adds computational expense, ideally compounded by the possible range of keys introduced by the salt.  A minimum iteration count of 1000 is RECOMMENDED.
 */
@property (nonatomic, readonly) int count;

/**
 A Key Management Mode in which the CEK value is encrypted to the intended recipient using an asymmetric encryption algorithm.
 */
@property (nonatomic, readonly) MCJKeyEncryptionAlgorithm keyEncryptionAlgorithm;

/**
 @abstract              Initialization method for PBES2 KEK derivation parameters.
 @param alg             MCJKeyEncryptionAlgorithm
 @param iterationCount  Number of iteration to be set.
 @param saltValue       Salt value.
 @return                MCJECDHKEKDerivationParameters object
 */
- (instancetype)initWithKeyEncryptionAlgorithm:(MCJKeyEncryptionAlgorithm)alg iterationCount:(int)iterationCount saltValue:(NSData *)saltValue;

@end
