/*
 * controlSemaforo.c
 *
 *  Created on: 4 sep. 2019
 *      Author: federico
 */

#include "controlSemaforo.h"
#include "semaforo.h"
#include "visualizarSemaforo.h"
#include "sapi.h"

void iniciar(controlSemaforo * control, semaforo * sem){
	control->estado = Rojo;
	control->ultimoCambio = 0;
	inicializar(sem);
}

void actualizar(controlSemaforo * control, semaforo * sem) {
	int tickActual = tickRead();
	int tiempoPasado = tickActual - control->ultimoCambio;

	switch (control->estado) {

	case Rojo: {
		if (tiempoPasado >= 7000) {
			control->estado = RojoAmarillo;
			apagarRoja(sem);
			prenderAmarillo(sem);
			control->ultimoCambio = tickActual;
		}
		break;
	}
	case RojoAmarillo : {
			if (tiempoPasado >= 3000) {
				control->estado = Verde;
				apagarAmarillo(sem);
				prenderVerde(sem);
				control->ultimoCambio = tickActual;
			}
			break;
	}
	case Verde : {
				if (tiempoPasado >= 7000) {
					control->estado = VerdeAmarillo;
					apagarVerde(sem);
					prenderAmarillo(sem);
					control->ultimoCambio = tickActual;
				}
				break;
	}
	case VerdeAmarillo : {
					if (tiempoPasado >= 3000) {
						control->estado = Rojo;
						apagarAmarillo(sem);
						prenderRoja(sem);
						control->ultimoCambio = tickActual;
					}
					break;
		}
	}

}

void iniciarYDetenerRojo(controlSemaforo * control, semaforo * sem) {
	inicializar(sem);
	estadoRoja(sem);
	delay(TiempoRojo);
	apagarRoja(sem);
	estadoRoja(sem);
}

void iniciarYDetenerAmarilla(controlSemaforo * control, semaforo * sem) {
	prenderAmarillo(sem);
	estadoAmarillo(sem);
	if (tickRead())
		delay(TiempoAmarillo);
	apagarAmarillo(sem);
	estadoAmarillo(sem);
}

void iniciarYDetenerVerde(controlSemaforo * control, semaforo * sem) {
	prenderVerde(sem);
	estadoVerde(sem);
	delay(TiempoVerde);
	apagarVerde(sem);
	estadoVerde(sem);
}
