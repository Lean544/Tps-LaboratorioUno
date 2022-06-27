#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
int main(void) {
	setbuf(stdout, NULL);
	int menu;
	int respuesta;
	float kms;
	float precioAerolineas;
	float precioLatam;
	int retornoUno;
	int retornoDos;
	int retornoTres;
	float debitoAero,debitoLatam,creditoAero,creditoLatam,bitcoinAero,bitcoinLatam,
	unitarioAero,unitarioLatam,difPrecios;
	do{
		respuesta = utn_getNumero(&menu,"1.Ingresar Kilometros.\n2.Ingresar precio de vuelos.\n3.Calcular costos."
				"\n4.Informar resultados.\n5.Carga Forzada de datos.\n6.Salir.\n","Opcion invalida\n",1,6,2);
		if(respuesta == 0){
			switch(menu){
				case 1:
					retornoUno=utn_getNumeroFlotante(&kms,"Ingrese los Kilometros a viajar:","Error",2500,1000000,5);

					break;
				case 2:
					if(retornoUno==0){
						if(utn_getNumeroFlotante(&precioAerolineas,"Ingrese el precio de Aerolineas:",
								"Error no es un numero o esta fuera del rango de precios\n",55000,350000,5)!=-1&&
						utn_getNumeroFlotante(&precioLatam,"Ingrese el precio de Latam:",
						"Error no es un numero o esta fuera del rango de precios\n",55000,350000,5)!=-1){
							retornoDos=1;
						}
					}else{
						printf("Error no se completo la funcion anterior\n");}
					break;
				case 3:
					if(retornoUno==0 && retornoDos==1){
						retornoTres=CalculoPrecios(precioAerolineas,precioLatam,kms,&debitoAero,&debitoLatam,&creditoAero,&creditoLatam,
								&bitcoinAero,&bitcoinLatam,&unitarioAero,&unitarioLatam,&difPrecios);
					}else{
						printf("Error complete las funciones anteriores\n");
					}
					break;
				case 4:
					if(retornoUno==0 && retornoDos==1 && retornoTres==1){
						informar(precioAerolineas,precioLatam,debitoAero,debitoLatam,creditoAero,creditoLatam,bitcoinAero,bitcoinLatam,
						unitarioAero,unitarioLatam,difPrecios);
					}else{
						printf("No completo las funciones anteriores\n");
					}
					break;
				case 5:
						cargaForzada(162965,159339,7090);
						break;
				case 6:
						printf("Finalizando ejecucion");
					break;
			}
		}
	}while(menu!=6);
	return EXIT_SUCCESS;
	}



