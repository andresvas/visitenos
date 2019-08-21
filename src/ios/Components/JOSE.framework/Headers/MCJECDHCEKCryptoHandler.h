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
#import "MCJCryptoServiceProtocol.h"
#import "MCJCEKCryptoHandler.h"
#import "MCJJWKServerPublicKey.h"
#import "MCJJWKECDHPublicKey.h"
#import "MCJKeyEncryptionAlgorithm.h"

/**
 Implements MCJCEKCryptoHandler using cryptography for ECDH-ES AESKW algorithm. This class provides cryptography operation for following key encryption algorithms:
 
    - ECDH_ES_A128KW
    - ECDH_ES_A192KW
    - ECDH_ES_A256KW
 */
@interface MCJECDHCEKCryptoHandler : NSObject<MCJCEKCryptoHandler>

/**
 Private key of the participant. It is private key of the EC key pair from which public key is sent to the other participant.
 */
@property (nonatomic, strong) NSData *privateKey;

/**
 @abstract                          Creates MCJECDHCEKCryptoHandler with given cryptoService.
 @param cryptoService               Concrete object of MCJCryptoServiceProtocol protocol.
 @return                            MCJECDHCEKCryptoHandler object
 */
- (instancetype)initWithCEKCryptoService:(id <MCJCryptoServiceProtocol>)cryptoService;

/**
 @abstract                          Sets x509Certificate public key certificate of the opposite participant for establishing communication which uses ECDH algorithm.
 @param handshakeServerPublicKey    Server public key to set.
 */
- (void)setHandshakeServerPublicKey:(MCJJWKServerPublicKey *)handshakeServerPublicKey;

/**
 @abstract                          Sets public key in form of X and Y component of the opposite participant for establishing communication which uses ECDH algorithm.
 @param handshakeECDHPublicKey      ECDH public key to set.
 */
- (void)setHandshakeECDHPublicKey:(MCJJWKECDHPublicKey *)handshakeECDHPublicKey;

/**
 @abstract                          Sets public key of the opposite participant for establishing communication which uses ECDH algorithm.
 @param handshakeECDHPublicKey      ECDH public key to set.
 */
- (void)setHandshakeDataPublicKey:(NSData *)handshakeDataPublicKey;

@end
