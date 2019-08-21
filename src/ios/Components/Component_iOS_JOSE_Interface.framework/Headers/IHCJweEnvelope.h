/*
 Author:© 2017 Mastercard. Proprietary. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import "IHCRecipientInfo.h"

/**
 Represents JWE Envelope
 */
@protocol IHCJweEnvelope <NSObject>

/**
 Base64 encoded headers.
 */
@property (nonatomic, readwrite, nonnull) NSString *protectedHeaders;

/**
 Base64 encoded headers value.
 */
@property (nonatomic, readwrite, nullable) NSDictionary *unProtectedHeaders;

/**
 Initialization Vector.
 */
@property (nonatomic, readwrite, nullable) NSData *iv;

/**
 Additional Authentication Data.
 */
@property (nonatomic, readwrite, nullable) NSString *aad;

/**
 Cipher Text.
 */
@property (nonatomic, readwrite, nonnull) NSData *cipherText;

/**
 Authentication tag.
 */
@property (nonatomic, readwrite, nonnull) NSData *tag;

/**
 Recipient Information.
 */
@property (nonatomic, readwrite, nonnull) NSArray<id <IHCRecipientInfo>> *recipients;


@end
