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
 Contains parameters required for content cryptography operation. It contains jweAad, protectedHeader and cekData.
 */
@interface MCJContentCryptoData : NSObject

/**
 Holds MCJCEKData used for content cryptography.
 */
@property (nonatomic, strong) MCJCEKData *cekData;

/**
 Holds protected header used for content cryptography.
 */
@property (nonatomic, strong) NSString *protectedheader;

/**
 @abstract              Constructor method to generate MCJContentCryptoData from given parameters.
 @param jweAad          JWE Additional Authentication Data.
 @param protectedheader Protected Header.
 @param cekData         Content Encryption Key object.
 @return                MCJContentCryptoData object.
 */
- (instancetype)initWithJweAad:(NSString *)jweAad Protectedheader:(NSString *)protectedheader CEKData:(MCJCEKData *)cekData;

/**
 Gets the JWE Additional Authentication Data.
 @return NSString object.
 */
- (NSString *)getJweAad;

/**
 @abstract Sets the JWE Additional Authentication Data from NSData.
 @param jweAad JWE Additional Authentication Data.
 */
- (void)setJweAadWithData:(NSData *)jweAad;

/**
 @abstract Sets the JWE Additional Authentication Data from NSString.
 @param jweAad JWE Additional Authentication Data.
 */
- (void)setJweAad:(NSString *)jweAad;

@end
