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
#import "MCJAADGenerator.h"

/**
 Provides basic content cryptography services.
 */
@interface MCJBaseContentCryptoHandler: NSObject

/**
 Plugable aadGenerator
 */
@property (nonatomic, strong) id <MCJAADGenerator> aadGenerator;

/**
 @abstract          Generates the initialization vector for given byteLength.
 @param byteLength  length of IV to be generated.
 @return            generated IV
 */
- (NSData *)generateInitializationVector:(int)byteLength;

/**
 @abstract          Returns the 64-Bit Big-Endian representation of AAD Length
 @param aad         Additional Authentication Data
 @return            64-Bit Big-Endian NSData.
 */
- (NSData *)calculateAL:(NSData *)aad;

@end
