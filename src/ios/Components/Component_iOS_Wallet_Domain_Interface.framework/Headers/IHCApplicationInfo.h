/*
 Author:© 2017 Mastercard. Proprietary. All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 This protocol provides an interface to define required properties of an application.
 */
@protocol IHCApplicationInfo <NSObject>

/**
 This property provides an interface to define app-id of an application.
 */
@property (nonatomic, readonly) NSString *appId;

/**
 This property provides an interface to define application name.
 */
@property (nonatomic, readonly) NSString *appName;

/**
 This property provides an interface to define application version.
 */
@property (nonatomic, readonly) NSString *appVersion;

/**
 This property provides an interface to define bundle version.
 */
@property (nonatomic, readonly) NSString *bundleVersion;

@end
