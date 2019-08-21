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
#import "MCJBaseContentCryptoHandler.h"
#import "MCJContentCryptoHandler.h"
#import "MCJCryptoServiceProtocol.h"

/**
 Implements ContentCryptoHandler using JCA for AES-HMAC algorithm. This class provides JCA based cryptography operation for following content encryption algorithm:
 
    - A128CBC_HS256
    - A192CBC_HS384
    - A256CBC_HS512
 */
@interface MCJAESHMacContentCryptoHandler: MCJBaseContentCryptoHandler <MCJContentCryptoHandler>

/**
 @abstract              Creates the instance.
 @param cryptoSpi       Initializes the instance with default provided crypto service class.
 return                 MCJAESHMacContentCryptoHandler instance.
 */
- (instancetype)initWithCryptoService:(id <MCJCryptoServiceProtocol>)cryptoSpi;

/**
 @abstract              Creates the instance.
 @param cryptoSpi       Initializes the instance with default provided crypto service class.
 @param AADGenerator    Default AAD generator class.
 @return                MCJAESHMacContentCryptoHandler instance.
 @see                   MCJAADGenerator
 */
- (instancetype)initWithCryptoService:(id <MCJCryptoServiceProtocol>)cryptoSpi aadGenerator:(id <MCJAADGenerator>)AADGenerator;

@end
