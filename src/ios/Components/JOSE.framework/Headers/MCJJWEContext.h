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
#import "MCJJWEParameters.h"

/**
 Provides JWE context during the encryption and decryption of the plain text.
 */
@interface MCJJWEContext : NSObject

/**
 @abstract Gets the intermediate JWE parameters.
 @return MCJJWEParameters object.
 */
+ (MCJJWEParameters *)getIntermediateJWEParameters;

/**
 @abstract Sets the intermediate JWE parameters.
 @param jweParameters JWE parameters to be set for creation of JWE Envelope.
 */
+ (void)setIntermediateJWEParameters:(MCJJWEParameters *)jweParameters;

/**
 @abstract Sets the received protected header during the JWE envelope creation.
 @param protectedHeaderMap Received protected headers to be set in JWE envelope.
 */
+ (void)setReceivedProtectedHeaders:(NSDictionary *)protectedHeaderMap;

/**
 @abstract Sets the received unprotected header during the JWE envelope creation.
 @param unprotectedHeaders Received unprotected headers to be set in JWE envelope.
 */
+ (void)setReceivedUnprotectedHeaders:(NSDictionary *)unprotectedHeaders;

/**
 @abstract Gets the received protected header for the given key.
 @param key Key for the protected header.
 @return NSString value.
 */
+ (NSString *)getReceivedProtectedHeaders:(NSString *)key;

/**
 @abstract Gets the received unprotected header for the given key.
 @param key Key for the protected header.
 @return NSString value.
 */
+ (NSString *)getReceivedUnprotectedHeaders:(NSString *)key;

/**
 @abstract Sets the custom protected header.
 @param dictionary Custom protected header in form of key-value pair.
 */
+ (void)setCustomProtectedHeader:(NSDictionary *)dictionary;

/**
 @abstract Sets the custom unprotected header.
 @param dictionary Custom unprotected header in form of key-value pair.
 */
+ (void)setCustomUnprotectedHeader:(NSDictionary *)dictionary;

/**
 @abstract Gets the custom protected header.
 @return NSDictionary object.
 */
+ (NSDictionary *)getCustomProtectedHeaders;

/**
 @abstract Gets the custom unprotected header.
 @return NSDictionary object.
 */
+ (NSDictionary *)getCustomUnprotectedHeaders;

@end
