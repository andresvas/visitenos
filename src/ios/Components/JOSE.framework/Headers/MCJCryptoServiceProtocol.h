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

#ifndef MCJCryptoServiceProtocol_h
#define MCJCryptoServiceProtocol_h

//@import Crypto;

#import "MCJSecretKeyPairProtocol.h"
#import "MCJSecretKeyProtocol.h"
#import "MCJRSAKeyPairProtocol.h"

typedef NS_ENUM(uint32_t, CryptoPaddingOptions)
{
    CryptoPaddingOptionPKCS7Padding   = 0x0001,
    CryptoPaddingOptionECBMode        = 0x0002
};
/**
 Defines the interfaces for cryptographic functions.
 */
@protocol MCJCryptoServiceProtocol <NSObject>

/**
 @abstract                  Generates cryptographically secure key with specified size.
 @param     keySize         Size of the key to be generated. Expected values are 128,256,512.
 @return                    An object confirming to <SecretKey> protocol
 @see                       See SecretKey
 */
- (id<MCJSecretKeyProtocol>)generateAESKey:(int)keySize;

/**
 @abstract                  Derives the shared secret from the supplied public & private key.
 @discussion                This function uses Elliptic curve cryptography to derive the shared secret.
 @param   privateKey        The private key. Generally this is client's private key
 @param   serverPublicKey   The public key which correponds to server's public key. How to fetch the server public key depends on application use case.
 @return    NSData          The derived secret key bytes.
 */
- (NSData *)generateSharedSecretKeyWithServerPublicKey:(NSData *)serverPublicKey privateKey:(NSData *)privateKey;

/**
 @abstract                  Derive a KEK from a given algorithm, key length, sharedSecretKey and any other information.
 @param     macAlgorithm    The Pseudo Random Algorithm to use for the derivation iterations.
 @param     bitKeyLength    Key length of the Pseudo Random Algorithm.
 @param     sharedSecretKey This shared secret key is derived from public and private key.
 @param     otherInfo       Any other information that is to be passed in for KDF algorithm for generating KEK.
 @param     error           Error object that will be populated in case any error is generated.
 @return    NSData          The resulting derived Key Encryption Key (KEK) produced by the function.
 */
- (NSData *)deriveKeyUsingKDFForAlgorithm:(NSString *)macAlgorithm bitKeyLength:(int)bitKeyLength sharedSecretKey:(NSData *)sharedSecretKey otherInfo:(NSData *)otherInfo error:(NSError *__autoreleasing *)error;

/**
 @abstract                  Wrap a symmetric key with a Key Encryption Key (KEK).
 @discussion                The algorithm chosen is determined by the algorithm parameter and the size of the key being wrapped. It returns nil if an error occurs. Error may result from bad values for KeK and rawKey.
 @param     key             The Key Encryption Key to be used to wrap the raw key.
 @param     plainCEK        The raw key bytes to be wrapped.
 @param     error           Error object that will be populated in case any error is generated in wrapping the plainCEK with Key.
 @return    NSData          The wrapped key bytes.
 */
- (NSData *)wrap:(NSData *)plainCEK key:(NSData *)key error:(NSError *__autoreleasing *)error;

/**
 @abstract                  Unwrap a symmetric key with a Key Encryption Key (KEK).
 @discussion                The algorithm chosen is determined by the algorithm parameter and the size of the key being unwrapped. It returns nil if an error occurs. Error may result from bad values for KeK and wrappedKey.
 @param     encryptedCek    The raw key bytes to be unwrapped.
 @param     key             The key used to unwrap.
 @param     error           Error object that will be populated in case any error is generated in unwrapping the plainCEK with Key.
 @return    NSData          The unwrapped key bytes.
 */
- (NSData *)unwrap:(NSData *)encryptedCek key:(NSData *)key error:(NSError *__autoreleasing *)error;

