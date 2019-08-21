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
#import "MCJKeyEncryptionAlgorithm.h"
#import "MCJContentEncryptionAlgorithm.h"

/**
 Represents input required to produce a JSON Web Encryption (JWE).
 */
@interface MCJJWEInput : NSObject

/**
 */
@property (nonatomic, strong) NSData *data;

/**
 */
@property (nonatomic, strong) NSData *aad;

/**
 */
@property (nonatomic) MCJKeyEncryptionAlgorithm alg;

/**
 */
@property (nonatomic) MCJContentEncryptionAlgorithm enc;

/**
 @abstract      Creates JWEInput object with the provided input data.
 @param data    Data to be protected.
 @param aad     Defines JWE aad.
 @param alg     Defines MCJKeyEncryptionAlgorithm used.
 @param enc     Defines MCJContentEncryptionAlgorithm used.
 @return        MCJJWEInput object
 */
- (instancetype)initWithData:(NSData *)data aad:(NSData *)aad keyEncryptionAlgorithm:(MCJKeyEncryptionAlgorithm)alg contentEncryptionAlgorithm:(MCJContentEncryptionAlgorithm)enc;

@end
