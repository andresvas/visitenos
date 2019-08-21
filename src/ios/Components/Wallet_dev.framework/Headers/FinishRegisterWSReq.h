//
//  FinishRegisterWSReq.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 3/19/19.
//  Copyright © 2019 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import "WSRequest.h"
#import "AcceptTnCWSReq.h"

NS_ASSUME_NONNULL_BEGIN

@interface FinishRegisterWSReq : WSRequest

/*!
 *  @discussion This property knows accept terms and conditions.
 */
@property (nonatomic, strong) AcceptTnCWSReq *acceptTnC;

/*!
 *  @discussion This method knows is constructor for this class with parameter:
 *  @param finishRegister provide wallet finish register web service request object.
 *  @return web service request object.
 */
- (WSRequest *)initWithFinishRegister:(FinishRegisterWSReq *)finishRegister;

@end

NS_ASSUME_NONNULL_END
