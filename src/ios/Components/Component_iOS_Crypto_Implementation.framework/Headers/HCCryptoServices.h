
/**
 Author:© 2017 Mastercard. Proprietary. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <Component_iOS_Crypto_Interface/Component_iOS_Crypto_Interface.h>

/**
 Provides default implementation of the crypto based service. The crypto based services are those services which encodes and decodes the data while communicating with server in order to secure the data. A developer should inherit from this class in order to write their own service.
 */
@interface HCCryptoServices : NSObject <IHCCryptoServices>

@end
