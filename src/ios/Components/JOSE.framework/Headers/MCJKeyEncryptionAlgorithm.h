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

#ifndef MCJKeyEncryptionAlgorithm_h
#define MCJKeyEncryptionAlgorithm_h

/**
 A Key Management Mode in which the CEK value is encrypted to the intended recipient using an asymmetric encryption algorithm. Provides key encryption algorithm specified in <a href="https://tools.ietf.org/html/rfc7518#section-4.1">JWA specification</a>.
 */
typedef NS_ENUM(int, MCJKeyEncryptionAlgorithm) {
    
    /**
     PBES2 with HMAC SHA-256 and CEKData wrapped with "A128KW".
     */
    PBES2_HS256_A128KW,
    
    /**
     PBES2 with HMAC SHA-384 and CEKData wrapped with "A192KW".
     */
    PBES2_HS384_A192KW,
    
    /**
     PBES2 with HMAC SHA-512 and CEKData wrapped with "A256KW".
     */
    PBES2_HS512_A256KW,
    
    /**
     ECDH-ES using concatenated KDF and CEKData wrapped with "A128KW"
     */
    ECDH_ES_A128KW,
    
    /**
     ECDH-ES using concatenated KDF and CEKData wrapped with "A192KW"
     */
    ECDH_ES_A192KW,
    
    /**
     ECDH-ES using concatenated KDF and CEKData wrapped with "A256KW"
     */
    ECDH_ES_A256KW,
    
    /**
     Elliptic Curve Diffie-Hellman Ephemeral Static key agreement using concatenated KDF
     */
    ECDH_ES,
    
    /**
     Key wrapping with AES GCM using 128-bit key
     */
    A128GCMKW,
    
    /**
     Key wrapping with AES GCM using 192-bit key
     */
    A192GCMKW,
    
    /**
     Key wrapping with AES GCM using 256-bit key
     */
    A256GCMKW,
    
    /**
     AES key wrapping with default initial value using 128-bit key
     */
    A128KW,
    
    /**
     AES key wrapping with default initial value using 192-bit key
     */
    A192KW,
    
    /**
     AES key wrapping with default initial value using 256-bit key
     */
    A256KW,
    
    /**
     RSAES OAEP using default parameters
     */
    RSA_OAEP,
    
    /**
     RSAES OAEP using SHA-256 and MGF1 with SHA-256
     */
    RSA_OAEP_256,
    
    /**
     RSAES- using PKCS1-v1-5
     */
    RSA1_5
};

#endif /* MCJKeyEncryptionAlgorithm_h */
