#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "passenger.h"
#include <ctype.h>
#include "tomaDatos.h"

int initPassengers(Passenger* list, int len)
{
	for(int i=0;i<len;i++){
				(list+i)->isEmpty=1;
				(list+i)->id=0;
			}


return 0;
}

int addPassenger(Passenger* list, int len, int* id, char name[],char
lastName[],float* price,int* typePassenger, char flycode[],int* status)
{
	int retorno=-1;
	int i;

	for(i=0;i<len;i++){
		if((list+i)->isEmpty==1){
			strcpy((list+i)->name,name);
			strcpy((list+i)->lastName,lastName);
			(list+i)->price=*price;
			(list+i)->tipoPasajero=*typePassenger;
			strcpy((list+i)->flycode,flycode);
			(list+i)->statusFlight=*status;
			(list+i)->id=*id;

			(list+i)->isEmpty=0;
			retorno=0;

			printf("\n----------------------------------------------------\n\n");
			printf(" El nombre ingresado es:%s\n",(list+i)->name);
			printf(" El apellido ingresado es:%s\n",(list+i)->lastName);
			printf(" El precio del vuelo es:%f\n",(list+i)->price);
			printf(" El tipo de pasajero es %d\n",(list+i)->tipoPasajero);
			printf(" Su codigo de vuelo es %s\n",(list+i)->flycode);
			printf(" El estado de vuelo es %d\n",*status);
			printf(" Su id es %d\n",(list+i)->id);
			printf("\n----------------------------------------------------\n\n");
			break;

		}

	}


	return retorno;
}

int findPassengerById(Passenger* list, int len,int id)
{
	int i;

	for(i=0;i<len;i++){
		if((list+i)->id==id){
			printf("Pasajero encontrado!\n");
			return i;
		}
	}
 return -1;
}

void modificarPasajero(Passenger* pasajero,int len){
	int menu;
	int idModificar;
	int busqueda;

	utn_getNumero(&idModificar,"Ingrese la Id del pasajero a modificar","Error",1,len,5);

	busqueda=findPassengerById(pasajero,len,idModificar);


	if(busqueda!=-1){
		do{
			utn_getNumero(&menu," Ingrese la opcion a modificar:\n 1)Nombre\n 2)Apellido\n 3)Precio\n"
					" 4)Codigo de vuelo\n 5)Tipo de Pasajero\n 6)Estatus de Vuelo\n 7)Volver al menu anterior\n","Error",1,7,5);

			switch(menu){
				case 1:

						printf("El nombre actual es %s\n",(pasajero+busqueda)->name);

						if(utn_getCadena((pasajero+busqueda)->name,"Ingrese el nombre","Error",51,5)==0){

							printf("El nuevo nombre es %s",(pasajero+busqueda)->name);
						}else{
							printf("Error al actualizar el nombre");
						}



					break;

				case 2:
						printf("El Apellido actual es %s\n",(pasajero+busqueda)->lastName);

						utn_getCadena((pasajero+busqueda)->lastName,"Ingrese el nombre","Error",51,5);
						printf("El nuevo Apellido es %s\n",(pasajero+busqueda)->lastName);

					break;

				case 3:
						printf("El Precio actual es %f\n",(pasajero+busqueda)->price);

						utn_getNumeroFlotante(&(pasajero+busqueda)->price,"Ingrese el numero",
						"Error",45000,250000,5);

						printf("El Precio nuevo es %f\n",(pasajero+busqueda)->price);

					break;

				case 4:
					printf("El Codigo de vuelo actual es %s\n",(pasajero+busqueda)->flycode);

					utn_getCodigo((pasajero+busqueda)->flycode,"Ingrese el nuevo codigo","Error",51,5);
					printf("El Codigo de vuelo nuevo es %s\n",(pasajero+busqueda)->flycode);

					break;


				case 5:
					printf("El Tipo de Pasajero actual es %d\n",(pasajero+busqueda)->tipoPasajero);

					utn_getNumero(&(pasajero+busqueda)->tipoPasajero,
					"Ingrese el tipo de pasajero nuevo\n 1)Jubilado\n 2)Trabajador\n 3)Estudiante\n 4) Discapacitado",
					"Error",1,4,5);

					printf("El Tipo de pasajero nuevo es %d\n",(pasajero+busqueda)->tipoPasajero);

					break;

				case 6:
					printf("El Status de vuelo actual es %d\n",(pasajero+busqueda)->statusFlight);

					utn_getNumero(&(pasajero+busqueda)->statusFlight,"Ingrese el status nuevo:\n"
					"100.Normal\n101.Atrasado\n102.Cancelado","Error",100,102,5);

					printf("El Status de vuelo nuevo es %d\n",(pasajero+busqueda)->statusFlight);

					break;

				case 7:
					printf("Finalizando Submenu\n");
					break;

					}
			}while(menu!=7);
	}else{
		printf("Error pasajero no encontrado\n");
	}
}

