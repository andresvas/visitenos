/*
 Author:© 2017 Mastercard. Proprietary. All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 This protocol provides an interface to define required properties of a device.
 */
@protocol IHCDeviceInfo <NSObject>

/**
 This method provides an interface to define oem of device.
 */
@property (nonatomic, readonly) NSString *deviceOEM;

/**
 This method provides an interface to define name of device.
 */
@property (nonatomic, readonly) NSString *deviceName;

/**
 This method provides an interface to define model name of device.
 */
@property (nonatomic, readonly) NSString *modelName;

/**
 This method provides an interface to define model number of device.
 */
@property (nonatomic, readonly) NSString *modelNumber;

/**
 This method provides an interface to define unique identifier of device.
 */
@property (nonatomic, readonly) NSString *deviceUniqueIdentifier;

/**
 This method provides an interface to define screen's height of device.
 */
@property (nonatomic, readonly) NSString *screenHeight;

/**
 This method provides an interface to define screen's width of device.
 */
@property (nonatomic, readonly) NSString *screenWidth;

/**
 This method provides an interface to define name of OS installed in device.
 */
@property (nonatomic, readonly) NSString *osName;

/**
 This method provides an interface to define version of OS installed in device.
 */
@property (nonatomic, readonly) NSString *osVersion;

/**
 This method provides an interface to define alias of OS installed in device.
 */
@property (nonatomic, readonly) NSString *osAlias;

/**
 This method provides an interface to define locale of device.
 */
@property (nonatomic, readonly) NSLocale *locale;

@end
