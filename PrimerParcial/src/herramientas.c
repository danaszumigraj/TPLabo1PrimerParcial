/*
 * herramientas.c
 *
 *  Created on: 21 may. 2022
 *      Author: Dana
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "herramientas.h"
#include "utn.h"
#include "ArrayVivienda.h"


int menu(char opcion)
{
		printf("\nA. ALTA VIVIENDA\n"
				"B. MODIFICAR VIVIENDA\n"
				"C. BAJA VIVIENDA\n"
				"D. LISTAR VIVIENDAS\n"
				"E. LISTAR CENSISTAS\n"
				"F. SALIR\n");

	printf("\nIngrese una opción: \n");
	fflush(stdin);
	scanf("%c", &opcion);
	opcion = toupper(opcion);

	return (opcion);
}

int subMenu(char opcion)
{
	printf("A. CALLE\n"
			"B. CANTIDAD DE PERSONAS\n"
			"C. CANTIDAD DE HABITACIONES\n"
			"D. TIPO DE VIVIENDA\n"
			"E. SALIR\n");
	printf("\nQue dato desea modificar?\n");
	fflush(stdin);
	scanf("%c", &opcion);
	opcion = toupper(opcion); //SE PASA LA LETRA INGRESADA A MAYUS

	return opcion;
}

void calculoCensistaConMasCensos(int legajoCensista, int* contadorViviendaAna, int* contadorViviendaJuan, int* contadorViviendaSol)
{
	if(legajoCensista == 100)
	{
		*contadorViviendaAna = *contadorViviendaAna + 1;
	}
	else if(legajoCensista == 101)
	{
		*contadorViviendaJuan = *contadorViviendaJuan + 1;
	}
	else
	{
		*contadorViviendaSol = *contadorViviendaSol + 1;
	}


}

void mostrarCensistaConMasCensos(int* contadorViviendaAna, int* contadorViviendaJuan, int* contadorViviendaSol)
{
	char censistaAMostrar[25];

	if(*contadorViviendaAna > *contadorViviendaJuan)
	{
		strcpy(censistaAMostrar, "Ana");
		if(*contadorViviendaAna == *contadorViviendaSol)
		{
			strcpy(censistaAMostrar, "Ana y Sol");
		}
	}
	else if(*contadorViviendaJuan > *contadorViviendaSol)
		{
			strcpy(censistaAMostrar, "Juan");
			if(*contadorViviendaJuan == *contadorViviendaAna)
			{
				strcpy(censistaAMostrar, "Juan y Ana");
			}
		}
		else if(*contadorViviendaSol > *contadorViviendaJuan && *contadorViviendaSol > *contadorViviendaAna)
		{
			strcpy(censistaAMostrar, "Sol");
			if(*contadorViviendaSol == *contadorViviendaJuan)
			{
				strcpy(censistaAMostrar, "Sol y Juan");
			}
		}
		else if(*contadorViviendaSol == *contadorViviendaJuan && *contadorViviendaSol == *contadorViviendaAna)
		{
			strcpy(censistaAMostrar, "Ana, Juan y Sol");
		}


	printf("\nLos censistas con mas censos realizados fueron %s\n", censistaAMostrar);
}

