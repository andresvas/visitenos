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
#import "MCJEncryptedData.h"
#import "MCJContentEncryptionAlgorithm.h"
#import "MCJContentCryptoData.h"

/**
 Provides cryptography services for content.
 */
@protocol MCJContentCryptoHandler <NSObject>

/**
 @abstract                  Encrypts content.
 @param data                data to be encrypted
 @param contentCryptoData   ContentCryptoData for encryption
 @param enc                 ContentEncryptionAlgorithm used for encryption
 @param error               Content crypto exception if content encryption fails
 @return                    encrypted content
 */
- (MCJEncryptedData *)encrypt:(NSData *)data contentCryptoData:(MCJContentCryptoData *)contentCryptoData contentEncryptionAlgorithm:(MCJContentEncryptionAlgorithm)enc error:(NSError *__autoreleasing *)error;

/**
 @abstract                  Decrypts content.
 @param encryptedTextData   data to be decrypted
 @param contentCryptoData   ContentCryptoData used for decryption
 @param enc                 ContentEncryptionAlgorithm  used for decryption
 @param error               Content crypto exception if content decryption fails
 @return                    decrypted content
 */
- (NSData *)decrypt:(MCJEncryptedData *)encryptedTextData contentCryptoData:(MCJContentCryptoData *)contentCryptoData contentEncryptionAlgorithm:(MCJContentEncryptionAlgorithm)enc error:(NSError *__autoreleasing *)error;

/**
 @abstract                  Generates CEK for given enc.
 @param enc                 ContentEncryptionAlgorithm
 @param error               Content crypto exception if CEK generation fails.
 @return                    generated CEK.
 */
- (NSData *)generateCEK:(MCJContentEncryptionAlgorithm)enc error:(NSError *__autoreleasing *)error;

@end
