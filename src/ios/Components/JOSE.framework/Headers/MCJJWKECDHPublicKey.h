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
#import "MCJJWKPublicKey.h"

/**
 Contains Elliptic curve Diffie Hellman (ECDH) related JWK public key.
 */
@interface MCJJWKECDHPublicKey : MCJJWKPublicKey

/**
 The "crv" (curve) parameter identifies the cryptographic curve used with the key.
 */
@property (nonatomic, strong) NSString *crv;

/**
 The "key_ops" (key operations) parameter identifies the operation(s) for which the key is intended to be used.  The "key_ops" parameter is intended for use cases in which public, private, or symmetric keys may be present. Its value is an array of key operation values.
 */
@property (nonatomic, strong) NSString *keyOps;

/**
 The "x" (x coordinate) parameter contains the x coordinate for the Elliptic Curve point.  It is represented as the base64url encoding of the octet string representation of the coordinate.
 */
@property (nonatomic, strong) NSString *x;

/**
 The "y" (y coordinate) parameter contains the y coordinate for the Elliptic Curve point.  It is represented as the base64url encoding of the octet string representation of the coordinate
 */
@property (nonatomic, strong) NSString *y;

@end
