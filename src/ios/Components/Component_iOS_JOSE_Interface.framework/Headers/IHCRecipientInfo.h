/*
 Author:© 2017 Mastercard. Proprietary. All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 Denotes the information pertaining to the recipient. This is a composite part of the JweEnvelope.
 */
@protocol IHCRecipientInfo <NSObject>

/**
 This member must be present and contain the value JWE Per-Recipient Unprotected Header when the JWE Per-Recipient Unprotected Header value is non-empty; otherwise, it must be absent. This value is represented as an unencoded JSON object, rather than as a string.  These Header Parameter values are not integrity protected.
 */
@property (nonatomic, readwrite, nullable) NSDictionary *header;

/**
 This member must be present and contain the value BASE64URL(JWE Encrypted Key) when the JWE Encrypted Key value is non-empty; otherwise, it must be absent.
 */
@property (nonatomic, readwrite, nullable) NSData *encrypted_key;

@end
