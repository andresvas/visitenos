//
//  PBES2Serializer.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 3/2/18.
//  Copyright © 2018 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import "JOSESerializer.h"

@interface PBES2Serializer : JOSESerializer

/*!
 *  @discussion This method knows is constructor for this class with parameters:
 *  @param pin provide data serialized of pin.
 *  @param salt provide data serialized of salt.
 */
- (instancetype)initWithPIN:(NSData *)pin andSalt:(NSData *)salt;

@end
