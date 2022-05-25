/*
 * ArrayCensista.c
 *
 *  Created on: 21 may. 2022
 *      Author: Dana
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayVivienda.h"
#include "ArrayCensista.h"
#include "utn.h"
#include "herramientas.h"

#define VACIO -1

int initCensistas(Censista* list, int len)
{
	int retorno = -1;
	if(list!= NULL && len > 0)
	{
		for (int i = 0; i < len; i++)
		{
			list[i].legajoCensista = VACIO;
		}
		retorno = 0;
	}
	return retorno;
}

int agregarCensista(Censista* list, int len, int legajoCensista, char nombreCensista[], int edadCensista, char telefonoCensista[])
{
	setbuf(stdout, NULL);
	int retorno = -1;

	if(list!=NULL && len > 0)
	{
		for(int i = 0; i<len; i++)
		{
			if(list[i].legajoCensista==VACIO)
			{
				list[i].legajoCensista = legajoCensista;
				strcpy(list[i].nombreCensista, nombreCensista);
				list[i].edadCensista = edadCensista;
				strcpy(list[i].nombreCensista, nombreCensista);
				strcpy(list[i].telefonoCensista, telefonoCensista);

				i = len+1;
				retorno = 0;
			}
		}
	}
	return retorno;
}

void agregarCensistas(Censista* list, int len, int legajoCensista, char nombreCensista[], int edadCensista, char telefonoCensista[])
{
	legajoCensista++;
	strcpy(nombreCensista, "Ana");
	edadCensista = 34;
	strcpy(telefonoCensista, "1203-2345");
	agregarCensista(list, len, legajoCensista, nombreCensista, edadCensista, telefonoCensista);

	legajoCensista++;
	strcpy(nombreCensista, "Juan");
	edadCensista = 24;
	strcpy(telefonoCensista, "4301-54678");
	agregarCensista(list, len, legajoCensista, nombreCensista, edadCensista, telefonoCensista);

	legajoCensista++;
	strcpy(nombreCensista, "Sol");
	edadCensista = 47;
	strcpy(telefonoCensista, "5902-37487");
	agregarCensista(list, len, legajoCensista, nombreCensista, edadCensista, telefonoCensista);
}

int mostrarCensistas(Censista* list, int len)
{
	int retorno = -1;
	for(int i = 0; i<len; i++)
	{
		if(list[i].legajoCensista != VACIO)
		{
			printf("\n/*************************************************************/\n"
					"\nLegajo: %d || Nombre: %s || Edad: %d || Telefono: %s \n",
					list[i].legajoCensista, list[i].nombreCensista, list[i].edadCensista, list[i].telefonoCensista);
		}
	}

	return retorno;
}
