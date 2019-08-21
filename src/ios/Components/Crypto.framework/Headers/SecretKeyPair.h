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
#import "KeyPair.h"

/**
 This protocol is used to get several of the components of the EC Public key like X, Y, binary X & binary Y components.
 */
@protocol SecretKeyPair <KeyPair>

/**
 @abstract            This is the X component of the EC public key in decimal format.
 @return              Returns the X component of the EC public key in decimal format in form of NSData object.
 */
- (NSData *)getXcomponent;

/**
 @abstract            The Y component of the EC public key in decimal format.
 @return              Returns the Y component of the EC public key in decimal format in form of NSData object.
 */
- (NSData *)getYcomponent;

/**
 @abstract            This is the binary representation of X component (Two's complement) of the EC public key in decimal format.
 @return              Returns the X component of the EC public key in binary format in form of NSData object.
 */
- (NSData *)getBinaryXcomponent;

/**
 @abstract            This is the binary representation of Y component (Two's complement) of the EC public key in decimal format.
 @return              Returns the Y component of the EC public key in binary format in form of NSData object.
 */
- (NSData *)getBinaryYcomponent;

@end
