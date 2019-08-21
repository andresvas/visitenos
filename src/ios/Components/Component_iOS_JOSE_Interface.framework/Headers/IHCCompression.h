/*
 Author:© 2017 Mastercard. Proprietary. All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 Applies compression algorithm to the Plaintext before   encryption
 */
@protocol IHCCompression <NSObject>

/**
 Compress the plain text.

 @param plainText Encoded text.
 @param error     On input, a pointer to variable for an NSError object. If an error occurs, this pointer is set to an NSError object containing information about the error. You may specify nil for this parameter if you do not want the error information.

 @return Compressed plain data.
 */
- (NSData *)compressWithPlainText:(NSData *)plainText
                            error:(NSError **)error;

/**
 Decompress the given compressed data.

 @param compressedData Encoded text.
 @param error          On input, a pointer to variable for an NSError object. If an error occurs, this pointer is set to an NSError object containing information about the error. You may specify nil for this parameter if you do not want the error information.

 @return Compressed plain data.
 */
- (NSData *)decompressWithCompressedData:(NSData *)compressedData
                                   error:(NSError **)error;

@end
