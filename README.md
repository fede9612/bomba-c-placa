# bomba-c-placa

### Información sobre el proyecto

Este proyecto está basado sobre el uso de la placa CIAA. La funcionalidad que tiene es poder prender un relay a través de un botón o de una aplicación por medio de la conectividad Bluetooth, en este caso se usa para encender una bomba pero se podría encender cualquier aparato electro de 220v.

### Conectividad

Si contamos con la placa CIAA EDU conectaremos el **relay** de la siguiente manera:

* Alimentación: 5v
* Datos: GPIO01
* Negativo: GND 

En cuanto a la **placa Bluetooth** la conectamos así:

* Alimentación(VVC): 5v
* Negativo(GND): GND
* RXD: 232_TX
* TXD: 232_RX

### Uso

El progama lo podemos usar de dos maneras:

* A través de la placa utilizando el botón TEC 1 para encender y apagar.
* A través de la aplicación Android, primero precionamos en buscar, cuando aparezca la leyenda "Seleccione el dispositivo" presionamos sobre Elegir dispositivo, elegimos el dispositivo bluetooth y tocamos Conectar. Si aparece la leyenda "Conectado" podemos precionar sobre Encender bomba para prenderla y Apagar bomba para apagarla.
