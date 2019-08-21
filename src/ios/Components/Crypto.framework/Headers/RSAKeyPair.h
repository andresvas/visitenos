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

@protocol RSAKeyPair <KeyPair>

/**
 @abstract           This method is called to get the modulus component of RSA public key.
 @return             Returns the modulus of RSA public key in form of NSData object.
 */
- (NSData *)getModulus;  // n

/**
 @abstract           This method is called to generate the public key using cryptographic algorithm.
 @return             Returns the exponent of RSA public key in form of NSData object.
 */
- (NSData *)getExponent;  // e

/**
 @abstract           This method is called to generate the public key using cryptographic algorithm.
 @return             Returns the exponent of RSA public key in form of SecKeyRef type.
 */
- (SecKeyRef)getPublicKeyRef;

/**
 @abstract           This method is called to generate the public key using cryptographic algorithm.
 @return             Returns the exponent of RSA public key in form of SecKeyRef type.
 */
- (SecKeyRef)getPrivateKeyRef;

@end
