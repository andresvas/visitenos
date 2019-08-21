//
//  RuncheckResDto.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 3/16/18.
//  Copyright © 2018 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RuncheckResDto : NSObject

/*!
 *  @discussion This method knows is constructor for this class.
 */
+ (instancetype)sharedInstance;

/*!
 *  @discussion This property knows device OEM.
 */
@property (nonatomic, strong) NSString *deviceOEM;
/*!
 *  @discussion This property knows device name.
 */
@property (nonatomic, strong) NSString *deviceName;
/*!
 *  @discussion This property knows model name.
 */
@property (nonatomic, strong) NSString *modelName;
/*!
 *  @discussion This property knows model number.
 */
@property (nonatomic, strong) NSString *modelNumber;
/*!
 *  @discussion This property knows device unique identifier.
 */
@property (nonatomic, strong) NSString *deviceUniqueIdentifier;
/*!
 *  @discussion This property knows screen height.
 */
@property (nonatomic, strong) NSString *screenHeight;
/*!
 *  @discussion This property knows screen width.
 */
@property (nonatomic, strong) NSString *screenWidth;
/*!
 *  @discussion This property knows screen width.
 */
@property (nonatomic, strong) NSString *osName;
/*!
 *  @discussion This property knows os name.
 */
@property (nonatomic, strong) NSString *osVersion;
/*!
 *  @discussion This property knows os alias.
 */
@property (nonatomic, strong) NSString *osAlias;
/*!
 *  @discussion This property knows locale.
 */
@property (nonatomic, strong) NSLocale *locale;
/*!
 *  @discussion This property knows is device rooted.
 */
@property (nonatomic) BOOL isDeviceRooted;
/*!
 *  @discussion This property knows is device secure lock enabled.
 */
@property (nonatomic) BOOL isDeviceSecureLockEnabled;
/*!
 *  @discussion This property knows is data network available.
 */
@property (nonatomic) BOOL isDataNetworkAvailable;

@end
