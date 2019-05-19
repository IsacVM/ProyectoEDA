/**
 * @file SLL.h
 * @Author Team
 * @date mayo 2019
 * @brief Proyecto - EDA-I
 * @note Grupo: 0007, Semestre 2019-2
 */

#ifndef _SLL_H_
#define _SLL_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

/**
 * @typedef ItemI tipo Entero para horarios
 */
typedef int ItemI;

/**
 * @typedef ItemIPtr Apuntador a tipo de dato.
 */
typedef ItemI* ItemIPtr;

/**
 * @typedef NodeS de tipo estructura autoreferenciada.
 * @struct NodeS referida a un nodo dinamico.
 * @brief Nodo con dato, enlaces anterior y posterior.
 */
typedef struct NodeS{
    ItemI data;
    struct NodeS* next;
} NodeS;

/**
 * @typedef NodeSPtrS Apuntador a nodo.
 */
typedef NodeS* NodeSPtrS;

/**
 * @typedef SLL de tipo estructura.
 * @struct SLL referida a una Lista.
 * @brief Lista con apuntadores a nodos.
 */
typedef struct SLL{
    NodeSPtrS first;
    NodeSPtrS last;
    NodeSPtrS cursor;
    size_t len;
} SLL;

/**
 * @typedef DLLPtr Apuntador a Lista DLL.
 */
typedef SLL* SLLPtr;

/**
 * @brief Crea una SLL.
 * @return Apuntador a la SLL creada.
 */
SLLPtr SLL_New( );

/**
 * @brief Borra una SLL.
 * @param this Puntero a SLL.
 */
void SLL_Delete( SLLPtr this );

/**
 * @brief Inserta en el Front.
 * @param this Puntero a SLL, _data valor a insertar.
 * @return True si inserto, False si no.
 */
bool SLL_InsertFront( SLLPtr this, ItemI _data );

/**
 * @brief Inserta en el Back.
 * @param this Puntero a SLL, _data valor a insertar.
 * @return True si inserto, False si no.
 */
bool SLL_InsertBack( SLLPtr this, ItemI _data );

/**
 * @brief Inserta delante del cursor.
 * @param this Puntero a SLL, _data valor a insertar.
 * @return True si inserto, False si no.
 */
bool SLL_InsertAfter( SLLPtr this, ItemI _data );

/**
 * @brief Extrae valor en el Front.
 * @param this Puntero a SLL, _data_back valor devuelto.
 * @return True si removio, False si no.
 */
bool SLL_RemoveFront( SLLPtr this, ItemIPtr _data_back );

/**
 * @brief Muestra el valor al que apunta el cursor.
 * @param this Puntero a SLL, _data_back el valor a mostrar.
 * @return True si muestra valor, False si no.
 */
bool SLL_Peek( SLLPtr this, ItemIPtr _data_back );

/**
 * @brief Indica cuantos elemtos hay en la SLL.
 * @param this Puntero a SLL.
 * @return Elementos o nodos en la SLL.
 */
size_t SLL_Len( SLLPtr this );

/**
 * @brief Indica si esta vacia la SLL.
 * @param this Puntero a SLL.
 * @return True si esta vacia, False si no.
 */
bool SLL_IsEmpty( SLLPtr this );

/**
 * @brief Vacia la SLL.
 * @param this Puntero a SLL.
 */
void SLL_MakeEmpty( SLLPtr this );

/**
 * @brief Mueve el cursor a first.
 * @param this Puntero a SLL.
 */
void SLL_CursorFirst( SLLPtr this );

/**
 * @brief Mueve el cursor a last.
 * @param this Puntero a SLL.
 */
void SLL_CursorLast( SLLPtr this );

/**
 * @brief Mueve el cursor al siguiente nodo.
 * @param this Puntero a SLL.
 */
void SLL_CursorNext( SLLPtr this );

/**
 * @brief Busca valor en la SLL.
 * @param this Puntero a SLL, _data valor a buscar.
 * @return True si encontro, False si no.
 */
bool SLL_FindIf( SLLPtr this, ItemI _data );

/**
 * @brief Busca valor en la SLL y lo apunta con cursor.
 * @param this Puntero a SLL, _data valor a buscar.
 * @return True si encontro, False si no.
 */
bool SLL_Search( SLLPtr this, ItemI _data );

#endif  // _SLL_H_
