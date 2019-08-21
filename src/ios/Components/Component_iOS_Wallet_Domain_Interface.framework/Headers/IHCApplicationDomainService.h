/*
 Author:© 2017 Mastercard. Proprietary. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import "IHCApplicationInfoProvider.h"
#import "IHCApplicationInfo.h"

/**
 This protocol provides an interface to get application related info.
 */
@protocol IHCApplicationDomainService <NSObject>

/**
 This method provides an interface to initialize an object following to IHCApplicationDomainService protocol.

 @param applicationInfoProvider An object following to IHCApplicationInfoProvider protocol.

 @return An object following to IHCApplicationDomainService protocol.
 */
- (instancetype)initWithApplicationInfoProvider:(id <IHCApplicationInfoProvider>)applicationInfoProvider;

/**
 This method provides an interface to get an object following to IHCApplicationInfo protocol.

 @return An object following to IHCApplicationInfo protocol.
 */
- (id <IHCApplicationInfo>)getApplicationInfo;

@end
