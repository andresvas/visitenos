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
 Provides content encryption algorithms specified in JWA specification (https://tools.ietf.org/html/rfc7518#section-5.1)
 */
typedef NS_ENUM(int, MCJContentEncryptionAlgorithm) {
    
    /**
     Content encryption algorithm AES/CBC with 128 bit size and HMacSHA256 hashing algorithm.
     */
    A128CBC_HS256,
    
    /**
     Content encryption algorithm AES/CBC with 192 bit size and HMacSHA384 hashing algorithm.
     */
    A192CBC_HS384,
    
    /**
     Content encryption algorithm AES/CBC with 256 bit size and HMacSHA512 hashing algorithm.
     */
    A256CBC_HS512,
    
    /**
     Content encryption algorithm AES-GCM with 128 bit size.
     */
    A128GCM,
    
    /**
     Content encryption algorithm AES-GCM with 192 bit size.
     */
    A192GCM,
    
    /**
     Content encryption algorithm AES-GCM with 256 bit size.
     */
    A256GCM,
};
