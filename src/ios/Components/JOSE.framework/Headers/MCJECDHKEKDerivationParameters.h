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
 Provides ECDH based MCJKEKDerivationParameters.
 */
@interface MCJECDHKEKDerivationParameters : NSObject <MCJKEKDerivationParameters>

/**
 ECDH public key (Ephemeral Public Key)
 */
@property (nonatomic, strong, readonly) NSString *epk;

/**
 Key encryption algorithm
 */
@property (nonatomic, readonly) MCJKeyEncryptionAlgorithm kekDerivationAlgorithm;

/**
 The "apu" (Agreement PartyUInfo) value for key agreement algorithms using it (such as "ECDH-ES"), represented as a base64url-encoded string.
 */
@property (nonatomic, strong, readonly) NSString *apu;

/**
 @abstract          Creates with the epk and key derivation parameters.
 @param epk         ECDH public key
 @param alg         MCJKeyEncryptionAlgorithm
 @return            MCJECDHKEKDerivationParameters object
 */
- (instancetype)initWithEPK:(NSString *)epk keyEncryptionAlgorithm:(MCJKeyEncryptionAlgorithm)alg;

/**
 @abstract          Creates with the epk and key derivation parameters.
 @param epk         ECDH public key
 @param alg         MCJKeyEncryptionAlgorithm
 @param apu         Agreement PartyUInfo
 @return            MCJECDHKEKDerivationParameters object
 */
- (instancetype)initWithEPK:(NSString *)epk keyEncryptionAlgorithm:(MCJKeyEncryptionAlgorithm)alg apu:(NSString *)apu;

@end
