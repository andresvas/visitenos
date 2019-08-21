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
#import "MCJJWEEnvelope.h"
#import "MCJJWEInput.h"

/**
 JWE Service provider interface, which create MCJJWEEnvelope to protect and extract content. This interface should be used in producer or sender side which expects to create MCJJWEEnvelope first.
 */
@protocol MCJJWEProducer <NSObject>

/**
 @abstract              Creates JWEEnvelope to protect the content and includes necessary parameters.
 @param jweInput        MCJJWEInput for creating envelope.
 @param error           Error raised when MCJWEEnvelope object creation fails.
 @return                MCJJWEEnvelope containing the protected content.
 */
- (MCJJWEEnvelope *)createJWEEnvelope:(MCJJWEInput *)jweInput error:(NSError *__autoreleasing *)error;

/**
 @abstract              Extracts the content from JWEEnvelope.
 @param jweEnvelope     MCJJWEEnvelope object to be extracted.
 @param error           Error raised when extractContent of JWE envelope fails.
 @return                NSData of actual data.
 */
- (NSData *)extractContent:(MCJJWEEnvelope *)jweEnvelope error:(NSError *__autoreleasing *)error;

@end
