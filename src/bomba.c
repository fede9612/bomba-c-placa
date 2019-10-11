/*
 * bomba.c
 *
 *  Created on: 5 oct. 2019
 *      Author: federico
 */

#include "bomba.h"

void bombaPrender(Bomba * bomba){
	if(bomba->estadoBomba == Apagada){
		bomba->estadoBomba = Prendida;
	}else{
		bomba->estadoBomba = Apagada;
	}

}

void bombaApagar(Bomba * bomba){
	bomba->estadoBomba = Apagada;
}

void bombaMitad(Bomba * bomba){
	bomba->estadoBomba = Mitad;
}

void bombaLlena(Bomba * bomba){
	bomba->estadoBomba = Llena;
}
