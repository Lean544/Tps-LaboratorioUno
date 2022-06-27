/*
 ============================================================================
 Name        : Trabajo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "passenger.h"
#include "tomaDatos.h"

#define MAXIMO 5
int main(void) {
	setbuf(stdout, NULL);
	int retorno;
	int menu;
	int retornoUno;
	int tipoAux,statusAux,id=0,contIngresos=0,contPrecios=0;
	float precioAux,acumPrecios;
	char auxNombre[51],auxApellido[51],auxCodigo[10];

	Passenger pasajeros[MAXIMO];
	Passenger* pPasajeros;

	pPasajeros=pasajeros;

	initPassengers(pPasajeros,MAXIMO);

	do
	{
		retorno = utn_getNumero(&menu,"1.Altas pasajeros\n2.Modificar pasajeros\n3.Baja de pasajeros\n4.Informar\n5.Carga Forzada\n6.Salir","Error",1,6,2);
		if(retorno == 0){
				switch(menu){
						case 1:
							retornoUno=tomarDatos(auxNombre,auxApellido,&precioAux,&tipoAux,auxCodigo,&statusAux,&id);
							if(retornoUno==0){
								acumPrecios=acumPrecios+precioAux;
								contPrecios++;
								addPassenger(pPasajeros, MAXIMO,&id, auxNombre, auxApellido
								, &precioAux, &tipoAux, auxCodigo,&statusAux);
								contIngresos++;
							}
						break;


						case 2:
								if(retornoUno==0){
									//findPassengerById(pPasajeros,MAXIMO,pPasajeros->id);
									modificarPasajero(pPasajeros,MAXIMO);
								}else{
									printf("Error no se completo la funcion anterior\n");
								}
								break;

						case 3:
								if(retornoUno==0)
								{

									removePassenger( pPasajeros, MAXIMO);


								}else{
									printf("Error no hay ningun pasajero ingresado\n");
								}
								break;


						case 4:
								if(retornoUno==0)
								{
									if(contIngresos==1){
										printAPassenger(pPasajeros);
									}else{
										MenuMostrar(pPasajeros, MAXIMO,contPrecios,acumPrecios);
									}
								}else
								{
									printf("Error no hay ningun pasajero ingresado o no se llenaron todos espacios\n");
								}
								break;

						case 5:

								cargaForzada(pPasajeros,MAXIMO);

								break;

						case 6:
								printf("Finalizando programa");
								break;
							}
		}

	}while(menu!=6);


	return EXIT_SUCCESS;
}
