#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
int main(void) {
	int eleccion;
	float A;
	setlocale(LC_ALL, "es-ES");
	printf("MENU PRINCIPAL PROYECTO:\n\n[-1.Pulse 1 para la entrada al Parking (SIENDO 1 BOTON SWITCH 1)]\n\n[-2.Pulse 2 para la salida del Parking (SIENDO 2 BOTON SWITCH 2 PARA LA SALIDA)]\n\n[-3.Presiona para ver el numero de plazas disponibles]\n\n[-4.Fin Del Programa]\n\nSeleccione opci�n:");
	scanf_s("%d", &eleccion);
	if (eleccion == 1) {
		printf("\n\nHas PRESIONADO BOTON ENTRADA (Se eleva la barra)\n\n ");
		printf("\n\nIf((numero_plazas>0)  &&  (sensor detecta la presencia a una frecuencia>= X Hz)  &&  (presiona switch)\n\n");
		printf("\n\n*******APERTURA*******\n\nContador_de_plazas=Contador_de_plazas-1------(SIENDO Contador_de_plazas=40)\n\nLA BARRA SE ABRE MIENTRAS SIMULTANEAMENTE SE ENCIENDEN LAS LEDS\n\n");
		
	}
	else if (eleccion == 2)
	{
		printf("\n\nHas PRESIONADO BOTON SALIDA (Se eleva la barra)\n\n ");
		printf("\n\nIf((sensor detecta la presencia a una frecuencia>= X Hz) && (presiona switch))\n\n");
		printf("\n\n*******APERTURA*******\n\nContador_de_plazas=Contador_de_plazas+1------(AL ABANDONAR LA PLAZA RESERVADA)\n\nLA BARRA SE ABRE MIENTRAS SIMULTANEAMENTE SE ENCIENDEN LAS LEDS\n\n");


	}
	else if (eleccion == 3)
	{
		printf("\n\nQUEDAN X PLAZAS\n\n");
		printf("\n\n[Printf(X,contador)===========[If(numero_plazas)<1]===========NO APERTURA===========INDICAR PANTALLA PLAZAS LLENAS]\n\n");
	}
	else if (eleccion == 4)
	{
		do
		{
			printf("FINAL DEL PROGRAMA");
			break;

		} while (eleccion == 4);

	}
}
/*-�Cu�l ser� el ciclo de funcionamiento del sistema y por ende qu� eventos
desencadenar�n la progresi�n del mismo?
-El funcionamiento comienza con la aproximaci�n del vehiculo a la barra accionada por el servomotor. Una vez localizada dentro del rango , el programa medira tres condiciones: la aproximaci�n del vehiculo con sensores infras�nicos, si acciona o no el bot�n SWITCH, y finalmente si hay plazas disponibles. En caso de que alguna no se confirme, el programa no se activar�. En caso de que se verifiquen las condiciones la barra comenzara a abrirse junto con el funcionamiento de las luces led que complemtaran el ciclo. Una vez habiendo pasado la barra. Si no se detecta la presencia de alg�n vehiculo esta se bajara tras unos segundos e indicar� una disminuci�n del contador del numero de plazas m�ximo hasta que no haya disponible.
-�Qu� magnitudes f�sicas va a capturar y medir el sistema?:
-Para accionar la barra cuando el medidor supera una cantidad de Hz dentro del intervalo establecido. Un sensor reconoce la proximidad del vehiculo y por lo tanto envia al programa una se�al de que se esta cumpliendo la condici�n de proximacion para su apertura la cual se debe ver complementada junto con el numero de plazas disponibles y si se acciona o no el �SWITCH�.

-�Qu� consignas de gobierno se deben establecer desde la aplicaci�n del Pc para
determinar el comportamiento del subsistema hardware?
El sensor consta de un terminal emisor que emite un ultrasonido (inaudible para el o�do humano por su alta frecuencia) y espera un determinado tiempo con el terminal receptor la vuelta de la onda sonora. Si no detecta nada es debido a que no hay ning�n obst�culo en el rango de medidas del sensor (este sensor en concreto tiene un rango de distancias sensible entre 3cm y 3m con una precisi�n de 3mm) mientras que si recibe la respuesta usa el hecho de que el sonido lleva un movimiento rectil�neo uniforme para, a partir del tiempo que pasa desde que emite hasta que recibe la se�al, realice de forma sencila el c�lculo de la distancia a la que se encuentra el objeto
*/