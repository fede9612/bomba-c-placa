/*
 * controlRemoto.h
 *
 *  Created on: 12 oct. 2019
 *      Author: federico
 */

#ifndef PROGRAMS_BLINKY_INC_CONTROLREMOTO_H_
#define PROGRAMS_BLINKY_INC_CONTROLREMOTO_H_

#include "UartConnector.h"
#include "bomba.h"

typedef struct{
	int estado;

}ControlRemoto;
enum{
	Habilitado, Deshabilitado
};

void cambiarEstadoControlRemoto(ControlRemoto * controlRemoto);
void iniciarControlRemoto(ControlRemoto * controlRemoto);
void actualizarControlRemoto(ControlRemoto * controlRemoto, Bomba * bomba);
void bluetoothCommandReceived(void * model, uint8_t byte);

#endif /* PROGRAMS_BLINKY_INC_CONTROLREMOTO_H_ */
