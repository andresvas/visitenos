/*
 Author:© 2017 Mastercard. Proprietary. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import "IHCJweEnvelope.h"
#import "IHCJweInput.h"

/**
 JWE Service provider interface, which create HCJweEnvelope to protect and extract content. This interface should be used in producer or sender side which expects to create HCJweEnvelope first.
 */
@protocol IHCJweCreater <NSObject>

/**
 Creates JweEnvelope to protect the content and includes necessary parameters.

 @param jweInput HCJweInput for creating envelope.
 @param error    On input, a pointer to variable for an NSError object. If an error occurs, this pointer is set to an NSError object containing information about the error. You may specify nil for this parameter if you do not want the error information.

 @return HCJweEnvelope containing the protected content.
 */
- (id <IHCJweEnvelope> _Nullable)createJWEEnvelope:(id <IHCJweInput> _Nonnull)jweInput
                               error:(NSError * _Nullable * _Nullable)error;

/**
 Extracts the content from JweEnvelope.

 @param envelope HCJweEnvelope object to be extracted.
 @param error    On input, a pointer to variable for an NSError object. If an error occurs, this pointer is set to an NSError object containing information about the error. You may specify nil for this parameter if you do not want the error information.

 @return NSData of actual data.
 */
- (NSData * _Nullable)extractContent:(id <IHCJweEnvelope> _Nonnull)envelope
                     error:(NSError * _Nullable * _Nullable)error;

@end
