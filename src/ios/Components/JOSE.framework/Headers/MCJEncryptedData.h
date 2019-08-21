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
 Contains encrypted content data. It contains cipherText, tag and iv.
 */
@interface MCJEncryptedData: NSObject

/**
 Initialization Vector value used when encrypting the plaintext. Note that some algorithms may not use an Initialization Vector, in which case this value is the empty octet sequence.
 */
@property (nonatomic, strong, readonly) NSData *iv;

/**
 Ciphertext value resulting from authenticated encryption of the plaintext with Additional Authenticated Data.
 */
@property (nonatomic, strong, readonly) NSData *cipherText;

/**
 Authentication Tag value resulting from authenticated encryption of the plaintext with Additional Authenticated Data.
 */
@property (nonatomic, strong, readonly) NSData *tag;

/**
 @abstract Initialize the class with the cipher text, tag & IV values.
 @param cipherText It is plain text to be encrypted.
 @param tag Authentication tag.
 @param iv Initialization vector.
 @return MCJEncryptedData object.
 */
- (instancetype)initWithCipherText:(NSData *)cipherText Tag:(NSData *)tag IV:(NSData *)iv;

@end
