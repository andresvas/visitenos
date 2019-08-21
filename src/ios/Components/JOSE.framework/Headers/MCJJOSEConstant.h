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

#ifndef JOSEConstant_h
#define JOSEConstant_h

/**
 Here constants represents the error code generated when any error occurs in JOSE toolkit.
 */
typedef NS_ENUM(int, JOSEErrorTypes) {
    
    /** Any data found in JOSE envelope object is invalid. */
    JOSEInvalidDataError = 1,
    
    /** JOSE Response envelope is invalid. */
    JOSEBadResponseError = 2,
    
    /** JSON string of JOSE envelope is invalid. */
    JOSEBadJSONError = 3,
    
    /** JOSE envelope is invalid or nil. */
    JOSEModelIsInvalidError = 4,
    
    /** Any input is nil. */
    JOSENilInputError = 5,
    
    /** Algorithm is not found or mismatch. */
    JOSEInvalidAlgorithmError = 6,
    
    /** Shared secret key is nil. */
    JOSESharedSecretNilError = 7,
    
    /** CEK crypto handler is nil. */
    JOSECEKCryptoHandlerNilError = 8,
    
    /** Content crypto handler is nil. */
    JOSEContentCryptoHandlerNilError = 9,
    
    /** Key encryption algorithm is not supported. */
    JOSEKeyEncryptionAlgorithmNotSupported = 10,
    
    /** Content encryption algorithm is not supported. */
    JOSEContentEncryptionAlgorithmNotSupported = 11,
    
    /** Private key is nil. */
    JOSEPrivateKeyNilError = 12,
    
    /** Ephemaral key is nil. */
    JOSEEpkNilError = 13,
    
    /** Content integrity check failed. */
    JOSEContentIntegrityCheckFailedError = 14,
    
    /** Wrapping the content failed. */
    JOSEWrapSymmetricKeyFailedError = 15,
    
    /** UnWrapping the content failed. */
    JOSEUnWrapSymmetricKeyFailedError = 16,
    
    /** Invalid KDF input. */
    JOSEInvalidKDFInputError = 17,
    
    /** Invalid KDF output. */
    JOSEInvalidKDFOutputError = 18,
    
    /** Invalid wrap symmetric key. */
    JOSEInvalidWrapSymmetricKeyError = 19,
    
    /** Invalid pin block. */
    JOSEInvalidPinBlockError = 20,
    
    /** Invalid salt. */
    JOSEInvalidSaltError = 21,
    
    /** Invalid count. */
    JOSEInvalidIterationCountError = 22,
    
    /** Invalid protected header. */
    JOSEInvalidProtectedHeaderError = 23,
    
    /** Invalid unwrap symmetric key. */
    JOSEInvalidUnWrapSymmetricKeyError = 24,
    
    /** Shared Secret Key generation failed. */
    JOSESharedSecretKeyGenerationError = 25
};

#endif /* JOSEConstant_h */
