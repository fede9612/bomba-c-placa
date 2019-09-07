/*
 * semaforo.h
 *
 *  Created on: 31 ago. 2019
 *      Author: federico
 */

#ifndef SEMAFORO_H_
#define SEMAFORO_H_

#include <string.h>
#include <unistd.h>


typedef struct {
	int Rojo;
	int Amarillo;
	int Verde;
}semaforo;

void inicializar(semaforo * sem);
void prenderRoja(semaforo * sem);
void prenderVerde(semaforo * sem);
void prenderAmarillo(semaforo * sem);
void apagarRoja(semaforo * sem);
void apagarVerde(semaforo * sem);
void apagarAmarillo(semaforo * sem);
void estadoRoja(semaforo * sem);
void estadoVerde(semaforo * sem);
void estadoAmarillo(semaforo * sem);
void estadoSemaforo(semaforo * sem);


#endif /* SEMAFORO_H_ */
