/*
 Author:© 2017 Mastercard. Proprietary. All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 This protocol provides an interface to provide all required info of device.
 */
@protocol IHCDeviceInfoProvider <NSObject>

/**
 This method provides an interface to provide oem of device.

 @return oem of device.
 */
- (NSString *)deviceOEM;

/**
 This method provides an interface to provide name of device.

 @return name of device.
 */
- (NSString *)deviceName;

/**
 This method provides an interface to provide name of model.

 @return name of model.
 */
- (NSString *)modelName;

/**
 This method provides an interface to provide model number of device.

 @return model number of device.
 */
- (NSString *)modelNumber;

/**
 This method provides an interface to provide unique identifier of device.

 @return unique identifier of device.
 */
- (NSString *)deviceUniqueIdentifier;

/**
 This method provides an interface to provide screen's height of device.

 @return screen's height of device.
 */
- (NSString *)screenHeight;

/**
 This method provides an interface to provide screen's width of device.
 
 @return screen's width of device.
 */
- (NSString *)screenWidth;

/**
 This method provides an interface to provide locale of device.

 @return locale of device
 */
- (NSLocale *)locale;

/**
 This method provides an interface to provide name of os installed in device

 @return name of os installed in device.
 */
- (NSString *)osName;

/**
 This method provides an interface to provide version of os installed in device
 
 @return version of os installed in device.
 */
- (NSString *)osVersion;

/**
 This method provides an interface to provide alias of os installed in device
 
 @return alias of os installed in device.
 */
- (NSString *)osAlias;

/**
 This method provides an interface to provide information regarding, whether a device is rooted or not.

 @return A boolean value explaining whether device is rooted or not.
 */
- (BOOL)isDeviceRooted;

/**
 This method provides an interface to provide information regarding, whether a devide has secure lock functionality enabled or not.

 @return A boolean value explaining whether a devide has secure lock functionality enabled or not.
 */
- (BOOL)isDeviceSecureLockEnabled;

/**
 This method provides an interface to provide information regarding, whether a devide has data network available or not.
 
 @return A boolean value explaining whether a devide has data network available or not.
 */
- (BOOL)isDataNetworkAvailable;

@end
