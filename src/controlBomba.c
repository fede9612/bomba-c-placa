/*
 * controlSemaforo.c
 *
 *  Created on: 4 sep. 2019
 *      Author: federico
 */

#include "../inc/controlBomba.h"

#include "bomba.h"
#include "visualizarSemaforo.h"
#include "sapi.h"

void iniciar(controlBomba * control, Bomba * bomba){
	bombaApagar(bomba);
	control->ultimoCambio = 0;
}

void actualizar(controlBomba * control, Bomba * bomba, controlBlinky * controlAmarillo,  controlBlinky * controlRojo) {
	int tickActual = tickRead();
	int tiempoPasado = tickActual - control->ultimoCambio;

	switch (bomba->estadoBomba) {

	case Prendida: {
			bombaMitad(bomba);
			control->ultimoCambio = tickActual;
		break;
	}
	case Mitad : {
			if(tiempoPasado >= controlAmarillo->tiempo){
				bombaLlena(bomba);
				prenderBlinky(controlAmarillo);
				control->ultimoCambio = tickActual;
			}
			break;
	}
	case Llena : {
				if (tiempoPasado >= controlRojo->tiempo) {
					bombaApagar(bomba);
					prenderBlinky(controlRojo);
					apagarBlinky(controlAmarillo);
					control->ultimoCambio = tickActual;
				}
				break;
	}
	case Apagada : {
				apagarBlinky(controlRojo);
				apagarBlinky(controlAmarillo);
				control->ultimoCambio = tickActual;
				break;
		}
	}

}

