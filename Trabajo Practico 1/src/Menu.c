/*
 * Menu.c
 *
 *  Created on: 14 abr. 2022
 *      Author: ayala
 */
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int myGets(char* cadena,int largo){
	int retorno=-1;

	fflush(stdin);
	//scanf("%s",buffer);
	fgets(cadena,largo,stdin);
	(*(cadena+strlen(cadena)-1))='\0';


	return retorno;
}

int esNumerica(char*cadena){
	int retorno=1;
	int i;

	if((*(cadena+0))=='-')
	{
		i=1;
	}else
	{
		i=0;
	}

	for(;(*(cadena+i))!='\0';i++)
	{
		if((*(cadena+i))>'9'||(*(cadena+i))<'0'){
			retorno=0;
			break;
		}
	}

	return retorno;
}

int getInt(int* pResultado){
		int retorno=-1;
		char buffer[4096];



	if(myGets(buffer,sizeof(buffer)) && esNumerica(buffer))
	{
		retorno=0;
		*pResultado=atoi(buffer);
	}

	return retorno;
}

int getFloat(int* pResultado)
{
	int retorno=-1;
	char buffer[4096];



	if(myGets(buffer,sizeof(buffer)) && esNumerica(buffer))
	{
		retorno=0;
		*pResultado=atof(buffer);
	}

	return retorno;
}

int utn_getNumero(int* pResultado, char* mensaje,char* mensajeError,int minimo,int maximo, int reintentos)
{
	int retorno = -1;
	int buffer;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >=0)
	{
		do{
			printf("%s\n",mensaje);
			//scanf("%d",&bufferInt);

			if(getInt(&buffer)==0)
			{
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s\n",mensajeError);
				reintentos--;
			}
		}while(reintentos>0);
	}

	return retorno;
}

int utn_getNumeroFlotante(float* pResultado, char* mensaje,
char* mensajeError,float minimo,float maximo, int reintentos)
{
	int retorno=-1;

	int buffer;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >=0)
	{
		do{
			printf("%s\n",mensaje);
			//scanf("%d",&bufferInt);

			if(getFloat(&buffer)==0 && buffer>=minimo && buffer <=maximo)
			{
				*pResultado = buffer;
				retorno = 0;
				break;
			}else
			{
				printf("%s\n",mensajeError);
				reintentos--;
			}
		}while(reintentos>0);
	}


	return retorno;
}

int CalculoPrecios(float precioUno,float precioDos,float kms,float* debitoUno,float* debitoDos,float* creditoUno,
float* creditoDos,float* bitcoinUno,float* bitcoinDos,float* unitarioUno,float* unitarioDos,float* difPrecios)
{
	int retorno=0;

	if(precioUno>0 && precioDos>0 && kms>0)
	{
		*debitoUno=precioUno-(precioUno*0.10);
		*debitoDos=precioDos-(precioDos*0.10);
		*creditoUno=precioUno+(precioUno*0.25);
		*creditoDos=precioDos+(precioDos*0.25);
		*bitcoinUno=precioUno/4606954.55;
		*bitcoinDos=precioDos/4606954.55;
		*unitarioUno=precioUno/kms;
		*unitarioDos=precioDos/kms;
		if(precioUno>precioDos)
		{
			*difPrecios=precioUno-precioDos;
		}else
		{
			*difPrecios=precioDos-precioUno;
		}
		printf("Todos los calculos completados!\n");
		retorno=1;
	}


	return retorno;
}

void informar(float precioUno,float precioDos,float debitoUno,float debitoDos,float creditoUno,
float creditoDos,float bitcoinUno,float bitcoinDos,float unitarioUno,float unitarioDos,float difPrecios){
	printf("**********************************************************************\n");
	printf("Latam:%f\na)Precio Debito:%f\nb)Precio Credito:%f\nc)Precio Bitcoin:%f\nd)Precio Unitario:%f\n",precioUno,
	debitoUno,creditoUno,bitcoinUno,unitarioUno);
	printf("**********************************************************************\n");
	printf("Aerolineas:%f\na)Precio Debito:%f\nb)Precio Credito:%f\nc)Precio Bitcoin:%f\nd)Precio Unitario:%f\n",precioDos,
	debitoDos,creditoDos,bitcoinDos,unitarioDos);
	printf("**********************************************************************\n");
	printf("Diferencia de Precios:%f\n",difPrecios);
}

void cargaForzada(float precioUno,float precioDos,float kms){
	float debitoUno=precioUno-(precioUno*0.10);
	float debitoDos=precioDos-(precioDos*0.10);
	float creditoUno=precioUno+(precioUno*0.25);
	float creditoDos=precioDos+(precioDos*0.25);
	float bitcoinUno=precioUno/4606954.55;
	float bitcoinDos=precioDos/4606954.55;
	float unitarioUno=precioUno/kms;
	float unitarioDos=precioDos/kms;
	float difPrecios;

	if(precioUno>precioDos)
	{
		difPrecios=precioUno-precioDos;
	}else
	{
		difPrecios=precioDos-precioUno;
	}

	printf("**********************************************************************\n");
	printf("Latam:\na)Precio Debito:%f\nb)Precio Credito:%f\nc)Precio Bitcoin:%f\nd)Precio Unitario:%f\n",debitoUno,creditoUno,
	bitcoinUno,unitarioUno);
	printf("**********************************************************************\n");
	printf("Aerolineas:\na)Precio Debito:%f\nb)Precio Credito:%f\nc)Precio Bitcoin:%f\nd)Precio Unitario:%f\n",debitoDos
	,creditoDos,bitcoinDos,unitarioDos);
	printf("**********************************************************************\n");
	printf("Diferencia de Precios:%f\n",difPrecios);

}
