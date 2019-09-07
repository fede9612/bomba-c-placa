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

void iniciar(controlSemaforo * control, semaforo * sem) {
	iniciarYDetenerRojo(control, sem);
	iniciarYDetenerAmarilla(control, sem);
	iniciarYDetenerVerde(control, sem);
	iniciarYDetenerAmarilla(control, sem);
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