int printPassenger(Passenger* list, int length){
	int i;
	int j;
	int x;
	int anchoColumnasTexto=-20;
	//int anchoColumnasNumero=-15;
	int anchoColumnasNumero=-20;

	statusFlight EstatusVuelo[3]={
			{100 , "Normal"},
			{101 , "Atrasado"},
			{102 , "Cancelado"}
			};
	typePassenger TipoPasajero[4]={
			{1, "Jubilado"},
			{2, "Trabajador"},
			{3, "Estudiante"},
			{4, "Discapacitado"}
			};




	printf("\n*******************************************************************************************************\n");
	printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|",anchoColumnasTexto,"Nombres",anchoColumnasTexto,"Apellidos",anchoColumnasNumero,
			"Precios",anchoColumnasTexto,"Codigos de vuelo",anchoColumnasTexto,"Estatus de Vuelo",
			anchoColumnasTexto,"Tipo de pasajero",anchoColumnasNumero,"Id");
	for(i=0;i<length;i++){
		if((list+i)->isEmpty==0){
			for(j=0;j<4;j++){
				if((list+i)->statusFlight==(*(EstatusVuelo+j)).id){
					break;
				}
			}
			for(x=0;x<5;x++){
					if((list+i)->tipoPasajero==(*(TipoPasajero+x)).id){
						break;
					}
			}
			printf("\n----------------------------------------------------------------------------------------------------\n");
			printf("|%*s|%*s|%*f|%*s|%*s|%*s|%*d|\n",anchoColumnasTexto,(list+i)->name,anchoColumnasNumero,(list+i)->lastName
			,anchoColumnasNumero,(list+i)->price,anchoColumnasTexto,(list+i)->flycode
			,anchoColumnasTexto,(*(EstatusVuelo+j)).descriptionstatusFlight,
			anchoColumnasTexto,(*(TipoPasajero+x)).descriptionPassenger,anchoColumnasNumero,(list+i)->id);
		}
	}


	printf("\n*******************************************************************************************************\n");

	return 0;
}

int printAPassenger(Passenger* list){
	int j;
	int x;
	int anchoColumnasTexto=-20;
	//int anchoColumnasNumero=-15;
	int anchoColumnasNumero=-20;

	statusFlight EstatusVuelo[3]={
			{100 , "Normal"},
			{101 , "Atrasado"},
			{102 , "Cancelado"}
			};
	typePassenger TipoPasajero[4]={
			{1, "Jubilado"},
			{2, "Trabajador"},
			{3, "Estudiante"},
			{4, "Discapacitado"}
			};

		for(j=0;j<4;j++){
			if((list+0)->statusFlight==(*(EstatusVuelo+j)).id){
				break;
			}
		}
		for(x=0;x<5;x++){
			if((list+0)->tipoPasajero==(*(TipoPasajero+x)).id){
				break;
			}
		}



	printf("\n*******************************************************************************************************\n");
	printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|",anchoColumnasTexto,"Nombres",anchoColumnasTexto,"Apellidos",anchoColumnasNumero,
			"Precios",anchoColumnasTexto,"Codigos de vuelo",anchoColumnasTexto,"Estatus de Vuelo",
			anchoColumnasTexto,"Tipo de pasajero",anchoColumnasNumero,"Id");
		if((list+0)->isEmpty==0){
			printf("\n----------------------------------------------------------------------------------------------------\n");
			printf("|%*s|%*s|%*f|%*s|%*s|%*s|%*d|\n",anchoColumnasTexto,(list+0)->name,anchoColumnasNumero,(list+0)->lastName
			,anchoColumnasNumero,(list+0)->price,anchoColumnasTexto,(list+0)->flycode
			,anchoColumnasTexto,(*(EstatusVuelo+j)).descriptionstatusFlight,
			anchoColumnasTexto,(*(TipoPasajero+x)).descriptionPassenger,anchoColumnasNumero,(list+0)->id);

		}



	printf("\n*******************************************************************************************************\n");

	return 0;
}

