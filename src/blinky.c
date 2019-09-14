/* Copyright 2016, Eric Pernia.
 * All rights reserved.
 *
 * This file is part sAPI library for microcontrollers.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/*
 * Date: 2016-04-26
 */

/*==================[inclusions]=============================================*/

#include "controlSemaforo.h"
#include "semaforo.h"
#include "visualizarSemaforo.h"
#include "sapi.h"

/* FUNCION PRINCIPAL, PUNTO DE ENTRADA AL PROGRAMA LUEGO DE RESET. */

int main(void) {

	/* ------------- INICIALIZACIONES ------------- */

	/* Inicializar la placa */
	boardConfig();

	/* ------------- REPETIR POR SIEMPRE ------------- */
//   while(1) {
//
//      /* Prendo el led azul */
//      gpioWrite( LED2, ON );
//
//      delay(500);
//
//      /* Apago el led azul */
//      gpioWrite( LED2, OFF );
//
//      delay(500);
//
//   }


//Semaforo
//	semaforo sem1;
//	int * psemaforo;
//	psemaforo = &sem1;
//	controlSemaforo control1;
//	int * pcontrol;
//	pcontrol = &control1;
//
//	while (1) {
//		iniciar(pcontrol, psemaforo);
//	}


	semaforo sem1;
	int * psemaforo;
	psemaforo = &sem1;
	controlSemaforo control1;
	int * pcontrol;
	pcontrol = &control1;
	iniciar(pcontrol, psemaforo);
	while (1) {
		actualizar(pcontrol, psemaforo);
		estadoSemaforo(psemaforo);
		delay(1000);
	}



//Boton para prender led rojo
//	int estado;
//	while (1) {
//		{
//			int valor = gpioRead(TEC1);    //leemos el botón: false  =  LOW
//			if (valor == 0)              // esto es que han pulsado el botón
//			{
//				estado = !estado;                       // cambiamos el estado
//				gpioWrite(LED2, estado);          // escribimos el nuevo valor
//			}
//		}
//	}

	/* NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa no es llamado
	 por ningun S.O. */
	return 0;
}

/*==================[end of file]============================================*/
