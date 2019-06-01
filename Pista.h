/**
 * @file Pista.h
 * @Author Team
 * @date mayo 2019
 * @brief Proyecto - EDA-I
 * @note Grupo: 0007, Semestre 2019-2
 */
#ifndef _PISTA_H_
#define _PISTA_H_

#include "DLL.h"


/**
 * @typedef TDA Pista de tipo estructura.
 * @brief TDA Pista basada en Lista.
 */	
typedef struct
{
	DLLPtr track;
	int capacidad;
	int espacio_libre;
	
}Pista;

/**
 * @typedef PistaPtr Puntero a estructura Pista.
 */
typedef Pista* PistaPtr;

/**< tag::API_METODOS[] */

/**
 * @brief Crea una nueva pista
 * @param capacidad de la pista
 */
PistaPtr Pista_New(	 int _capacidad);

/**
 * @brief Permite insertar un avión a una pista de aterrizaje
 * @param apuntador a una 'Pista' y un 'Avion'
 */
bool Pista_Landing(	 PistaPtr this,Item _avion);

/**
 * @brief Permite extraer un avión de una pista de despegue
 * @param apuntador a una 'Pista' y apuntador a un 'Avion'
 */
bool Pista_Takeoff(	 PistaPtr this,ItemPtr _avion);

/**
 * @brief Imprime los datos de la pista/la pista completa con sus aviones
 * @param apuntador a una 'Pista'
 */
void Pista_Imprimir( PistaPtr this);

/**
 * @brief Elimina una pista y sus elementos
 * @param apuntador a una 'Pista'
 */
void Pista_Delete(	 PistaPtr this);

/**
 * @brief Revisa si la pista esta vacia
 * @param apuntador a una 'Pista'
 */
bool Pista_IsEmpty( PistaPtr this );

/**
 * @brief Nos permite observar y extraer el valor del ultimo 'Avion' de una pista, no lo elimina
 * @param apuntador a una 'Pista' y apuntador a un 'Avion'
 */
void Pista_Peek( PistaPtr this,ItemPtr _avion );



void Pista_sort(PistaPtr this);

#endif // _PISTA_H_