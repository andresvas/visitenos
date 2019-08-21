/*
 Author:© 2017 Mastercard. Proprietary. All rights reserved.
 */

#ifndef IHCJweAlgorithms_h
#define IHCJweAlgorithms_h

/**
 A Key Management Mode in which the CEK value is encrypted to the intended recipient using an asymmetric encryption algorithm.
 */
typedef NS_ENUM(int, HCKeyEncryptionAlgorithm) {
    
    /**
     PBES2 with HMAC SHA-256 and CEKData wrapped with "A128KW".
     */
    HC_PBES2_HS256_A128KW,
    
    /**
     PBES2 with HMAC SHA-384 and CEKData wrapped with "A192KW".
     */
    HC_PBES2_HS384_A192KW,
    
    /**
     PBES2 with HMAC SHA-512 and CEKData wrapped with "A256KW".
     */
    HC_PBES2_HS512_A256KW,
    
    /**
     ECDH-ES using concatenated KDF and CEKData wrapped with "A128KW"
     */
    HC_ECDH_ES_A128KW,
    
    /**
     ECDH-ES using concatenated KDF and CEKData wrapped with "A192KW"
     */
    HC_ECDH_ES_A192KW,
    
    /**
     ECDH-ES using concatenated KDF and CEKData wrapped with "A256KW"
     */
    HC_ECDH_ES_A256KW,
    
    /**
     Elliptic Curve Diffie-Hellman Ephemeral Static key agreement using concatenated KDF
     */
    HC_ECDH_ES,
    
    /**
     Key wrapping with AES GCM using 128-bit key
     */
    HC_A128GCMKW,
    
    /**
     Key wrapping with AES GCM using 192-bit key
     */
    HC_A192GCMKW,
    
    /**
     Key wrapping with AES GCM using 256-bit key
     */
    HC_A256GCMKW,
    
    /**
     AES key wrapping with default initial value using 128-bit key
     */
    HC_A128KW,
    
    /**
     AES key wrapping with default initial value using 192-bit key
     */
    HC_A192KW,
    
    /**
     AES key wrapping with default initial value using 256-bit key
     */
    HC_A256KW,
    
    /**
     RSAES OAEP using default parameters
     */
    HC_RSA_OAEP,
    
    /**
     RSAES OAEP using SHA-256 and MGF1 with SHA-256
     */
    HC_RSA_OAEP_256,
    
    /**
     RSAES- using PKCS1-v1-5
     */
    HC_RSA1_5
};

/**
 Provides content encryption algorithms specified in JWA specification
 */
typedef NS_ENUM(int, HCContentEncryptionAlgorithm) {
    
    /**
     Content encryption algorithm AES/CBC with 128 bit size and HMacSHA256 hashing algorithm.
     */
    HC_A128CBC_HS256,
    
    /**
     Content encryption algorithm AES/CBC with 192 bit size and HMacSHA384 hashing algorithm.
     */
    HC_A192CBC_HS384,
    
    /**
     Content encryption algorithm AES/CBC with 256 bit size and HMacSHA512 hashing algorithm.
     */
    HC_A256CBC_HS512,
    
    /**
     Content encryption algorithm AES-GCM with 128 bit size.
     */
    HC_A128GCM,
    
    /**
     Content encryption algorithm AES-GCM with 192 bit size.
     */
    HC_A192GCM,
    
    /**
     Content encryption algorithm AES-GCM with 256 bit size.
     */
    HC_A256GCM,
    
    /**
     Content encryption algorithm AES with PKCS7Padding.
     */
    HC_AES_CBC_PKCS7Padding
};


#endif /* IHCJweAlgorithms_h */
