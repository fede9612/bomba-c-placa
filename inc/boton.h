/*
 * boton.h
 *
 *  Created on: 14 sep. 2019
 *      Author: federico
 */

#ifndef PROGRAMS_BLINKY_INC_BOTON_H_
#define PROGRAMS_BLINKY_INC_BOTON_H_

typedef void (* botonHandler)(void);

typedef struct{
	botonHandler funcionDown;
}boton;


#endif /* PROGRAMS_BLINKY_INC_BOTON_H_ */