/**
 @abstract                  Encrypt Data  using Advanced Encryption Standard (AES).
 @param     plainText       Data to be encrypted.
 @param     aSymmetricKey   Key to be used for encrypting the plain data.
 @param     ivBytes         Initialization vector
 @param     padding         Padding to be applied to the tailing block.
 @param     error           Error object that will be populated in case any error is generated in encrypting the data.
 @return    NSMutableData   The  chiper data generated after encryption.
 */
- (NSMutableData *)encryptWithAES:(NSMutableData *)plainText
                              key:(NSData *)aSymmetricKey
                               IV:(NSData*)ivBytes
                          padding:(uint32_t*)padding //CCOptions
                            error:(NSError *__autoreleasing *)error;

/**
 @abstract                  Decrypt Data using Advanced Encryption Standard (AES).
 @param     chiperText      Data to be decrypted.
 @param     aSymmetricKey   Key to be used for decrypting the cipher data.
 @param     ivBytes         Initialization vector.
 @param     padding         Padding applied when decrypting the data.
 @param     error           Error object that will be populated in case any error is generated in encrypting the data.
 @return    NSMutableData   Plain text generated after decryption.
 */
- (NSMutableData *)decryptWithAES:(NSMutableData *)chiperText
                              key:(NSData *)aSymmetricKey
                               IV:(NSData*)ivBytes
                          padding:(uint32_t*)padding
                            error:(NSError *__autoreleasing *)error;

/**
 @abstract                  Generates Hashed Message Authentication Code (HMAC) of size 20.
 @param     dataToEncrypt   Data used to generate the digest.
 @param     key             Key to be used for generating the HMAC.
 @return    NSData          The output with 20 byte length.
 */
+ (NSMutableData *)generateSHA1HMAChash:(NSData *)dataToEncrypt
                                    key:(NSData *)key;

/**
 @abstract                  Generates Hashed Message Authentication Code (HMAC) of size 32.
 @param     dataToEncrypt   Data used to generate the digest.
 @param     key             Key to be used for generating the HMAC
 @return    NSData          The output with 32 byte length.
 */
+ (NSMutableData *)generateSHA256HMAChash:(NSData *)dataToEncrypt
                                      key:(NSData *)key;

/**
 @abstract                  Generates Hashed Message Authentication Code (HMAC) of size 48.
 @param     dataToEncrypt   Data used to generate the digest.
 @param     key             Key to be used for generating the HMAC
 @return    NSData          The output with 48 byte length.
 */
+ (NSMutableData *)generateSHA384HMAChash:(NSData *)dataToEncrypt
                                      key:(NSData *)key;

/**
 @abstract                  Generates Hashed Message Authentication Code (HMAC) of size 64.
 @param     dataToEncrypt   Data used to generate the digest.
 @param     key             Key to be used for generating the HMAC
 @return    NSData          The output with 64 byte length.
 */
+ (NSMutableData *)generateSHA512HMAChash:(NSData *)dataToEncrypt
                                      key:(NSData *)key;

/**
 @abstract                  Generates Hashed Message Authentication Code (HMAC) of given digestLength size.
 @param     dataToEncrypt   Data used to generate the digest.
 @param     key             Key to be used for generating the HMAC.
 @param     hmacAlg         Hashed Message Authentication algorithm of CCHmacAlgorithm.
 @param     digestLength    Key to be used for generating the HMAC.
 @param     error           Key to be used for generating the HMAC.
 @return    NSData          The output with 20 byte length.
 */
//- (NSMutableData *)generateHMAC:(NSData*)dataToEncrypt
//                            key:(NSData*)key
//                        hmacAlg:(uint32_t)hmacAlg //CCHmacAlgorithm
//                   digestLength:(int)digestLength
//                          error:(NSError *__autoreleasing *)error;

- (NSMutableData *)generateHMAC:(NSData*)dataToEncrypt
                            key:(NSData*)key
                        hmacAlg:(NSString *)algoString //CCHmacAlgorithm
                          error:(NSError *__autoreleasing *)error;


