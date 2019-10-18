/*
 * controlBoton.c
 *
 *  Created on: 14 sep. 2019
 *      Author: federico
 */

#include "controlBoton.h"
#include "controlBlinky.h"
#include "controlRemoto.h"
#include "boton.h"
#include "bomba.h"
#include "sapi.h"

void siElBotonFuePresionado(int tiempoPasado, controlBoton * control, boton * boton, Bomba * bomba){
	if(tiempoPasado >= 40 && ((gpioRead(TEC1)) == 0)){
		control->estadoBoton = Down;
		control->ultimoCambioBoton = tickRead();
		bombaPrender(bomba);
		boton->funcionDown();
	}
}

void inicializarBoton(controlBoton * control, boton * boton, botonHandler _funcionDown){
	control->estadoBoton = Up;
	control->ultimoCambioBoton = tickRead();
	boton->funcionDown = _funcionDown;
}

void actualizarBoton(controlBoton * control, boton * boton, Bomba * bomba, ControlRemoto * controlRemoto){
	int tickActual = tickRead();
	int tiempoPasado = tickActual - control->ultimoCambioBoton;

	if(bomba->estadoBomba == Apagada && gpioRead(LEDB)){
		boton->funcionDown();
	}

	switch(control->estadoBoton){
		case Up : {
			if(gpioRead(TEC1) == 0){
				control->estadoBoton = Falling;
				control->ultimoCambioBoton = tickRead();
			}
			break;
		}
		case Falling : {
			siElBotonFuePresionado(tiempoPasado, control, boton, bomba);
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


