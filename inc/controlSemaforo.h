/*
 * controlSemaforo.h
 *
 *  Created on: 4 sep. 2019
 *      Author: federico
 */

#ifndef CONTROLSEMAFORO_H_
#define CONTROLSEMAFORO_H_

#include "semaforo.h"

#define TiempoRojo 7000
#define TiempoAmarillo 3000
#define TiempoVerde 7000


typedef struct {

}controlSemaforo;

void iniciar(controlSemaforo * control, semaforo * sem);

#endif /* CONTROLSEMAFORO_H_ */
