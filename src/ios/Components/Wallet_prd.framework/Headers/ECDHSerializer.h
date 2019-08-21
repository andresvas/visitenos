//
//  ECDHSerializer.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 2/28/18.
//  Copyright © 2018 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import "JOSESerializer.h"

@interface ECDHSerializer : JOSESerializer

/*!
 *  @discussion This method knows is constructor for this class with parameter:
 *  @param jwk provide data serialized of java web key.
 */
- (instancetype)initWithJWK:(id)jwk;

@end
