/*
 ============================================================================
 Name        : PrimerParcial
 Author      : Dana Szumigraj
 Copyright   : Your copyright notice
 Description :
 Se necesita gestionar el Censo Nacional 2022 y para eso se deberá desarrollar lo siguiente:
ENTIDADES:
VIVIENDA :
-idVivienda (comienza en 20000, autoincremental)
-calle (máximo 25 caracteres)
-cantidadPersonas
-cantidadHabitaciones
-tipoVivienda (1.CASA – 2.DEPARTAMENTO – 3.CASILLA - 4.RANCHO)
-legajoCensista (debe existir) Validar
CENSISTA :
-legajoCensista
-nombre
-edad
-telefono

DATOS PREVIOS:
El array de los censistas deberá ser hardcodeado.
Censista ({100, Ana, 34, 1203-2345}, {101, Juan, 24, 4301-54678}, {102, Sol, 47, 5902-37487} )

MENU DE OPCIONES:
A. ALTA VIVENDA
B. MODIFICAR VIVIENDA: Se ingresará el idVivienda, permitiendo en un submenú modificar:
-la calle
-la cantidad de las personas
-la cantidad de habitaciones
-el tipo de vivienda
C. BAJA VIVIENDA: Se ingresará el idVivienda y se realizará una baja lógica.
D. LISTAR VIVENDAS: Hacer un único listado de todas las viviendas ordenados por calle y ante igualdad
de calle por cantidad de personas.
E. LISTAR CENSISTAS
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "herramientas.h"
#include "utn.h"
#include "ArrayVivienda.h"
#include "ArrayCensista.h"

#define QTY_VIVIENDAS 10000
#define QTY_CENSISTAS 3

int main(void)
{
	setbuf(stdout, NULL);

	int opcionMenuPrincipal;
	//VARIABLES ARRAY VIVIENDA
	int idViviendaAux = 20000;
	char calleViviendaAux[25];
	int cantidadPersonasAux;
	int cantidadHabitacionesAux;
	int tipoViviendaAux; //1.CASA 2.DEPARTAMENTO 3.CASILLA 4.RACHO
	//VARIABLES ARRAY CENSISTA
	int legajoCensistaAux = 99; //100, 101, 102
	char nombreCensistaAux[51];
	int edadCensistaAux = 0;
	char telefonoCensistaAux[15];

	int flagPrimerIngreso = 0;
	//ARRAYS
	Vivienda listaDeViviendas [QTY_VIVIENDAS];
	Censista listaDeCensistas [QTY_CENSISTAS];
	//INICIALIZO VIVIENDAS
	if(initVivienda(listaDeViviendas, QTY_VIVIENDAS)!=0)
	{
		printf("\nHubo un error, intente nuevamente\n");
	}
	//INICIALIZO CENSISTAS
	if(initCensistas(listaDeCensistas, QTY_CENSISTAS)!=0)
	{
		printf("\nHubo un error, intente nuevamente\n");
	}
	else
	{
		agregarCensistas(listaDeCensistas, QTY_CENSISTAS, legajoCensistaAux, nombreCensistaAux, edadCensistaAux, telefonoCensistaAux); //AGREGO LOS CENSISTAS HARDCODEADOS
	}

	do
	{
		opcionMenuPrincipal = menu(opcionMenuPrincipal);//MENU PRINCIPAL
		fflush(stdin);
		switch(opcionMenuPrincipal)
		{
		//ALTA VIVIENDA
		case 'A':
			idViviendaAux++;
			utn_getName(calleViviendaAux, "\nIngrese la calle de la vivienda\n", "\nEl dato ingresado no es valido\n");
			utn_getNumber(&cantidadPersonasAux, "\nIngrese la cantidad de personas\n", "\nEl dato ingresado no es valido\n", 1, 20);
			utn_getNumber(&cantidadHabitacionesAux, "\nIngrese la cantidad de habitaciones\n", "\nEl dato ingresado no es valido\n", 1, 20);
			utn_getNumber(&tipoViviendaAux, "\nIngrese el tipo de vivienda (1.CASA - 2.DEPARTAMENTO - 3.CASILLA - 4.RANCHO)\n", "\nEl dato ingresado no es valido\n", 1, 4);
			utn_getNumber(&legajoCensistaAux, "\nIngrese el legajo del censista\n", "\nEl legajo ingresado no existe, (LEGAJOS DISPONIBLES: 100, 101, 102)\n", 100, 102);

			if(agregarVivienda(listaDeViviendas, QTY_VIVIENDAS, idViviendaAux, calleViviendaAux, cantidadPersonasAux, cantidadHabitacionesAux, tipoViviendaAux, legajoCensistaAux)==0)
			{

				printf("\nLa vivienda fue ingresada correctamente\n");
				flagPrimerIngreso=1;
			}
			else
			{
				printf("\nHubo un error al ingresar la vivienda, intente nuevamente\n");
			}
		break;
		//MODIFICAR VIVIENDA
		case 'B':
			if(flagPrimerIngreso == 1)
			{
			modificarVivienda(listaDeViviendas, QTY_VIVIENDAS, idViviendaAux, calleViviendaAux, cantidadPersonasAux, cantidadHabitacionesAux, tipoViviendaAux, legajoCensistaAux);
			}
			else
			{
				printf("\nNo hay usuarios ingresados\n"
						"\nVolviendo al menu principal...\n");
			}
		break;
		//BORRAR VIVIENDA
		case 'C':
			if(flagPrimerIngreso == 1)
			{
			borrarVivienda(listaDeViviendas, QTY_VIVIENDAS, idViviendaAux);
			}
			else
			{
				printf("\nNo hay usuarios ingresados\n"
						"\nVolviendo al menu principal...\n");
			}
		break;
		//ORDENAR Y MOSTRAR VIVIENDAS
		case 'D':
			if(flagPrimerIngreso==1)
			{
				if(ordenarViviendas(listaDeViviendas, QTY_VIVIENDAS)==0)
				{
					mostrarViviendas(listaDeViviendas, QTY_VIVIENDAS);
				}
			}
			else
			{
				printf("\nNo hay usuarios ingresados\n"
						"\nVolviendo al menu principal...\n");
			}
		break;
		//MOSTRAR LOS CENSISTAS HARDCODEADOS
		case 'E':
			mostrarCensistas(listaDeCensistas, QTY_CENSISTAS);
		break;
		//SALIR DEL MENU
		case 'F':
			printf("\nVuelva pronto!!!\n");
		break;
		//POR SI INGRESA CUALQUIER COSA
		default:
			printf("\nOpción no válida, intente nuevamente\n");
		break;
		}

	}while(opcionMenuPrincipal!='F');

}
