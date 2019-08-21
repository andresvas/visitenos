//
//  CardResDto.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 4/12/18.
//  Copyright © 2018 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CardResDto : NSObject

/*!
 *  @discussion This property knows was card id.
 */
@property (nonatomic, strong) NSString *cardId;
/*!
 *  @discussion This property knows was card status.
 */
@property (nonatomic, strong) NSString *cardStatus;
/*!
 *  @discussion This property knows was card image.
 */
@property (nonatomic, strong) NSString *cardImage;
/*!
 *  @discussion This property knows was card number.
 */
@property (nonatomic, strong) NSString *cardNumber;
/*!
 *  @discussion This property knows was card type.
 */
@property (nonatomic, strong) NSString *cardType;
/*!
 *  @discussion This property knows was account type.
 */
@property (nonatomic, strong) NSString *accountType;
/*!
 *  @discussion This property knows was available balance.
 */
@property (nonatomic, strong) NSDecimalNumber *availableBalance;
/*!
 *  @discussion This property knows was franchise.
 */
@property (nonatomic, strong) NSString *franchise;
/*!
 *  @discussion This property knows was preferred.
 */
@property (nonatomic, strong) NSString *preferred;
/*!
 *  @discussion This property knows hidden.
 */
@property (nonatomic) BOOL hidden;

/*!
 *  @discussion This method knows transform this class to response for DTO.
 *  @param response provide data web service response object.
 *  @return card response data transfer object.
 */
+ (CardResDto *)mapResponseToDTO:(id)response;

@end
