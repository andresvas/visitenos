var exec = require('cordova/exec');

exports.authentication = function (success, error, userInfo, authorizationCode) {
    exec(success, error, 'WalletPlugin', 'AUTHENTICATION', [userInfo, authorizationCode]);
};

exports.isWalletRegistered = function (success, error, userInfo) {
    exec(success, error, 'WalletPlugin', 'IS_WALLET_REGISTERED', [userInfo]);
};

exports.registerWallet = function (success, error, userInfo) {
    exec(success, error, 'WalletPlugin', 'REGISTER_WALLET', [userInfo]);
};

exports.getTermsAndConditions = function (success, error) {
    exec(success, error, 'WalletPlugin', 'GET_TERMS_AND_CONDITIONS');
};

exports.runCheck = function (success, error) {
    exec(success, error, 'WalletPlugin', 'RUN_CHECK');
};

exports.acceptTnC = function (success, error, userInfo) {
    exec(success, error, 'WalletPlugin', 'ACCEPT_TNC', [userInfo]);
};

exports.getCardList = function (success, error, userInfo) {
    exec(success, error, 'WalletPlugin', 'GET_CARD_LIST', [userInfo]);
};

/**
 *
 * @param success
 * @param error
 * @param options - should be an object containing the parameters x,y,width and height. All optional
 */
exports.captureQrCode = function (success, error,options) {
    exec(success, error, 'WalletPlugin', 'CAPTURE_PAYMENT_QR', [options]);
};

exports.cancelCaptureQr = function (success, error) {
    exec(success, error, 'WalletPlugin', 'CANCEL_CAPTURE_QR');
};

/**
 *
 * @param success
 * @param error
 * @param options - should be an object containing the parameters cardId, cardType, installments, purchaseValue, tipValue. The 2 first are mandatory, and the other, optionals
 */
exports.qrValidate = function (success, error, jsonData) {
    exec(success, error, 'WalletPlugin', 'QR_VALIDATE', [jsonData]);
};

exports.qrPurchase = function (success, error, jsonData) {
    exec(success, error, 'WalletPlugin', 'QR_PURCHASE', [jsonData]);
};

exports.initMonitoringControl = function (success, error) {
    exec(success, error, 'WalletPlugin', 'INIT_MONITORING_CONTROL');
};

exports.openVisitUs = function (success, error,) {
    exec(success, error, 'WalletPlugin', 'OPEN_VISIT_US');
};
