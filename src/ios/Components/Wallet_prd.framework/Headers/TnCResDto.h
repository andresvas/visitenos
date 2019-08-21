//
//  TnCResDto.h
//  Wallet
//
//  Created by CAPGEMINI COLOMBIA S.A.S on 4/11/18.
//  Copyright © 2018 CAPGEMINI COLOMBIA S.A.S. All rights reserved.
//

#import "ResponseDto.h"

@interface TnCResDto : ResponseDto

/*!
 *  @discussion This property knows version.
 */
@property (nonatomic, strong) NSString *version;
/*!
 *  @discussion This property knows url.
 */
@property (nonatomic, strong) NSString *url;
/*!
 *  @discussion This property knows legal doc type.
 */
@property (nonatomic, strong) NSString *legalDocType;
/*!
 *  @discussion This property knows content.
 */
@property (nonatomic, strong) NSString *content;

/*!
 *  @discussion This method knows transform this class to response for DTO.
 *  @param response provide data web service response object.
 *  @return terms and conditions response data transfer object.
 */
+ (TnCResDto *)mapResponseToDTO:(id)response;
/*!
 *  @discussion This method knows transform this class to response for status.
 *  @param status provide data web service response object.
 *  @return terms and conditions response data transfer object.
 */
+ (TnCResDto *)mapStatusResToDTO:(id)status;

@end
