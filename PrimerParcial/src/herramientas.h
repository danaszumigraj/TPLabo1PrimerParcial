/*
 * herramientas.h
 *
 *  Created on: 21 may. 2022
 *      Author: Dana
 */

#ifndef HERRAMIENTAS_H_
#define HERRAMIENTAS_H_
/**
 * Muestra el menu principal y pide al usuario que ingrese una opcion
 * @param opcion Opcion del usuario
 * @return Retorna la opcion ingresada
 */
int menu(char opcion);
/**
 * Muestra el submenu para las modificaciones y pide al usuario que ingrese una opcion
 * @param opcion Opcion del usuario
 * @return Retorna la opcion ingresada
 */
int subMenu(char opcion);
/**
 * Calcula quien es el censista que realizo mas censos
 * @param legajoCensista Legajo dado
 * @param contadorViviendaAna Contador de censos de Ana
 * @param contadorViviendaJuan Contador de censos de Juan
 * @param contadorViviendaSol Contador de censos de Sol
 */
void calculoCensistaConMasCensos(int legajoCensista, int* contadorViviendaAna, int* contadorViviendaJuan, int* contadorViviendaSol);
/**
 * Muestra al censista con mas censos realizados
 * @param contadorViviendaAna Contador de censos de Ana
 * @param contadorViviendaJuan Contador de censos de Juan
 * @param contadorViviendaSol Contador de censos de Sol
 */
void mostrarCensistaConMasCensos(int* contadorViviendaAna, int* contadorViviendaJuan, int* contadorViviendaSol);


#endif /* HERRAMIENTAS_H_ */
