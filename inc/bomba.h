/*
 * bomba.h
 *
 *  Created on: 5 oct. 2019
 *      Author: federico
 */

#ifndef PROGRAMS_BLINKY_INC_BOMBA_H_
#define PROGRAMS_BLINKY_INC_BOMBA_H_

typedef struct{
	int estadoBomba;
}Bomba;

enum{
	Prendida, Mitad, Llena, Apagada
};

void bombaPrender(Bomba * bomba);
void bombaApagar(Bomba * bomba);
void bombaMitad(Bomba * bomba);
void bombaLlena(Bomba * bomba);

#endif /* PROGRAMS_BLINKY_INC_BOMBA_H_ */