int sortPassengers(Passenger* list, int len, int order)
{
	int flagCambio;
	int i;
	char auxApellido[51];
	char auxCodigoVuelo[10];
	char auxNombre[51];
	float auxPrecio;
	int auxTipo,auxEstadoVuelo,auxId,auxIsEmpty;

	if(order==1){
		do{
			flagCambio = 0;
			for(i = 0; i < len-1; i++){

				if(strcmp((list+i)->lastName,(list+i+1)->lastName)>0 && (list+i)->isEmpty==0){

					flagCambio = 1;

					strcpy(auxNombre, (list+i)->name);
					strcpy((list+i)->name, (list+i+1)->name);
					strcpy((list+i+1)->name, auxNombre);

					strcpy(auxApellido, (list+i)->lastName);
					strcpy((list+i)->lastName, (list+i+1)->lastName);
					strcpy((list+i+1)->lastName, auxApellido);

					auxPrecio = (list+i)->price;
					(list+i)->price = (list+i+1)->price;
					(list+i+1)->price = auxPrecio;

					strcpy(auxCodigoVuelo, (list+i)->flycode);
					strcpy((list+i)->flycode, (list+i+1)->flycode);
					strcpy((list+i+1)->flycode, auxCodigoVuelo);

					auxTipo = (list+i)->tipoPasajero;
					(list+i)->tipoPasajero = (list+i+1)->tipoPasajero;
					(list+i+1)->tipoPasajero = auxTipo;

					auxEstadoVuelo = (list+i)->statusFlight;
					(list+i)->statusFlight = (list+i+1)->statusFlight;
					(list+i+1)->statusFlight = auxEstadoVuelo;

					auxId = (list+i)->id;
					(list+i)->id = (list+i+1)->id;
					(list+i+1)->id = auxId;

					auxIsEmpty=(list+i)->isEmpty;
					(list+i)->isEmpty=(list+i+1)->isEmpty;
					(list+i+1)->isEmpty=auxIsEmpty;
				}
			}
			}while(flagCambio == 1);


	}else{
		do{
			flagCambio = 0;
			for(i = 0; i < len-1; i++){

				if(strcmp((list+i)->lastName,(list+i+1)->lastName)<0 && (list+i)->isEmpty==0){

					flagCambio = 1;

					strcpy(auxNombre, (list+i)->name);
					strcpy((list+i)->name, (list+i+1)->name);
					strcpy((list+i+1)->name, auxNombre);

					strcpy(auxApellido, (list+i)->lastName);
					strcpy((list+i)->lastName, (list+i+1)->lastName);
					strcpy((list+i+1)->lastName, auxApellido);

					auxPrecio = (list+i)->price;
					(list+i)->price = (list+i+1)->price;
					(list+i+1)->price = auxPrecio;

					strcpy(auxCodigoVuelo, (list+i)->flycode);
					strcpy((list+i)->flycode, (list+i+1)->flycode);
					strcpy((list+i+1)->flycode, auxCodigoVuelo);

					auxTipo = (list+i)->tipoPasajero;
					(list+i)->tipoPasajero = (list+i+1)->tipoPasajero;
					(list+i+1)->tipoPasajero = auxTipo;

					auxEstadoVuelo = (list+i)->statusFlight;
					(list+i)->statusFlight = (list+i+1)->statusFlight;
					(list+i+1)->statusFlight = auxEstadoVuelo;

					auxId = (list+i)->id;
					(list+i)->id = (list+i+1)->id;
					(list+i+1)->id = auxId;


				}
			}
			}while(flagCambio == 1);
	}

return 0;
}

