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
#import "MCJContentEncryptionAlgorithm.h"

/**
 Provides content encryption algorithms specified in <a href="https://tools.ietf.org/html/rfc7518#section-5.1">JWA specification</a>.
 */
@interface MCJContentEncryptionAlgorithmMapper : NSObject

/**
 @abstract          Mapping of MCJContentEncryptionAlgorithm to a string format of the algorithm.
 @param algorithm   Algorithm for which string conversion is needed.
 @param error       If algorithm is not found in MCJContentEncryptionAlgorithm, then error is generated.
 @return            String format of MCJContentEncryptionAlgorithm constant.
 */
+ (NSString *)contentEncryptionAlgorithmToString:(MCJContentEncryptionAlgorithm)algorithm error:(NSError *__autoreleasing *)error;

/**
 @abstract          Gets MCJContentEncryptionAlgorithm from string form of Algorithm. If not found then returns -1.
 @param algorithm   Algorithm for which MCJContentEncryptionAlgorithm conversion is needed.
 @return            MCJContentEncryptionAlgorithm constant.
 */
+ (MCJContentEncryptionAlgorithm)getContentEncryptionAlgorithm:(NSString *)algorithm;

@end
