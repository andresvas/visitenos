#import "QrScanViewController.h"
@implementation QrScanViewController

#pragma Mark Scan QR Code Interface Methods
- (void)getEncryptedQRCode:(QRCodeDataReqDto * )qrCodeData{
    if(_delegate != (id)[NSNull null]){
        [_delegate onQrCodeDetected:qrCodeData];
        [self dismissViewControllerAnimated:NO completion:NULL];
    }
}

- (void)getStatusResponse:(StatusResDto * )status {
    if(_delegate != (id)[NSNull null]){
        [_delegate onStatusResponse:status];
        [self dismissViewControllerAnimated:NO completion:NULL];
    }
}
@end
