/*
 * passenger.h
 *
 *  Created on: 9 may. 2022
 *      Author: ayala
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_
struct
{

int id;
char descriptionPassenger[21];

}typedef typePassenger;
/*	typePassenger tipoPasajeros[]={
			{1, "Jubilado"},
			{2, "Trabajador"},
			{3, "Estudiante" },
			{4, "Discapacitado"}
			};*/
struct
{

int id;
char descriptionstatusFlight[21];

}typedef statusFlight;

/*statusFlight tipoVuelos[]={
			{1, "Normal"},
			{2, "Atrasado"},
			{3, "Cancelado" },
			};*/

struct
{
int id;
char name[51];
char lastName[51];
float price;
char flycode[10];
int tipoPasajero;
int statusFlight;
int isEmpty;
}typedef Passenger;


#endif /* PASSENGER_H_ */

int initPassengers(Passenger* list, int len);

int addPassenger(Passenger* list, int len, int* id, char name[],char
lastName[],float* price,int* typePassenger, char flycode[],int* status);

int findPassengerById(Passenger* list, int len,int id);

void modificarPasajero(Passenger* pasajero,int len);

int printPassenger(Passenger* list, int length);

int printAPassenger(Passenger* list);

int sortPassengers(Passenger* list, int len, int order);

int sortPassengersByCode(Passenger* list, int len, int order);

int sortByPrice(Passenger* list, int len, int order,int contPrecios,float acumPrecios);

void MenuMostrar(Passenger* list, int length,int contPrecios,float acumPrecios);

int removePassenger(Passenger* list, int len);

void cargaForzada(Passenger* list,int len);