/**
 @abstract                  Derive a key from a text password/passphrase.
 @param     password        The password used as input to the derivation.
 @param     salt            The salt byte values used as input to the derivation function.
 @param     count           The number of rounds of the Pseudo Random Algorithm.
 @param     keySize         The expected length of the derived key in bytes.
 @param     alg         	The Pseudo Random Algorithm to use for the derivation iterations.
 @param     error         	The error object populated in case any error is generated.
 @return    NSData      	The resulting derived key produced by the function.
 */
+ (NSData *)AESKeyForPassword:(NSData *)password
                         salt:(NSData *)salt
                        round:(NSUInteger)count
               derivedKeySize:(NSUInteger)keySize
                    algorithm:(NSString*)alg
                        error:(NSError **)error;

/**
 @abstract                  Extracts the public key at the first index position of the X.509 certificate chain.
 @param   certificateChain  Chain of certificate from which public certificate is to be extracted.
 @return                    Public Key in form of NSData object.
 */
- (NSData *)getPublicKeyFromCertificates:(NSArray *)certificateChain;

/**
 @abstract                  Gets the Big Number format of the NSData.
 @param input               Data to be converted to Big Number.
 @param error               Error object that will be populated in case any error is generated.
 @return                    Big Number in form of NSString object.
 */
+ (NSString *)getBigNumberFromNSData:(NSData *)input error:(NSError *__autoreleasing *)error;

/**
 @abstract                  Gets the NSData format of the Big Number.
 @param input               Big Number to be converted to NSData.
 @param error               Error object that will be populated in case any error is generated.
 @return                    NSData format of the given Big Number.
 */
+ (NSData *)getDataFromBigNumber:(NSString *)input error:(NSError *__autoreleasing *)error;


#pragma mark - ECDH Algorithm -
/////////////////////////////////
//        ECDH Algorithm
/////////////////////////////////
/**
 @abstract                  Generates an ECDH public & private key pair alongwith their X & Y components.
 @discussion                This function uses Elliptic curve Diffie–Hellman (ECDH) algorithm to generate the public & private key pair.
 @return                    Returns an object that confirms to id<SecretKeyPair>
 */
- (id<MCJSecretKeyPairProtocol> )generateECDHKeyPair;

/**
 @abstract                  Generates the public key from X and Y component.
 @param xInput              X component in decimal form of the public key that is received from the server response.
 @param yInput              Y component in decimal form of the public key that is received from the server response.
 @param error               Error object that will be populated in case any error is generated.
 @return                    Public key in form of NSData object.
 */
+ (NSData *)getPublicKeyFromDecimalX:(NSData *)xInput decimalY:(NSData *)yInput error:(NSError *__autoreleasing *)error;

/**
 @abstract                  Generates the public key from X and Y component.
 @param xInput              X component in binary form of the public key that is received from the server response.
 @param yInput              Y component in binary form of the public key that is received from the server response.
 @param error               Error object that will be populated in case any error is generated.
 @return                    Public key in form of NSData object.
 */
+ (NSData *)getPublicKeyFromBinaryX:(NSData *)xInput binaryY:(NSData *)yInput error:(NSError *__autoreleasing *)error;

/**
 @abstract                  Fetches X & Y Components from  the public key.
 @discussion                This function uses Elliptic curve cryptography where the public key is a point on a curve.
 @param publicKey           Public key from which to  X & Y coordinates need to be extracted.
 @return                    Returns an object that confirms to id<SecretKeyPair>. Use getXComponent & getYComponent method to get the coordinates.
 */
+ (id<MCJSecretKeyPairProtocol>)getXYComponentsFromPublicKey:(NSData *)publicKey;


#pragma mark - RSA Algorithm -
/////////////////////////////////
//        RSA Algorithm
/////////////////////////////////
/**
 @abstract                  Generates RSA key pair for the given key size. JOSE specification recommends 2048 bits key size.
 @param keyBits             Key size in bits for RSA algorithm.
 @param error               Error object that will be populated in case any error is generated.
 @return                    Returns an object that confirms to id<RSAKeyPair>
 */
