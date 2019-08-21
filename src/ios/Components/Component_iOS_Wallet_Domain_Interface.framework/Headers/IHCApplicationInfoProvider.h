/*
 Author:© 2017 Mastercard. Proprietary. All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 This protocol provides an interface to provide required application related information.
 */
@protocol IHCApplicationInfoProvider <NSObject>

/**
 This method provides an interface to providea app-id of application.

 @return app-id of application.
 */
- (NSString *)appId;

/**
 This method provides an interface to provide name of application.

 @return name of application.
 */
- (NSString *)appName;

/**
 This method provides an interface to provide application version.

 @return application version.
 */
- (NSString *)appVersion;

/**
 This method provides an interface to provide bundle version of application.

 @return bundle version of application.
 */
- (NSString *)bundleVersion;

@end
