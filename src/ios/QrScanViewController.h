#import <Wallet/Wallet.h>


@protocol QrScanViewControllerDelegate <NSObject>
- (void)onQrCodeDetected:(QRCodeDataReqDto *)qrData;
- (void)onStatusResponse:(StatusResDto *)data;
//- (void)onCanceled;
@end

@interface QrScanViewController : ScanQRCodeViewController

@property (weak, nonatomic) NSObject<QrScanViewControllerDelegate>* delegate;

@end

