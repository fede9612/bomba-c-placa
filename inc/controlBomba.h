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

#define TiempoRojo 7000
#define TiempoAmarillo 3000
#define TiempoVerde 7000


typedef struct {
	int estado;
	int ultimoCambio;
}controlBomba;

void actualizar(controlBomba * control, Bomba * sem, controlBlinky * controlAmarillo,  controlBlinky * controlRojo);
void iniciar(controlBomba * control, Bomba * sem);

#endif
