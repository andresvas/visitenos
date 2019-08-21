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
#import "MCJJWEProducer.h"
#import "MCJCEKCryptoHandler.h"
#import "MCJContentCryptoHandler.h"

/**
 Implements MCJJWEProducer and provides pre-defined steps mentioned in <a href="https://tools.ietf.org/html/rfc7516">JWE Specification</a> for creating envelope and extracting content from it. This class should be used in producer side. It should first create MCJJWEEnvelope and protect content in it using createJWEEnvelope.
 */
@interface MCJJWEProducerImpl : NSObject <MCJJWEProducer>

/**
 @abstract                      Creates MCJJWEProducerImpl using the given MCJCEKCryptoHandler. It uses MCJAESHMacContentCryptoHandler as MCJContentCryptoHandler.
 @param cekCryptoHandler        Implementation of MCJCEKCryptoHandler.
 @param error                   Error, if any, raised during CEK initialization.
 @return                        MCJJWEProducerImpl object.
 */
- (instancetype)initWithCEKCryptoHandler:(id <MCJCEKCryptoHandler> )cekCryptoHandler error:(NSError *__autoreleasing *)error;

/**
 @abstract                      Creates MCJJWEProducerImpl using the given MCJCEKCryptoHandler. It uses MCJAESHMacContentCryptoHandler as MCJContentCryptoHandler.
 @param cekCryptoHandler        Implementation of MCJCEKCryptoHandler.
 @param contentCryptoHandler    Implementation of MCJContentCryptoHandler.
 @param error                   Error, if any, raised during CEK initialization.
 @return                        MCJJWEProducerImpl object.
 */
- (instancetype)initWithCEKCryptoHandler:(id <MCJCEKCryptoHandler> )cekCryptoHandler contentCryptoHandler:(id <MCJContentCryptoHandler> )contentCryptoHandler error:(NSError *__autoreleasing *)error;

@end