+ (id<MCJRSAKeyPairProtocol>)generateRSAKeyPairWithKeySizeInBits:(int)keyBits error:(NSError *__autoreleasing *)error;

/**
 @abstract                  Generates the RSA public key from the given modulus and exponent.
 @param modulus             Modulus (n) component of the RSA public key.
 @param exponent            Exponent (e) component of the RSA public key.
 @param error               Error object that will be populated in case any error is generated.
 @return                    Returns the RSA public key in NSData format.
 */
+ (NSData *)generateRSAPublicKeyWithModulus:(NSData *)modulus exponent:(NSData *)exponent error:(NSError *__autoreleasing *)error;

/**
 @abstract                  Extracts the exponent part from the RSA public key.
 @param publicKey           RSA public key from which exponent is to be extracted.
 @param error               Error object that will be populated in case any error is generated.
 @return                    Exponent value in NSData object.
 */
+ (NSData *)getPublicKeyExponentFromKeyData:(NSData *)publicKey error:(NSError *__autoreleasing *)error;

/**
 @abstract                  Extracts the modulus part from the RSA public key.
 @param publicKey           RSA public key from which modulus is to be extracted.
 @param error               Error object that will be populated in case any error is generated.
 @return                    Modulus value in NSData object.
 */
+ (NSData *)getPublicKeyModulusFromKeyData:(NSData *)publicKey error:(NSError *__autoreleasing *)error;

/**
 @abstract                  Converts RSA public key from SecKeyRef to NSData object.
 @param publicKey           RSA public key that is to be converted to NSData object.
 @param error               Error object that will be populated in case any error is generated.
 @return                    NSData form of the RSA public key.
 */
+ (NSData *)getPublicKeyBitsFromKey:(SecKeyRef)publicKey error:(NSError *__autoreleasing *)error;

/**
 @abstract                  Converts RSA public key from NSData to SecKeyRef object.
 @param publicKeyData       RSA public key that is to be converted to SecKeyRef object.
 @param error               Error object that will be populated in case any error is generated.
 @return                    SecKeyRef form of the RSA public key.
 */
+ (SecKeyRef)getPublicKeyReferenceFromData:(NSData *)publicKeyData error:(NSError *__autoreleasing *)error;

/**
 @abstract                  Encrypts the plain data using RSA encryption method with the given public key & padding.
 @param plainData           Plain data to be encrypted.
 @param publicKey           Public key with which plain data to be encrypted.
 @param padding             Padding to be applied during encryption.
 @param error               Error object that will be populated in case any error is generated.
 @return                    Encrypted data in form of NSData object.
 */
+ (NSData *)encrypt:(NSData *)plainData RSAPublicKey:(SecKeyRef)publicKey padding:(SecPadding)padding error:(NSError *__autoreleasing *)error;

/**
 @abstract                  Decrypts the encrypted data using RSA decryption method with the given public key & padding.
 @param encryptedData       Encrypted data to be decrypted.
 @param privateKey          Private key with which encrypted data to be decrypted.
 @param padding             Padding to be applied during decryption.
 @param error               Error object that will be populated in case any error is generated.
 @return                    Plain data in form of NSData object.
 */
+ (NSData *)decrypt:(NSData *)encryptedData RSAPrivateKey:(SecKeyRef)privateKey padding:(SecPadding)padding error:(NSError *__autoreleasing *)error;

/**
 @abstract                  Extract out the ASN.1 header from the RSA public key.
 @param publicKey           RSA public key from which ASN.1 header to be removed.
 @param error               Error object that will be populated in case any error is generated.
 @return                    Public key in form of NSData after removing ASN.1 header.
 */
+ (NSData *)stripPublicKeyHeader:(NSData *)publicKey error:(NSError *__autoreleasing *)error;

@end

#endif /* MCJCryptoServiceProtocol_h */
