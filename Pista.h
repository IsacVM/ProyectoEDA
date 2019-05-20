/**
 * @file Pista.h
 * @Author Team
 * @date mayo 2019
 * @brief Proyecto - EDA-I
 * @note Grupo: 0007, Semestre 2019-2
 */
#ifndef _PILA_H_
#define _PILA_H_

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

//se crea una nueva pista
PistaPtr Pista_New(	 int _capacidad);
//aterriza el avion, si si pudo aterrizar true
bool Pista_Landing(	 PistaPtr this,Item _avion);
//despega un avion, sipudo, true
bool Pista_Takeoff(	 PistaPtr this,ItemPtr _avion);
//imprime los datos de la pista/la pista completa
void Pista_Imprimir( PistaPtr this);
//elimina la pista
void Pista_Delete(	 PistaPtr this);
//se revisa si la pista esta vacia
bool Pista_IsEmpty( PistaPtr this );
//funcion Peek(observar) para una pista
void Pista_Peek( PistaPtr this,ItemPtr _avion );

#endif // _PISTA_H_