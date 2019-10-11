/*
 * controlBoton.c
 *
 *  Created on: 14 sep. 2019
 *      Author: federico
 */

#include "visualizarSemaforo.h"
#include "AppModel.h"
#include "controlBoton.h"
#include "controlBlinky.h"
#include "boton.h"
#include "bomba.h"
#include "sapi.h"

void inicializarBoton(controlBoton * control, boton * boton, botonHandler _funcionDown){
	control->estadoBoton = Up;
	control->ultimoCambioBoton = tickRead();
	boton->funcionDown = _funcionDown;
	control->bluetooth = 0;
}

void actualizarBoton(controlBoton * control, boton * boton, AppModel * model, Bomba * bomba){
	int tickActual = tickRead();
	int tiempoPasado = tickActual - control->ultimoCambioBoton;

//	if(controlRojo->estadoBlinky == Prendido && tiempoPasado >= tiempoExtra){
//		controlRojo->estadoBlinky = Apagado;
//	}

	if(bomba->estadoBomba == Apagada && gpioRead(LEDB)){
		boton->funcionDown();
		appModel_disable(model);
	}

	switch(control->estadoBoton){
		case Up : {
			if(gpioRead(TEC1) == 0){
				control->estadoBoton = Falling;
				control->ultimoCambioBoton = tickRead();
			}
			if(gpioRead(LED3) && !gpioRead(LEDB)){
				bombaPrender(bomba);
				boton->funcionDown();
				control->bluetooth = 1;
				control->ultimoCambioBoton = tickRead();
			}
			if(!gpioRead(LED3) && gpioRead(LEDB) && control->bluetooth == 1){
				bombaApagar(bomba);
				boton->funcionDown();
				control->bluetooth = 0;
				control->ultimoCambioBoton = tickRead();
			}
			break;
		}
		case Falling : {
			if(tiempoPasado >= 40 && ((gpioRead(TEC1)) == 0)){
				control->estadoBoton = Down;
				control->ultimoCambioBoton = tickRead();
				bombaPrender(bomba);
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
