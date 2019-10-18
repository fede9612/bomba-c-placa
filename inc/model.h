/*
 * model.h
 *
 *  Created on: 18 oct. 2019
 *      Author: federico
 */

#ifndef PROGRAMS_BLINKY_INC_MODEL_H_
#define PROGRAMS_BLINKY_INC_MODEL_H_

#include "controlRemoto.h"
#include "bomba.h"

typedef struct{
	Bomba * bomba;
	ControlRemoto * control;
}Model;

void inicializarModel(Model * model, Bomba * bomba, ControlRemoto * control);
void iniciarModel(Model * model);
void detenerModel(Model * model);

#endif /* PROGRAMS_BLINKY_INC_MODEL_H_ */
