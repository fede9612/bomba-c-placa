/*
 * visualizarSemaforo.c
 *
 *  Created on: 7 sep. 2019
 *      Author: federico
 */

#include "visualizarSemaforo.h"
#include "sapi.h"

void estadoRoja(semaforo * sem) {
	if ((*sem).Rojo == 1) {
		gpioWrite(LED2, ON);
	} else {
		gpioWrite(LED2, OFF);
	}
}

void estadoVerde(semaforo * sem) {
	if ((*sem).Verde == 1) {
		gpioWrite(LED3, ON);
	} else {
		gpioWrite(LED3, OFF);
	}
}

void estadoAmarillo(semaforo * sem) {
	if ((*sem).Amarillo == 1) {
		gpioWrite(LED1, ON);
	} else {
		gpioWrite(LED1, OFF);
	}
}

void estadoSemaforo(semaforo * sem) {
	estadoRoja(sem);
	estadoAmarillo(sem);
	estadoVerde(sem);
}