int sortPassengersByCode(Passenger* list, int len, int order)
{
	int flagCambio;
		int i;
		char auxNombre[51],auxApellido[51],auxCodigoVuelo[10];
		float auxPrecio;
		int auxTipo,auxEstadoVuelo,auxId;
		if(order==1){
			do{
				flagCambio = 0;
				for(i = 0; i < len-1; i++){

					if(strcmp((list+i)->flycode,(list+i+1)->flycode)>0 &&
							(list+i)->statusFlight>(list+i+1)->statusFlight && (list+i)->isEmpty==0 && (list+i)->id!=0){

						flagCambio = 1;

						strcpy(auxNombre, (list+i)->name);
						strcpy((list+i)->name, (list+i+1)->name);
						strcpy((list+i+1)->name, auxNombre);

						strcpy(auxApellido, (list+i)->lastName);
						strcpy((list+i)->lastName, (list+i+1)->lastName);
						strcpy((list+i+1)->lastName, auxApellido);

						auxPrecio = (list+i)->price;
						(list+i)->price = (list+i+1)->price;
						(list+i+1)->price = auxPrecio;

						strcpy(auxCodigoVuelo, (list+i)->flycode);
						strcpy((list+i)->flycode, (list+i+1)->flycode);
						strcpy((list+i+1)->flycode, auxCodigoVuelo);

						auxTipo = (list+i)->tipoPasajero;
						(list+i)->tipoPasajero = (list+i+1)->tipoPasajero;
						(list+i+1)->tipoPasajero = auxTipo;

						auxEstadoVuelo = (list+i)->statusFlight;
						(list+i)->statusFlight = (list+i+1)->statusFlight;
						(list+i+1)->statusFlight = auxEstadoVuelo;

						auxId = (list+i)->id;
						(list+i)->id = (list+i+1)->id;
						(list+i+1)->id = auxId;


					}
				}
				}while(flagCambio == 1);


		}else{
			do{
				flagCambio = 0;
				for(i = 0; i < len-1; i++){

					if(strcmp((list+i)->flycode,(list+i+1)->flycode)<0 &&
							(list+i)->statusFlight<(list+i+1)->statusFlight && (list+i)->isEmpty==0){

						flagCambio = 1;

						strcpy(auxNombre, (list+i)->name);
						strcpy((list+i)->name, (list+i+1)->name);
						strcpy((list+i+1)->name, auxNombre);

						strcpy(auxApellido, (list+i)->lastName);
						strcpy((list+i)->lastName, (list+i+1)->lastName);
						strcpy((list+i+1)->lastName, auxApellido);

						auxPrecio = (list+i)->price;
						(list+i)->price = (list+i+1)->price;
						(list+i+1)->price = auxPrecio;

						strcpy(auxCodigoVuelo, (list+i)->flycode);
						strcpy((list+i)->flycode, (list+i+1)->flycode);
						strcpy((list+i+1)->flycode, auxCodigoVuelo);

						auxTipo = (list+i)->tipoPasajero;
						(list+i)->tipoPasajero = (list+i+1)->tipoPasajero;
						(list+i+1)->tipoPasajero = auxTipo;

						auxEstadoVuelo = (list+i)->statusFlight;
						(list+i)->statusFlight = (list+i+1)->statusFlight;
						(list+i+1)->statusFlight = auxEstadoVuelo;

						auxId = (list+i)->id;
						(list+i)->id = (list+i+1)->id;
						(list+i+1)->id = auxId;


					}
				}
				}while(flagCambio == 1);
		}


return 0;
}

