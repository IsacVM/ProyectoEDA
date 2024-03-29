/**
 * @file Aviones.h
 * @Author Team
 * @date 1 junio 2019
 * @brief Proyecto - EDA-I
 * @note Grupo: 0007, Semestre 2019-2
 */
 
#ifndef _AVIONES_H_
#define _AVIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
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
	int estado; 	  /**< 1:ocupado; 2:disponible; 3: danado */
	int hora_salida;  /**< en segundos */
	int hora_llegada; /**< en segundos */
} Avion;

typedef Avion* AvionPtr;

/**< tag::API_METODOS[] */

/**
 * @brief Resetea los valores hora_llegada,hora_salida,pasajeros
 *  y estado de un avion.
 * @param apuntador a tipo avion.
 */
void Avion_Reset(AvionPtr this);


/**
 * @brief Asigna valores a los campos:hora_llegad,hora_salida,pasajeros
 *  y estado de un avion.
 * @param apuntador a tipo Avion, valor de: hora_llegada, hora_salida
 */
void Avion_Llenar(AvionPtr this,int _hora_llegada, int _hora_salida);

/**
 * @brief Resetea los valores hora_salida y hora_llegada de un avion.
 * @param apuntador a tipo Avion.
 */
void Avion_ResetHorario(AvionPtr this, int _hora_salida, int _hora_llegada);

/**
 * @brief Guarda en un archivo los campos del avion
 * @param apuntador a tip FILE
 * @param apuntador a tipo Avion.
 */
void Avion_archivo(FILE* archivo, Avion this);

#endif // _AVIONES_H_
