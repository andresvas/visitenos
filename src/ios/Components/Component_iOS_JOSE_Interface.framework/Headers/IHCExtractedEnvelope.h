/*
 Author:© 2017 Mastercard. Proprietary. All rights reserved.
 */

#import <Foundation/Foundation.h>

@protocol IHCExtractedEnvelope <NSObject>
/**
 Extracted Content Data from JWE Envelope.
 */
@property (nonatomic, readwrite, nullable) NSData *extractedContentData;

/**
 Represents un-protected headers from JWE Envelope.
 */
@property (nonatomic, readwrite, nullable) NSDictionary *unprotectedHeaders;


/**
 Represents protected headers from JWE Envelope.
 */
@property (nonatomic, readwrite, nullable) NSDictionary *protectedHeaders;

@end
