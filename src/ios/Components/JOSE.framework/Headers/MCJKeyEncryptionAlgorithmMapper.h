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

/**
 Provides key encryption algorithm specified in <a href="https://tools.ietf.org/html/rfc7518#section-4.1">JWA specification</a>.
 */
@interface MCJKeyEncryptionAlgorithmMapper : NSObject

/**
 @abstract          Mapping of MCJKeyEncryptionAlgorithm to a string format of the algorithm.
 @param algorithm   Algorithm for which string conversion is needed.
 @param error       If algorithm is not found in MCJKeyEncryptionAlgorithm, then error is generated.
 @return            String format of MCJKeyEncryptionAlgorithm constant.
 */
+ (NSString *)keyEncryptionAlgorithmToString:(MCJKeyEncryptionAlgorithm)algorithm error:(NSError *__autoreleasing *)error;

/**
 @abstract          Gets MCJKeyEncryptionAlgorithm from string form of Algorithm. If not found then returns -1.
 @param algorithm   Algorithm for which MCJKeyEncryptionAlgorithm conversion is needed.
 @return            MCJKeyEncryptionAlgorithm constant.
 */
+ (MCJKeyEncryptionAlgorithm)getKeyEncryptionAlgorithm:(NSString *)algorithm;

@end
