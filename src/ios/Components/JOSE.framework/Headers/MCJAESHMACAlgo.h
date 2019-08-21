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
 This class represents content encryption related data.
 */
@interface MCJAESHMACAlgo : NSObject

/**
 The string instance representing keyAlgo.
 */
@property (nonatomic, strong) NSString *keyAlgo;

/**
 The string instance representing keySize.
 */
@property (nonatomic) int keySize;

/**
 The string instance representing encAlgo.
 */
@property (nonatomic, strong) NSString *encAlgo;

/**
 The string instance representing authKeyAlgo.
 */
@property (nonatomic, strong) NSString *authKeyAlgo;

/**
 The string instance representing authAlgo.
 */
@property (nonatomic, strong) NSString *authAlgo;

/**
 Integer representing the authKeySize;
 */
@property (nonatomic) int authKeySize;

@end
