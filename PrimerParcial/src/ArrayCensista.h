/*
 * ArrayCensista.h
 *
 *  Created on: 21 may. 2022
 *      Author: Dana
 */

#ifndef ARRAYCENSISTA_H_
#define ARRAYCENSISTA_H_

struct
{
	int legajoCensista;
	char nombreCensista[51];
	int edadCensista;
	char telefonoCensista[15];

}typedef Censista;
/**
 * Inicializa el Array de los Censistas para que no haya basura al momento de mostrar los datos
 * @param list Array Censista
 * @param len Largo del Array
 * @return Retorna 0 si no hay errores, -1 si los hay
 */
int initCensistas(Censista* list, int len);
/**
 * Agrega el censista al Array
 * @param list Array Censista
 * @param len Largo del Array
 * @param legajoCensista
 * @param nombreCensista
 * @param edadCensista
 * @param telefonoCensista
 * @return Retorna 0 si no hay errores, -1 si los hay
 */
int agregarCensista(Censista* list, int len, int legajoCensista, char nombreCensista[], int edadCensista, char telefonoCensista[]);
/**
 * Agrega los censistas hardcodeados al array, utiliza la funcion agregarCensista por cada censista hardcodeado
 * @param list Array Censista
 * @param len Largo del Array
 * @param legajoCensista
 * @param nombreCensista
 * @param edadCensista
 * @param telefonoCensista
 */
void agregarCensistas(Censista* list, int len, int legajoCensista, char nombreCensista[], int edadCensista, char telefonoCensista[]);
/**
 * Muestra los censistas ingresados
 * @param list Array Censista
 * @param len Largo del Array
 * @return Retorna 0 si no hay errores, -1 si los hay
 */
int mostrarCensistas(Censista* list, int len);

#endif /* ARRAYCENSISTA_H_ */
