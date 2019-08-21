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
#import "MCJCEKData.h"

/**
 Holds JWE envelope related parameters.
 */
@interface MCJJWEParameters : NSObject

/**
 */
@property (nonatomic, strong) MCJCEKData *cekData;

/**
 */
@property (nonatomic, strong) NSString *aad;

/**
 */
@property (nonatomic, strong) NSDictionary *jweReceivedProtectedHeaders;

/**
 */
@property (nonatomic, strong) NSDictionary *jweReceivedUnprotectedHeaders;

/**
 */
@property (nonatomic, strong) NSDictionary *jweCustomProtectedHeaders;

/**
 */
@property (nonatomic, strong) NSDictionary *jweCustomUnprotectedHeaders;

@end
