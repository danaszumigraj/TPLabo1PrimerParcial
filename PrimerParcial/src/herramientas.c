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

/*void ModificarDatos(int* idVivienda, char* calleVivienda[], int* cantidadPersonas, int* cantidadHabitaciones, int* tipoViviendaAux)
{
	int opcionIngresada;

	opcionIngresada = subMenu(opcionIngresada, "\nQue dato desea modificar?\n");
	do
	{
		switch(opcionIngresada)
		{
		case 1:
			utn_getName(&calleVivienda, "\nIngrese la calle de la vivienda\n", "\nEl dato ingresado no es valido\n");
		break;
		case 2:
			utn_getNumber(&cantidadPersonas, "\nIngrese la cantidad de personas\n", "\nEl dato ingresado no es valido\n", 1, 20);
		break;
		case 3:
			utn_getNumber(&cantidadHabitaciones, "\nIngrese la cantidad de habitaciones\n", "\nEl dato ingresado no es valido\n", 1, 20);
		break;
		case 4:
			utn_getNumber(&tipoViviendaAux, "\nIngrese el tipo de vivienda (1.CASA - 2.DEPARTAMENTO - 3.CASILLA - 4.RANCHO)\n", "\nEl dato ingresado no es valido\n", 1, 4);
		break;
		case 5:
			printf("\nVolviendo al menu principal...\n");
		break;
		}

	}while(opcionIngresada!=5);

}*/

