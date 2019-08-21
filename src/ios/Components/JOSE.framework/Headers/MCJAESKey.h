//
//  MCJAESKey.h
//  JOSE
//
//  Created by Malkan, Marmik on 5/9/17.
//  Copyright © 2017 MasterCard. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MCJSecretKeyProtocol.h"

@interface MCJAESKey : NSObject<MCJSecretKeyProtocol>

- (instancetype)initWithData:(NSData *)data keySize:(NSUInteger)size;

@end
