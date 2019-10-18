/*
 * controlBomba.h
 *
 *  Created on: 4 sep. 2019
 *      Author: federico
 */

#ifndef CONTROLBOMBA_H_
#define CONTROLBOMBA_H_

#include "bomba.h"
#include "controlBlinky.h"

typedef struct {
	int estado;
	int ultimoCambio;
}controlBomba;

void actualizarBomba(controlBomba * control, Bomba * sem, controlBlinky * controlAmarillo,  controlBlinky * controlRojo);
void iniciarBomba(controlBomba * control, Bomba * sem);

#endif
