//
//  WalletStatusResDto.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 4/11/18.
//  Copyright © 2018 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WalletStatusResDto : NSObject

/*!
 *  @discussion This property knows registered.
 */
@property (nonatomic) BOOL registered;
/*!
 *  @discussion This property knows registered.
 */
@property (nonatomic) BOOL preRegistered;
/*!
 *  @discussion This property knows status.
 */
@property (nonatomic, strong) NSString *status;

/*!
 *  @discussion This method knows transform this class to response for DTO.
 *  @param response provide data web service response object.
 *  @return wallet status response data transfer object.
 */
+ (WalletStatusResDto *)mapResponseToDTO:(id)response;

@end
