/*
 Author:© 2017 Mastercard. Proprietary. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import "IHCDeviceInfoProvider.h"
#import "IHCDeviceInfo.h"

/**
 This method provides an interface to get all required information regarding device.
 */
@protocol IHCDeviceDomainService <NSObject>

/**
 This method provides an interface to initialize an object following to IHCDeviceDomainService protocol.

 @param deviceInfoProvider An object following to IHCDeviceInfoProvider protocol.

 @return An object following to IHCDeviceDomainService protocol.
 */
- (instancetype)initWithDeviceInfoProvider:(id <IHCDeviceInfoProvider>)deviceInfoProvider;

/**
 This method provides an interface to get all required information regarding device.

 @return An object following to IHCDeviceInfo protocol.
 */
- (id <IHCDeviceInfo>)getDeviceInfo;

/**
 This method provides an interface to get information regarding, whether a device is rooted or not.
 
 @return A boolean value explaining whether device is rooted or not.
 */
- (BOOL)isDeviceRooted;

/**
 This method provides an interface to get information regarding, whether a devide has secure lock functionality enabled or not.
 
 @return A boolean value explaining whether a devide has secure lock functionality enabled or not.
 */
- (BOOL)isDeviceSecureLockEnabled;

/**
 This method provides an interface to get information regarding, whether a devide has data network available or not.
 
 @return A boolean value explaining whether a devide has data network available or not.
 */
- (BOOL)isDataNetworkAvailable;

@end
