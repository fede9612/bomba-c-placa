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

#include "controlBlinky.h"
#include "controlBoton.h"
#include "controlRemoto.h"
#include "boton.h"
#include "sapi.h"
#include "controlBomba.h"
#include "UartConnector.h"
#include "model.h"

#define UART_PC        UART_USB
#define UART_BLUETOOTH UART_232



void prenderLedB(void) {
	gpioToggle(LEDB);
	gpioToggle(GPIO1);
}


//Este es un handler uartConnecter
//void bluetoothCommandReceived(void * appModelPointer, uint8_t byte) {
//	if(byte == 'p') {
//		gpioToggle(LED3);
//	}
//	else if(byte == 'a') {
//		gpioToggle(LED3);
//	}
//}

//Este es un observer del Modelo
//void modelChanged(void * uartConnectorPointer, AppModel * model) {
//	UartConnector * uartConnector = (UartConnector *) uartConnectorPointer;
//	if(appModel_isEnabled(model)) {
//		uartConnector_send(uartConnector, "LED_ON");
//	}
//	else {
//		uartConnector_send(uartConnector, "LED_OFF");
//	}
//}

/* FUNCION PRINCIPAL, PUNTO DE ENTRADA AL PROGRAMA LUEGO DE RESET. */

int main(void) {

//	botonHandler miFuncion = x;
//	miFuncion();
	/* ------------- INICIALIZACIONES ------------- */

	/* Inicializar la placa */
	boardConfig();
	gpioInit( GPIO1, GPIO_OUTPUT );
	/* ------------- REPETIR POR SIEMPRE ------------- */

	Bomba bomba;
	Bomba * pbomba = &bomba;

	controlBomba bombaControl;
	controlBomba * pBombaControl;
	pBombaControl = &bombaControl;
	iniciarBomba(pBombaControl, pbomba);

	ControlRemoto bluetoothControl;
	iniciarControlRemoto(&bluetoothControl);

	controlBlinky controlB;
	controlBlinky * pcontrolAmarillo;
	pcontrolAmarillo = &controlB;
	iniciarBlinky(pcontrolAmarillo, LED1, 3000);

	controlBlinky controlRojo;
	controlBlinky * pcontrolRojo;
	pcontrolRojo = &controlRojo;
	iniciarBlinky(pcontrolRojo, LED2, 6000);

	boton boton1;
	boton * pboton;
	pboton = &boton1;
	controlBoton controlBoton1;
	controlBoton * pcontrolBoton;
	pcontrolBoton = &controlBoton1;
	inicializarBoton(pcontrolBoton, pboton, prenderLedB);

	Model bombaYContolBomba;
	inicializarModel(&bombaYContolBomba, pbomba, &bluetoothControl);

	//--------------------- Bluetooth

	UartConnector uartConnector;

	uartConnector_initBt(&uartConnector, &bombaYContolBomba, bluetoothCommandReceived);

	while (1) {
		actualizarBlinky(pcontrolRojo);
		actualizarBlinky(pcontrolAmarillo);
		actualizarBoton(pcontrolBoton, pboton, pbomba, &bluetoothControl);
		actualizarBomba(pBombaControl, pbomba, pcontrolAmarillo, pcontrolRojo);
		actualizarControlRemoto(&bluetoothControl, pbomba);
		//appModelRender_update(&appModelRender);
		uartConnector_update(&uartConnector);
		delay(1);
	}

	/* NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa no es llamado
	 por ningun S.O. */
	return 0;
}

/*==================[end of file]============================================*/
