/*
 * controlBoton.c
 *
 *  Created on: 14 sep. 2019
 *      Author: federico
 */

#include "visualizarSemaforo.h"
#include "controlBoton.h"
#include "controlBlinky.h"
#include "boton.h"
#include "sapi.h"

void inicializarBoton(controlBoton * control, boton * boton, botonHandler _funcionDown){
	control->estadoBoton = Up;
	control->ultimoCambioBoton = tickRead();
	boton->funcionDown = _funcionDown;
}

void actualizarBoton(controlBoton * control, boton * boton, controlBlinky * controlAmarillo,
					int tiempoA, controlBlinky * controlRojo, int tiempoR, int tiempoExtra){
	int tickActual = tickRead();
	int tiempoPasado = tickActual - control->ultimoCambioBoton;

	switch(control->estadoBoton){
		case Up : {
			if(gpioRead(TEC1) == 0){
				control->estadoBoton = Falling;
				control->ultimoCambioBoton = tickRead();
			}
			if(tiempoPasado >= tiempoA && gpioRead(LEDB)){
				controlAmarillo->estadoBlinky = Prendido;
			}
			if(tiempoPasado >= tiempoR && gpioRead(LEDB)){
				controlRojo->estadoBlinky = Prendido;
				boton->funcionDown();
				controlAmarillo->estadoBlinky = Apagado;
			}
			if(controlRojo->estadoBlinky == Prendido && tiempoPasado >= tiempoExtra){
				controlRojo->estadoBlinky = Apagado;
			}
			break;
		}
		case Falling : {
			if(tiempoPasado >= 40 && ((gpioRead(TEC1)) == 0)){
				control->estadoBoton = Down;
				control->ultimoCambioBoton = tickRead();
				controlAmarillo->estadoBlinky = Apagado;
				controlRojo->estadoBlinky = Apagado;
				boton->funcionDown();
			}
			break;
		}
		case Down : {
			if((gpioRead(TEC1)) == 1){
				control->estadoBoton = Rising;
				control->ultimoCambioBoton = tickRead();
			}
			break;
		}
		case Rising : {
			if(tiempoPasado >= 40 && ((gpioRead(TEC1)) == 1)){
				control->estadoBoton = Up;
				control->ultimoCambioBoton = tickRead();
				//apagarLed1();
			}
			break;
		}
	}
}
