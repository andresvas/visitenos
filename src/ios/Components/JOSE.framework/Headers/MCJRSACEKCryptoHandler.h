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
#import "MCJCEKCryptoHandler.h"
#import "MCJCryptoService.h"
#import "MCJJWKRSAPublicKey.h"
#import "MCJJWKServerPublicKey.h"

/**
 Implements MCJCEKCryptoHandler using cryptography for RSA algorithm. This class provides cryptography operation for the following key encryption algorithms:
        
    - KeyEncryptionAlgorithm.RSA1_5
    - KeyEncryptionAlgorithm.RSA_OAEP
    - KeyEncryptionAlgorithm.RSA_OAEP_256
 */
@interface MCJRSACEKCryptoHandler: NSObject <MCJCEKCryptoHandler>

/**
 Private key of the participant. It is private key of the RSA key pair from which public key is sent to the other participant.
 */
@property (nonatomic) SecKeyRef privateKeyRef;

/**
 @abstract                          Creates MCJRSACEKCryptoHandler with given crypto service.
 @param cryptoService               Concrete object of MCJCryptoServiceProtocol protocol.
 @return                            MCJRSACEKCryptoHandler object
 */
- (instancetype)initWithCEKCryptoService:(id <MCJCryptoServiceProtocol>)cryptoService;

/**
 @abstract                          Sets publicKey of the opposite participant for establishing communication which uses RSA algorithm.
 @param handshakeRSAPublicKey       RSA public key to set.
 */
- (void)setHandshakeRSAPublicKey:(MCJJWKRSAPublicKey *)handshakeRSAPublicKey;

/**
 @abstract                          Sets x509Certificate public key certificate of the opposite participant for establishing communication which uses RSA algorithm.
 @param handshakeServerPublicKey    Server public key to set.
 */
- (void)setHandshakeServerPublicKey:(MCJJWKServerPublicKey *)handshakeServerPublicKey;

/**
 @abstract                          Sets the public key of the opposite participant for establishing communication which uses RSA algorithm.
 @param handshakeRSAPublicKeyData   Server public key to set.
 */
- (void)setHandshakeRSAPublicKeyData:(NSData *)handshakeRSAPublicKeyData;

@end
