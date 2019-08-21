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
#import "MCJKEKDerivationParameters.h"

/**
 Holds the Content Encryption Key (CEK) related data. Contains CEK and CEKCipher. It also composites MCJKEKDerivationParameters used for deriving KEK.
 */
@interface MCJCEKData : NSObject

/**
 A symmetric key for the Authenticated Encryption with Associated Data (AEAD) algorithm used to encrypt the plaintext to produce the ciphertext and the Authentication Tag. Data type of Cek can be SecretKey or key alias
 */
@property (nonatomic, strong) NSData *cek;

/**
 */
@property (nonatomic, strong) NSData *cekCipher;

/**
 */
@property (nonatomic, strong) id<MCJKEKDerivationParameters> kekDerivationParameters;

/**
 @abstract                      Creates the instance.
 @param cek                     Content encryption key in NSData format.
 @param cekCipher               CEK cipher data.
 @param derivationParameters    Key Encryption Key derivation parameters.
 @return                        MCJCEKData instance.
 */
- (instancetype)initWithCEK:(NSData *)cek cekCipher:(NSData *)cekCipher kekDerivationParameters:(id <MCJKEKDerivationParameters> )derivationParameters;

/**
 @abstract                        Sets the KEK derivation parameter map.
 @param kekDerivationParameterMap Map to be set in KEK derivation parameters.
 */
- (void)setKekDerivationParameterMap:(NSDictionary *)kekDerivationParameterMap;

/**
 @abstract                      Gets the KEK derivation parameter map.
 @return                        NSDictionary object.
 */
- (NSDictionary *)getKekDerivationParameterMap;

@end
