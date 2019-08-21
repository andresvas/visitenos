
/**
 Author:© 2017 Mastercard. Proprietary. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <Component_iOS_Crypto_Interface/Component_iOS_Crypto_Interface.h>
#import "HCAESKey.h"

/**
 This class provides an implementation of IHCSymmetricKeyGenerator.
 This class can be used for generating AES Key. Only 128, 256, 512 key sizes are supported.
 */
@interface HCAESKeyGenerator : NSObject <IHCSymmetricKeyGenerator>

@end
