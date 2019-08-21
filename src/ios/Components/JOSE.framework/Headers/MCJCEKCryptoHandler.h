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
#import "MCJCEKData.h"
#import "MCJKeyEncryptionAlgorithm.h"

/**
 Provides cryptography services for CEK. This is used for KeyEncryptionAlgorithm. See MCJCEKData.
 */
@protocol MCJCEKCryptoHandler <NSObject>

/**
 @abstract                  Encrypts CEKData.
 @param cek                 MCJCEKData.
 @param alg                 MCJKeyEncryptionAlgorithm to be used for encryption.
 @param error               This may fail if CEK encryption fails or if cryptography operation fails.
 @return                    MCJCEKData set with CEKCipher and MCJKEKDerivationParameters in it.
 */
- (MCJCEKData *)encrypt:(NSData *)cek keyEncryptionAlgorithm:(MCJKeyEncryptionAlgorithm)alg error:(NSError *__autoreleasing *)error;

/**
 @abstract                  Decrypts CEKData.
 @param cekCipher           MCJCEKData set with cekCipher and KEKDerivationParameters in it.
 @param protectedHeaderMap  MCJKeyEncryptionAlgorithm to be used for decryption.
 @param error               This may fail if CEK decryption fails or if cryptography operation fails.
 @return                    Decrypted CEK in form of NSData.
 */
- (NSData *)decrypt:(NSData *)cekCipher map:(NSDictionary *)protectedHeaderMap error:(NSError *__autoreleasing *)error;

@end
