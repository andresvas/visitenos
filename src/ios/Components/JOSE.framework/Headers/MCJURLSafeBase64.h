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
 Utility class for base64 & url-safe base64 encoding/decoding
 */
@interface MCJURLSafeBase64 : NSObject

/**
 @abstract              Convinient method to get the new instance of this class.
 @return                Instance of MTPURLSafeBase64 class
 */
+ (MCJURLSafeBase64 *)newInstance;

/**
 @abstract              Function to base64 encode the data
 @param     data        NSData * value to be encoded into base64 format
 @param     isUrlSafe   Flag to indicate plain base64 if false otherwise url safe base64 encodded string is produced.
 @return                Base64 or url safe base64 encoded string
 */
- (NSString *)base64EncodedStringWithData:(NSData *)data urlSafe:(BOOL)isUrlSafe;

/**
 @abstract              Function to decode the base64 encoded string
 @param     aString     NSString * value to be decoded
 @param     isUrlSafe   Flag to indicate if plain base64 decode (if false) otherwise url safe base64 decoded data is produced.
 @return                Base64 or url safe base64 decoded data
 */
- (NSData *)dataFromBase64String:(NSString *)aString urlSafe:(BOOL)isUrlSafe;

@end
