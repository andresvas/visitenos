//
//  IHCSerialization.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 4/9/18.
//  Copyright © 2018 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 This protocol provides an interface to serialize/deserialize an object.
 */
@protocol IHCSerialization <NSObject>

/**
 This method serialize an object to NSData.
 
 *  @param object An object to be serialized.
 *  @param error If any error occur during serialization, it is returned via this reference.
 
 *  @return Serialized object.
 */
- (nullable NSData *)serializeObject:(nonnull id)object error:(NSError * _Nullable)error;

/**
 This method deserialize NSData to object.
 
 *  @param data NSData to be deserialize.
 *  @param error If any error occur during deserialization, it is returned via this reference.
 
 *  @return deserialized Object.
 */
- (nullable id)deserializeData:(nonnull NSData *)data error:(NSError * _Nullable)error;

@end
