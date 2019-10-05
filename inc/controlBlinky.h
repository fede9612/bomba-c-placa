/*
 * controlBlinky.h
 *
 *  Created on: 14 sep. 2019
 *      Author: federico
 */

#ifndef PROGRAMS_BLINKY_INC_CONTROLBLINKY_H_
#define PROGRAMS_BLINKY_INC_CONTROLBLINKY_H_

#include "sapi.h"

enum estadoBlinky{
	Prendido, Apagado
};

typedef struct {
	int estadoBlinky;
	int ultimoCambioBlinky;
	gpioMap_t led;
}controlBlinky;



void actualizarBlinky(controlBlinky * control);
void iniciarBlinky(controlBlinky * control, gpioMap_t led);

#endif /* PROGRAMS_BLINKY_INC_CONTROLBLINKY_H_ */
