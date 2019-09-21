/*
 * controlBoton.h
 *
 *  Created on: 14 sep. 2019
 *      Author: federico
 */

#ifndef PROGRAMS_BLINKY_INC_CONTROLBOTON_H_
#define PROGRAMS_BLINKY_INC_CONTROLBOTON_H_

#include "boton.h"

typedef struct {
	int estadoBoton;
	int ultimoCambioBoton;
}controlBoton;

enum{
	Up, Falling, Rising, Down
};
void actualizarBoton(controlBoton* control, boton * boton);
void inicializarBoton(controlBoton * control, boton * boton, botonHandler _funcionDown);

#endif /* PROGRAMS_BLINKY_INC_CONTROLBOTON_H_ */
