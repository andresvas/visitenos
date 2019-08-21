/*
 Author:© 2017 Mastercard. Proprietary. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <Component_iOS_Wallet_Domain_Interface/IHCApplicationInfo.h>

/**
 This class provides an implementation of IHCApplicationInfo protocol.
 */
@interface HCApplicationInfo : NSObject <IHCApplicationInfo>

/**
 This method provides an interface to initialize an instance of HCApplicationInfo

 @param appId         app-id of application.
 @param appName       name of application.
 @param appVersion    version of application.
 @param bundleVersion bundler version of application.

 @return An instance of HCApplicationInfo.
 */
- (instancetype)initWithAppId:(NSString *)appId
                      appName:(NSString *)appName
                   appVersion:(NSString *)appVersion
             andBundleVersion:(NSString *)bundleVersion;

@end
