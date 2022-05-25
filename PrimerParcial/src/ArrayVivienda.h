/*
 * ArrayVivienda.h
 *
 *  Created on: 21 may. 2022
 *      Author: Dana
 */

#ifndef ARRAYVIVIENDA_H_
#define ARRAYVIVIENDA_H_

struct
{
	int idVivienda;
	char calleVivienda[25];
	int cantidadPersonas;
	int cantidadHabitaciones;
	int tipoVivienda;
	int legajoCensista;

}typedef Vivienda;
/**
 * Inicializa el array de Viviendas
 * @param list Array vivienda
 * @param len Largo del array
 * @return Retorna 0 si no hay errores, -1 si los hay
 */
int initVivienda(Vivienda* list, int len);
/**
 * Agrega los datos previamente solicitados al array
 * @param list Array Vivienda
 * @param len Largo del Array
 * @param idVivienda
 * @param calleVivienda
 * @param cantidadPersonas
 * @param cantidadHabitaciones
 * @param tipoVivienda
 * @param legajoCensista
 * @return Retorna 0 si no hay errores, -1 si los hay
 */
int agregarVivienda(Vivienda* list, int len, int idVivienda, char calleVivienda[], int cantidadPersonas, int cantidadHabitaciones, int tipoVivienda, int legajoCensista);
/**
 * Busca una vivienda a partir de su ID
 * @param list Array Vivienda
 * @param len Largo del Array
 * @param idVivienda ID a buscar
 * @param posicionADevolver Aca se guarda el ID en caso de que haya sido encontrado
 * @return Retorna 0 si no hay errores, -1 si los hay
 */
int buscarViviendaPorId(Vivienda* list, int len, int idVivienda, int* posicionADevolver);
/**
 * Se solicita el ingreso del ID, se busca con la funcion buscarViviendaPorId y se borra
 * @param list Array Vivienda
 * @param len Largo del Array
 * @param idVivienda ID a buscar
 * @return Retorna 0 si no hay errores, -1 si los hay
 */
int borrarVivienda(Vivienda* list, int len, int idVivienda);
/**
 * Ordena las viviendas por calle, si la calle es la misma las ordena por cantidad de personas
 * @param list Array Vivienda
 * @param len Largo del Array
 * @return Retorna 0 si no hay errores, -1 si los hay
 */
int ordenarViviendas(Vivienda* list, int len);
/**
 * Recorre el array y muestra todas la viviendas ingresadas
 * @param list Array Vivienda
 * @param len Largo del array
 * @return Retorna 0 si no hay errores, -1 si los hay
 */
int mostrarViviendas(Vivienda* list, int len);
/**
 * Muestra una vivienda sola
 * @param list Array Vivienda
 * @param len Largo del Array
 * @param idVivienda ID previamente ingresado
 */
void mostrarVivienda(Vivienda* list, int len, int idVivienda);
/**
 * Pide al usuario un ID mediante, lo valida, lo busca. Muestra los datos de la vivienda y muestra un menu de modificaciones, pide el dato que el usuario
 * elija y lo cambia
 * @param list Array Vivienda
 * @param len Largo del Array
 * @param idVivienda
 * @param calleVivienda
 * @param cantidadPersonas
 * @param cantidadHabitaciones
 * @param tipoVivienda
 * @param legajoCensista
 */
void modificarVivienda(Vivienda* list, int len, int idVivienda, char calleVivienda[], int cantidadPersonas, int cantidadHabitaciones, int tipoVivienda, int legajoCensista);



#endif /* ARRAYVIVIENDA_H_ */
