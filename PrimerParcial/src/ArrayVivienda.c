/*
 * ArrayVivienda.c
 *
 *  Created on: 21 may. 2022
 *      Author: Dana
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayVivienda.h"
#include "utn.h"
#include "herramientas.h"

#define VACIO 1


int initVivienda(Vivienda* listV, int len)
{
	int retorno = -1;
	if(listV!= NULL && len > 0)
	{
		for (int i = 0; i < len; i++)
		{
			listV[i].idVivienda = VACIO;
		}
		retorno = 0;
	}
	return retorno;
}

int agregarVivienda(Vivienda* listV, int len, int idVivienda, char calleVivienda[], int cantidadPersonas, int cantidadHabitaciones, int tipoVivienda, int legajoCensistaV)
{
	setbuf(stdout, NULL);
	int retorno = -1;

	if(listV!=NULL && len > 0)
	{
		for(int i = 0; i<len; i++)
		{
			if(listV[i].idVivienda==VACIO)
			{
				listV[i].idVivienda = idVivienda;
				strcpy(listV[i].calleVivienda, calleVivienda);
				listV[i].cantidadPersonas = cantidadPersonas;
				listV[i].cantidadHabitaciones = cantidadHabitaciones;
				listV[i].tipoVivienda = tipoVivienda;
				listV[i].legajoCensistaV = legajoCensistaV;

				printf("\nEl ID generado es: %d\n", idVivienda);
				i = len+1;
				retorno = 0;
			}
		}
	}
	return retorno;
}

int buscarViviendaPorId(Vivienda* listV, int len, int idVivienda, int* posicionADevolver)
{
	int retorno= -1;
	if(listV!=NULL && len > 0)
	{
		for(int i = 0; i<len;i++)
		{
			if(listV[i].idVivienda == idVivienda)
			{
				*posicionADevolver = i;
				retorno = 0;
			}
		}
	}
	return retorno;
}

int borrarVivienda(Vivienda* listV, int len, int idVivienda)
{
	int retorno = -1;
	int i;
	char respuesta;

	if (listV!=NULL && len>0)
	{
		utn_getNumber(&idVivienda, "\nIngrese el ID de la vivienda\n", "\nEl ID ingresado no es un numero valido, intente nuevamente\n", 20000, len);//PIDO ID

		if(buscarViviendaPorId(listV, len, idVivienda, &i) == -1)//BUSCO ID
		{
			printf("\nEl ID ingresado no existe, intente nuevamente\n");
		}
		else
		{
			mostrarVivienda(listV, len, idVivienda);//MUESTRO VIVIENDA ENCONTRADA
			printf("\nEsta seguro de que quiere eliminar a la vivienda correspondiente al id %d? (Ingrese s/n)\n", idVivienda);//CONSULTO SI QUIERE BORRARLA
			fflush(stdin);
			scanf("%c", &respuesta);
			while(respuesta!= 's' && respuesta != 'n')//VALIDO QUE INGRESE s/n
			{
				printf("\nEsta seguro de que quiere eliminar a la vivienda correspondiente al id %d? (Ingrese SOLO s/n)\n", idVivienda);
				fflush(stdin);
				scanf("%c", &respuesta);
			}

			if(respuesta == 's')
			{
				listV[i].idVivienda = VACIO;//BORRO ID
				printf("\nLa vivienda fue eliminada correctamente\n");
				retorno = 0;
			}
			else
			{
				printf("\nVolviendo al menu principal...\n");
			}
		}
	}

	return retorno;
}

int ordenarViviendas(Vivienda* listV, int len)
{
	int retorno = -1;
	int value = 0;

	Vivienda listAux;

	if(listV!=NULL && len>0)
	{
		for(int i=0; i<len; i++)
		{
			for(int j=i+1; j<len;j++)
			{
				value = strcmp(listV[i].calleVivienda, listV[j].calleVivienda);
				if(listV[i].calleVivienda == listV[j].calleVivienda)
				{
					if(listV[i].cantidadPersonas>listV[j].cantidadPersonas)
					{
						value = 1;
					}
				}
				if(value==1)
				{
					value = 0;

					listAux = listV[i];
					listV[i]=listV[j];
					listV[j]=listAux;
					j = i+1;
				}

			}
		}
		retorno = 0;
	}
	return retorno;
}

int mostrarViviendas(Vivienda* listV, int len)
{
	char tipoDeVivienda[30];

	for(int i = 0; i<len; i++)
	{
		if(listV[i].idVivienda != VACIO)
		{
			if (listV[i].tipoVivienda == 1)
			{
				strcpy(tipoDeVivienda, "Casa");
			}
			else if(listV[i].tipoVivienda == 2)
				{
					strcpy(tipoDeVivienda, "Departamento");
				}
				else if(listV[i].tipoVivienda == 3)
				{
					strcpy(tipoDeVivienda, "Casilla");
				}
					else
					{
						strcpy(tipoDeVivienda, "Rancho");
					}

					printf("\n/-------------------------------------------------------------------------------------------------------------------------------------------/\n"
								"\nID: %d || Calle: %s || Cantidad de Personas: %d || Cantidad de Habitaciones: %d ||   Tipo Vivienda: %s   || Legajo del Censista: %d \n",
								listV[i].idVivienda, listV[i].calleVivienda, listV[i].cantidadPersonas, listV[i].cantidadHabitaciones, tipoDeVivienda, listV[i].legajoCensistaV);
		}
	}
	return 0;
}

void mostrarVivienda(Vivienda* listV, int len, int idVivienda)
{
	char tipoDeVivienda[30];

	for(int i = 0; i<len; i++)
	{
		if(listV[i].idVivienda == idVivienda)
		{
			if (listV[i].tipoVivienda == 1)
			{
				strcpy(tipoDeVivienda, "Casa");
			}
			else if(listV[i].tipoVivienda == 2)
				{
					strcpy(tipoDeVivienda, "Departamento");
				}
				else if(listV[i].tipoVivienda == 3)
				{
					strcpy(tipoDeVivienda, "Casilla");
				}
					else
					{
						strcpy(tipoDeVivienda, "Rancho");
					}

					printf("\n/-------------------------------------------------------------------------------------------------------------------------------------------/\n"
								"\nID: %d || Calle: %s || Cantidad de Personas: %d || Cantidad de Habitaciones: %d ||   Tipo Vivienda: %s   || Legajo del Censista: %d \n"
								"\n/-------------------------------------------------------------------------------------------------------------------------------------------/\n",
								listV[i].idVivienda, listV[i].calleVivienda, listV[i].cantidadPersonas, listV[i].cantidadHabitaciones, tipoDeVivienda, listV[i].legajoCensistaV);
		}
	}
}

void mostrarViviendaPorLegajo(Vivienda* listV, int len, int legajoCensistaV)
{
	char tipoDeVivienda[30];

	for(int i = 0; i<len; i++)
	{
		if(listV[i].legajoCensistaV == legajoCensistaV)
		{
			if (listV[i].tipoVivienda == 1)
			{
				strcpy(tipoDeVivienda, "Casa");
			}
			else if(listV[i].tipoVivienda == 2)
				{
					strcpy(tipoDeVivienda, "Departamento");
				}
				else if(listV[i].tipoVivienda == 3)
				{
					strcpy(tipoDeVivienda, "Casilla");
				}
					else
					{
						strcpy(tipoDeVivienda, "Rancho");
					}

					printf("\n/-------------------------------------------------------------------------------------------------------------------------------------------/\n"
							"\nID: %d || Calle: %s || Cantidad de Personas: %d || Cantidad de Habitaciones: %d ||   Tipo Vivienda: %s   || Legajo del Censista: %d \n",
							listV[i].idVivienda, listV[i].calleVivienda, listV[i].cantidadPersonas, listV[i].cantidadHabitaciones, tipoDeVivienda, listV[i].legajoCensistaV);
		}
	}
}

void modificarVivienda(Vivienda* listV, int len, int idVivienda, char calleVivienda[], int cantidadPersonas, int cantidadHabitaciones, int tipoVivienda, int legajoCensistaV)
{
	int i;
	int opcionSubMenu;
	utn_getNumber(&idVivienda, "\nIngrese el ID de la vivienda\n", "\nEl ID igresado no es valido\n", 0, len); //PIDO ID AL USUARIO
	if(buscarViviendaPorId(listV, len, idVivienda, &i)==-1) //BUSCO EL ID
	{
		printf("\nEl ID ingresado no pudo ser encontrado, intente nuevamente\n");
	}
	else
	{
		printf("\nID encontrado con exito\n");
		do
		{
			mostrarVivienda(listV, len, idVivienda); //MUESTRO LA VIVIENDA ENCONTRADA
			opcionSubMenu = subMenu(opcionSubMenu); //SUBMENU DE MODIFICACIONES
			fflush(stdin);
			switch(opcionSubMenu) //ANALIZO OPCION INGRESADA
			{
			case 'A'://CALLE
				if(utn_getName(calleVivienda, "\nIngrese la calle de la vivienda\n", "\nEl dato ingresado no es valido\n") == 0)
				{
					strcpy(listV[i].calleVivienda, calleVivienda);
					printf("Calle modificada con exito");
				}
				else
				{
					printf("\nIntente nuevamente...");
				}

			break;
			case 'B'://CANTIDAD DE PERSONAS
				if(utn_getNumber(&cantidadPersonas, "\nIngrese la cantidad de personas\n", "\nEl dato ingresado no es valido\n", 1, 20)==0)
				{
					listV[i].cantidadPersonas = cantidadPersonas;
					printf("\nLa cantidad de personas fue modificada con exito\n");
				}
				else
				{
					printf("\nIntente nuevamente...");
				}
			break;
			case 'C'://CANTIDAD DE HABITACIONES
				if(utn_getNumber(&cantidadHabitaciones, "\nIngrese la cantidad de habitaciones\n", "\nEl dato ingresado no es valido\n", 1, 20)==0)
				{
					listV[i].cantidadHabitaciones = cantidadHabitaciones;
					printf("\nLa cantidad de habitaciones fue modificada con exito\n");
				}
				else
				{
					printf("\nIntente nuevamente...");
				}
			break;
			case 'D'://TIPO VIVIENDA
				if(utn_getNumber(&tipoVivienda, "\nIngrese el tipo de vivienda (1.CASA - 2.DEPARTAMENTO - 3.CASILLA - 4.RANCHO)\n", "\nEl dato ingresado no es valido\n", 1, 20)==0)
				{
					listV[i].tipoVivienda = tipoVivienda;
					printf("\nEl tipo de vivienda fue modificado con exito\n");
				}
				else
				{
					printf("\nIntente nuevamente...");
				}
			break;
			case 'E'://SALIR DEL SUBMENU
				printf("\nVolviendo al menu principal...\n");
			break;
			default://POR SI INGRESA CUALQUIER COSA
				printf("\nOpcion no valida, intente nuevamente\n");
			break;
			}
		}while(opcionSubMenu!='E');
	}
}


