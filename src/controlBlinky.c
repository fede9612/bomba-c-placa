/*
 * controlBlinky.c
 *
 *  Created on: 14 sep. 2019
 *      Author: federico
 */

#include "controlBlinky.h"
#include "sapi.h"

void iniciarBlinky(controlBlinky * control, gpioMap_t led){
	control->estadoBlinky = Prendido;
	control->ultimoCambioBlinky = tickRead();
	control->led = led;
}

void actualizarBlinky(controlBlinky * control, int tiempo){
	int tickActual = tickRead();
	int tiempoPasado = tickActual - control->ultimoCambioBlinky;

	switch(control->estadoBlinky){
		case Prendido : {
			if(tiempoPasado >= tiempo){
				gpioWrite(control->led, OFF);
				control->ultimoCambioBlinky = tickRead();
				control->estadoBlinky = Apagado;
			}
			break;
		}
		case Apagado : {
			if(tiempoPasado >= tiempo){
				gpioWrite(control->led, ON);
				control->ultimoCambioBlinky = tickRead();
				control->estadoBlinky = Prendido;
			}
			break;
		}
	}
}
