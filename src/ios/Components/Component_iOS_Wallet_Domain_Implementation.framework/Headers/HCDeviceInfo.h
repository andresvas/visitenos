/*
 Author:© 2017 Mastercard. Proprietary. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <Component_iOS_Wallet_Domain_Interface/IHCDeviceInfo.h>

/**
 This class provides an implementation of IHCDeviceInfo protocol.
 */
@interface HCDeviceInfo : NSObject <IHCDeviceInfo>

/**
 This method provides an interface to initialize an instance of HCDeviceInfo.

 @param oem              OEM of device.
 @param name             Name of device.
 @param modelName        Model name of device.
 @param modelNumber      Model number of device.
 @param uniqueIdentifier Unique identifier of device.
 @param screenHeight     Screen's height of device.
 @param screenWidth      Screen's width of device.
 @param osName           Name of OS installed in device.
 @param osVersion        Version of OS installed in device.
 @param osAlias          Alias of OS installed in device.
 @param locale           Locale of device.

 @return An instance of HCDeviceInfo.
 */
- (instancetype)initWithOEM:(NSString *)oem
                       name:(NSString *)name
                  modelName:(NSString *)modelName
                modelNumber:(NSString *)modelNumber
           uniqueIdentifier:(NSString *)uniqueIdentifier
               screenHeight:(NSString *)screenHeight
                screenWidth:(NSString *)screenWidth
                     osName:(NSString *)osName
                  osVersion:(NSString *)osVersion
                    osAlias:(NSString *)osAlias
                  andLocale:(NSLocale *)locale;

@end
