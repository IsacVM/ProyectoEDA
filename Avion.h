/**
 * @file Avion.h
 * @Author Team
 * @date mayo 2019
 * @brief Proyecto - EDA-I
 * @note Grupo: 0007, Semestre 2019-2
 */
 
#ifndef _AVION_H_
#define _AVION_H_

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/**
 * @typedef Avion de tipo estructura.
 * @struct Avion 
 * @brief campos en Avion
 */
typedef struct
{
	char _nombre[20];
	int pasajeros;
	int capacidad;
	int estado; //1=ocupado,2=disponible,3=danado
	int hora_salida;//en segundos
	int hora_llegada;//en segundos
}Avion;


/**< tag::API_METODOS[] */

/**
 * @brief Resetea los valores hora_llegada,hora_salida,pasajeros
 *  y estado de un avion.
 * @param apuntador a tipo avion.
 */
void Avion_Reset(Avion* this);


/**
 * @brief Asigna valores a los campos:hora_llegad,hora_salida,pasajeros
 *  y estado de un avion.
 * @param apuntador a tipo Avion, valor de: hora_llegada, hora_salida
 */
void Avion_Llenar(Avion* this,int _hora_llegada, int _hora_salida);


/**
 * @brief Libera memoria utilizada por un avion.
 * @param apuntador a tipo Avion.
 */
void Avion_Delete(Avion* this);


/**
 * @brief Resetea los valores hora_salida y hora_llegada de un avion.
 * @param apuntador a tipo Avion.
 */
void Avion_ResetHorario(Avion* this, int _hora_salida, int _hora_llegada);

#endif // _AVION_H_