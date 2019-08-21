/*******************************************************************************
 * Copyright (c) 2016, MasterCard International Incorporated and/or its
 * affiliates. All rights reserved.
 *
 * TO THE EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS", WITHOUT
 * WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NON INFRINGEMENT. TO THE EXTENT PERMITTED BY LAW, IN NO EVENT SHALL
 * MASTERCARD OR ITS AFFILIATES BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *******************************************************************************/

#import <UIKit/UIKit.h>

//! Project version number for JOSE.
FOUNDATION_EXPORT double JOSEVersionNumber;

//! Project version string for JOSE.
FOUNDATION_EXPORT const unsigned char JOSEVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <JOSE/PublicHeader.h>

#import "MCJJOSEConstant.h"
#import "CommonUtils.h"
#import "MCJURLSafeBase64.h"
#import "MCJJOSEErrorConstants.h"

// Crypto Functions
#import "MCJSecretKeyProtocol.h"
#import "MCJAESKey.h"
#import "MCJKeyPairProtocol.h"
#import "MCJRSAKeyPair.h"
#import "MCJRSAKeyPairProtocol.h"
#import "MCJSecretKeyPair.h"
#import "MCJSecretKeyPairProtocol.h"
#import "MCJCryptoServiceProtocol.h"
#import "MCJCryptoService.h"

#import "MCJECDHKEKDerivationParameters.h"
#import "MCJCEKCryptoHandler.h"
#import "MCJECDHCEKCryptoHandler.h"
#import "MCJCEKData.h"
#import "MCJKEKDerivationParameters.h"
#import "MCJKeyEncryptionAlgorithmMapper.h"
#import "MCJKeyEncryptionAlgorithm.h"
#import "MCJAESHMACAlgo.h"
#import "MCJAADGenerator.h"
#import "MCJBaseContentCryptoHandler.h"
#import "MCJContentCryptoData.h"
#import "MCJContentCryptoHandler.h"
#import "MCJContentEncryptionAlgorithm.h"
#import "MCJContentEncryptionAlgorithmMapper.h"
#import "MCJEncryptedData.h"
#import "MCJAESHMacContentCryptoHandler.h"
#import "MCJAADGeneratorImpl.h"
#import "MCJJWEParameters.h"
#import "MCJJWEUtils.h"
#import "MCJJWEContext.h"
#import "MCJJWKECDHPublicKey.h"
#import "MCJJWKPublicKey.h"
#import "MCJJWKRSAPublicKey.h"
#import "MCJJWKServerPublicKey.h"

#import "MCJPBES2CEKCryptoHandler.h"
#import "MCJPBES2KEKDerivationParameters.h"

#import "MCJRSACEKCryptoHandler.h"
#import "MCJRSAKEKDerivationParameters.h"

// Constants
#import "MCJAESHMacConstants.h"
#import "MCJCharsetConstants.h"
#import "MCJCryptoConstants.h"
#import "MCJJWKConstants.h"

// Envelope
#import "MCJJWEEnvelope.h"
#import "MCJJWEFlattenedEnvelope.h"
#import "MCJRecipientInfo.h"
#import "MCJJWEInput.h"
#import "MCJJWEProducer.h"
#import "MCJJWEProducerImpl.h"

// Serializer
#import "MCJJWESerializerDeserializer.h"
