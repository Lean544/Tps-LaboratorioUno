/*
 * Menu1.h
 *
 *  Created on: 14 abr. 2022
 *      Author: ayala
 */

#ifndef MENU1_H_
#define MENU1_H_

int getInt(int* pResultado);

int getFloat(int* pResultado);

int myGets(char* cadena,int largo);

int esNumerica(char*cadena);
//Esta funcion cumple el rol de menu principal.
int utn_getNumero(int* pResultado, char* mensaje,char* mensajeError,int minimo,int maximo, int reintentos);

int utn_getNumeroFlotante(float* pResultado, char* mensaje,char* mensajeError,float minimo,float maximo, int reintentos);

int CalculoPrecios(float precioUno,float precioDos,float kms,float* debitoUno,float* debitoDos,float* creditoUno,
float* creditoDos,float* bitcoinUno,float* bitcoinDos,float* unitarioUno,float* unitarioDos,float* difPrecios);

void informar(float precioUno,float precioDos,float debitoUno,float debitoDos,float creditoUno,
float creditoDos,float bitcoinUno,float bitcoinDos,float unitarioUno,float unitarioDos,float difPrecios);

void cargaForzada(float precioUno,float precioDos,float kms);
#endif /* MENU1_H_ */