int sortByPrice(Passenger* list, int len, int order,int contPrecios,float acumPrecios){

	float promedio;
	int i;
	int j;
	int x;
	int anchoColumnasTexto=-20;
	//int anchoColumnasNumero=-15;
	int anchoColumnasNumero=-20;
	statusFlight EstatusVuelo[3]={
				{100 , "Normal"},
				{101 , "Atrasado"},
				{102 , "Cancelado"}
				};
		typePassenger TipoPasajero[4]={
				{1, "Jubilado"},
				{2, "Trabajador"},
				{3, "Estudiante"},
				{4, "Discapacitado"}
				};

		for(j=0;j<4;j++){
			if((list+j)->statusFlight==(*(EstatusVuelo+j)).id){

				break;
			}
		}
		for(x=0;x<5;x++){
				if((list)->tipoPasajero==(*(TipoPasajero+x)).id){

					break;
				}
		}
	promedio=acumPrecios/contPrecios;


	printf("\n\n El total de las ventas de boletos es de: %f\n\n",acumPrecios);
	printf("\n\n El promedio de las ventas es de:%f\n\n",promedio);

	printf("La cantidad de Pasajeros que superan el promedio de precio son:\n\n");
	printf("\n*******************************************************************************************************\n");
	printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|",anchoColumnasTexto,"Nombres",anchoColumnasTexto,"Apellidos",anchoColumnasNumero,
			"Precios",anchoColumnasTexto,"Codigos de vuelo",anchoColumnasTexto,"Estatus de Vuelo",
			anchoColumnasTexto,"Tipo de pasajero",anchoColumnasNumero,"Id");
	for(i=0;i<len;i++){
		if((list+i)->isEmpty==0 && (list+i)->price>promedio){
			for(j=0;j<4;j++){
				if((list+i)->statusFlight==(*(EstatusVuelo+j)).id){

					break;
				}
			}
			for(x=0;x<5;x++){
					if((list+i)->tipoPasajero==(*(TipoPasajero+x)).id){

						break;
					}
			}
			printf("\n----------------------------------------------------------------------------------------------------\n");
			printf("|%*s|%*s|%*f|%*s|%*s|%*s|%*d|\n",anchoColumnasTexto,(list+i)->name,anchoColumnasNumero,(list+i)->lastName
			,anchoColumnasNumero,(list+i)->price,anchoColumnasTexto,(list+i)->flycode
			,anchoColumnasTexto,(*(EstatusVuelo+j)).descriptionstatusFlight,
			anchoColumnasTexto,(*(TipoPasajero+x)).descriptionPassenger,anchoColumnasNumero,(list+i)->id);
		}
	}


	printf("\n*******************************************************************************************************\n");

	return 0;
}

void MenuMostrar(Passenger* list, int length,int contPrecios,float acumPrecios)
{
	int menu;
	int retornoMenu;
	int modoOrdenamiento;

	do{
		retornoMenu=utn_getNumero(&menu,"Ingrese la forma en la que quiere se liste a los pasajeros\n"
				"1)Alfabeticamente y por tipo de pasajero\n2)Mostrar el total de recaudacion,"
				"el promedio y cuantos lo superan\n3)Por codigo de vuelo y Estado de vuelo\n"
				"4)Finalizar submenu","Error",1,4,5);

		if(retornoMenu==0){
			switch(menu){
				case 1:
					utn_getNumero(&modoOrdenamiento,"Ingrese le modo en el que desea listarlo\n"
					"1.Ascendente\n2.Descendente","Error",1,2,5);
					sortPassengers(list,length,modoOrdenamiento);
					printPassenger(list,length);
					break;

				case 2:
					sortByPrice(list,length,modoOrdenamiento,contPrecios,acumPrecios);
					break;

				case 3:
					utn_getNumero(&modoOrdenamiento,"Ingrese le modo en el que desea listarlo\n"
					"1.Ascendente\n2.Descendente","Error",1,2,5);
					sortPassengersByCode(list, length, modoOrdenamiento);
					printPassenger(list,length);
					break;

				case 4:
					printf("Finalizando submenu\n");
					break;
				}
		}
	}while(menu!=4);
}

int removePassenger(Passenger* list, int len)
{
	int idAux;

	if(list!=NULL && len<0){
		utn_getNumero(&idAux,"Ingrese la id del pasajero a eliminar","Error",1,len,5);
		if(findPassengerById(list,len,idAux)!=-1){
			printf("Pasajero Encontrado!");
			(list+idAux)->isEmpty=1;
			return 0;

		}else{
		printf("Error pasajero no encontrado\n");
		}
	}
	return -1;
}


void cargaForzada(Passenger* list,int len){
	char* nombres[5]={"martin","laura","juan","facundo","julio"};
	char* apellidos[5]={"montiel","Qispe","Allende","casas","roca"};
	float precios[5]={155000,165000,125000,75000,95000};
	char* codigos[5]={"1Y8F","9SIQ","4H7S","6B0M","1P7I"};
	int ids[5]={1,2,3,4,5};
	int tipoPasajeros[5]={1,3,2,1,2};
	int estatusVuelos[5]={100,102,101,100,100};
	int acumPrecios=502500;
	int contPrecios=5;
	for(int i=0;i<len;i++){
		addPassenger(list, len,(ids+i),*(nombres+i),*(apellidos+i)
		, (precios+i), (tipoPasajeros+i), *(codigos+i),(estatusVuelos+i));
	}

	sortPassengers(list,len,2);
	printPassenger(list, len);
	sortPassengersByCode(list,len,2);
	printPassenger(list, len);
	sortByPrice(list, len, 2, contPrecios, acumPrecios);
}



