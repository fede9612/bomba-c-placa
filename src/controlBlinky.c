/*
 * controlBlinky.c
 *
 *  Created on: 14 sep. 2019
 *      Author: federico
 */

#include "controlBlinky.h"
#include "sapi.h"

void iniciarBlinky(controlBlinky * control, gpioMap_t led){
	control->estadoBlinky = Apagado;
	control->ultimoCambioBlinky = tickRead();
	control->led = led;
}

void actualizarBlinky(controlBlinky * control){

	switch(control->estadoBlinky){
		case Prendido : {
				gpioWrite(control->led, ON);
				control->ultimoCambioBlinky = tickRead();
			break;
		}
		case Apagado : {
				gpioWrite(control->led, OFF);
				control->ultimoCambioBlinky = tickRead();
			break;
		}
	}
}
