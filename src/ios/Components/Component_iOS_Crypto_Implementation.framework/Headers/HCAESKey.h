
/**
 Author:© 2017 Mastercard. Proprietary. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <Component_iOS_Crypto_Interface/Component_iOS_Crypto_Interface.h>

/**
 This class provides an implementation of IHCSymmetricKey.
 This class can be used as AES key.
 */
@interface HCAESKey : NSObject <IHCSymmetricKey>


/**
 This method provide an instance of HCAESKey.

 @param keyData Byte value of key.
 @param keySize Size of key.

 @return Instance of HCAESKey.
 */
- (instancetype)initWithData:(NSData *)keyData
                     andSize:(NSUInteger)keySize;

@end
