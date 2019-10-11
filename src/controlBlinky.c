/*
 * controlBlinky.c
 *
 *  Created on: 14 sep. 2019
 *      Author: federico
 */

#include "controlBlinky.h"
#include "sapi.h"

void iniciarBlinky(controlBlinky * control, gpioMap_t led, int tiempo){
	control->estadoBlinky = Apagado;
	control->led = led;
	control->tiempo = tiempo;
}

void prenderBlinky(controlBlinky * control){
	control->estadoBlinky = Prendido;
}

void apagarBlinky(controlBlinky * control){
	control->estadoBlinky = Apagado;
}

void actualizarBlinky(controlBlinky * control){

	switch(control->estadoBlinky){
		case Prendido : {
				gpioWrite(control->led, ON);
			break;
		}
		case Apagado : {
				gpioWrite(control->led, OFF);
			break;
		}
	}
}
