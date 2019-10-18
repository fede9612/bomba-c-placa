/*
 * model.c
 *
 *  Created on: 18 oct. 2019
 *      Author: federico
 */

#include "model.h"
#include "sapi.h"
#include "bomba.h"
#include "controlRemoto.h"

void inicializarModel(Model * model, Bomba * bomba, ControlRemoto * control){
	model->bomba = bomba;
	model->control = control;
}

void iniciarModel(Model * model){
	bombaPrender(model->bomba);
	gpioToggle(GPIO1);
	cambiarEstadoControlRemoto(model->control);
	gpioWrite(LED3, ON);
}

void detenerModel(Model * model){
	bombaApagar(model->bomba);
	cambiarEstadoControlRemoto(model->control);
	gpioToggle(GPIO1);
	gpioWrite(LED3, OFF);
}
