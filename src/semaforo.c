/*
 * semaforo.c
 *
 *  Created on: 2 sep. 2019
 *      Author: federico
 */

#include "semaforo.h"
#include "sapi.h"

void inicializar(semaforo * sem){
	sem->Rojo = 1;
	(*sem).Amarillo = 0;
	(*sem).Verde = 0;
}

void prenderRoja(semaforo * sem){
	(*sem).Rojo = 1;
}

void apagarRoja(semaforo * sem){
	(*sem).Rojo = 0;
}

void prenderVerde(semaforo * sem){
	(*sem).Verde = 1;
}

void apagarVerde(semaforo * sem){
	(*sem).Verde = 0;
}

void prenderAmarillo(semaforo * sem){
	(*sem).Amarillo = 1;
}

void apagarAmarillo(semaforo * sem){
	(*sem).Amarillo = 0;
}

