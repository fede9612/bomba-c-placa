/*
 * controlRemoto.c
 *
 *  Created on: 12 oct. 2019
 *      Author: federico
 */

#include "controlRemoto.h"
#include "sapi.h"
#include "UartConnector.h"
#include "bomba.h"
#include "model.h"

void bluetoothCommandReceived(void * model, uint8_t byte) {
	if(byte == 'p') {
		iniciarModel(model);
	}
	else if(byte == 'a') {
		detenerModel(model);
	}
}


void iniciarControlRemoto(ControlRemoto * controlRemoto){
	controlRemoto->estado = Deshabilitado;
}

void cambiarEstadoControlRemoto(ControlRemoto * controlRemoto){
	if(controlRemoto->estado == Habilitado){
		controlRemoto->estado = Deshabilitado;
	}else{
		controlRemoto->estado = Habilitado;
	}
}

void actualizarControlRemoto(ControlRemoto * controlRemoto, Bomba * bomba){
	if(bomba->estadoBomba == Apagada && controlRemoto->estado == Habilitado){
		controlRemoto->estado = Deshabilitado;
		gpioToggle(GPIO1);
	}
	if(controlRemoto->estado == Deshabilitado){
		gpioWrite(LED3, OFF);
	}
}

