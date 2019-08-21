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
 JWE Utils provides the utility methods for the JWE envelope creation.
 */
@interface MCJJWEUtils : NSObject

/**
 @abstract This method is used to populate the protected headers in the MCJJWEContext class.
 @param protectedHeaders Populates the protected header in the MCJJWEContext class.
 */
+ (void)populateProtectedHeadersFromContext:(NSMutableDictionary *)protectedHeaders;

/**
 @abstract Gets the protected header in plain text from base64 encoded.
 @param protectedHeader Protected header dictionary in the decoded base64 format.
 @return NSString object.
 */
+ (NSString *)getProtectedHeaderBase64Decoded:(NSString *)protectedHeader;

@end
