//
//  ScanQRCodeViewController.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 2/27/18.
//  Copyright © 2018 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "QRCodeDataReqDto.h"
#import "IScanQRCode.h"

@interface ScanQRCodeViewController : UIViewController<AVCaptureMetadataOutputObjectsDelegate, IScanQRCode>

/*!
 *  @discussion This property knows capture session.
 */
@property (nonatomic, strong) AVCaptureSession *captureSession;
/*!
 *  @discussion This property knows video preview layer.
 */
@property (nonatomic, strong) AVCaptureVideoPreviewLayer *videoPreviewLayer;
/*!
 *  @discussion This property knows audio player.
 */
@property (nonatomic, strong) AVAudioPlayer *audioPlayer;

/*!
 *  @discussion This property knows capture device.
 */
@property (nonatomic, strong) AVCaptureDevice *captureDevice;
/*!
 *  @discussion This property knows input.
 */
@property (nonatomic, strong) AVCaptureDeviceInput *input;

/*!
 *  @discussion This property knows output.
 */
@property (nonatomic, strong) AVCaptureMetadataOutput *output;

/*!
 *  @discussion This method configure camera view for scan QR codes.
 *  @param scanQRCodeView provide view for configure.
 */
- (void)configureScanQRCodeView:(UIView *)scanQRCodeView;

/*!
 *  @discussion This method start camera session for capture QR codes.*/
- (void)startCameraSession;
/*!
 *  @discussion This method stop camera session.*/
- (void)stopCameraSession;

@end
