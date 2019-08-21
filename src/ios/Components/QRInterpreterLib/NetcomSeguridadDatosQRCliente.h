//
//  NetcomSeguridadDatosQRCliente.h
//  NetcomSeguridadDatosQRCliente
//
//  Created by NetCom SAS on 12/02/15.
//  Copyright (c) 2015 NetCom SAS. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NetcomSeguridadDatosQRCliente : NSObject

// Metodo encargado de desencriptar un dato
- (NSString*)desencriptar:(NSString*)datoDesencriptar;

// Metodo encargado de decifrar llave.
- (NSString*)decifrarLlave:(NSString*)llaveCifrada;

@end
