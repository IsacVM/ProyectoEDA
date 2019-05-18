/**
 * @file DLL.h
 * @Author Team
 * @date mayo 2019
 * @brief Proyecto - EDA-I
 * @note Grupo: 0007, Semestre 2019-2
 */

#ifndef _DLL_H_
#define _DLL_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include "Avion.h"

/**
 * @typedef NodeS de tipo estructura autoreferenciada.
 * @struct NodeS referida a un nodo dinamico.
 * @brief Nodo con dato, enlaces anterior y posterior.
 */
typedef struct Node
{
	Item data;          
	struct Node* next; 
	struct Node* prev; 
} Node;               

/**
 * @typedef NodePtr Apuntador a nodo.
 */
typedef Node* NodePtr; 

/**
 * @typedef DLL de tipo estructura.
 * @struct DLL referida a una Lista.
 * @brief Lista con apuntadores a nodos.
 */
typedef struct DLL
{
	NodePtr first;     
	NodePtr last;
	NodePtr cursor;
	size_t len;

} DLL;


/**
 * @brief Crea una DLL.
 * @return Apuntador a la DLL creada.
 */
DLL*   DLL_New();


/**
 *  @brief Borra una SLL.
 ** @param this Puntero a DLL.
 */ 
void   DLL_Delete( DLL* this );



/**
 * @brief Inserta en el Back.
 * @param this Puntero a DLL, _data valor a insertar.
 * @return True si inserto, False si no.
 */
bool   DLL_InsertBack(  DLL* this, Item _data );



/**
 * @brief Inserta en el Front.
 * @param this Puntero a DLL, _data valor a insertar.
 * @return True si inserto, False si no.
 */
bool   DLL_InsertFront( DLL* this, Item _data );



/**
 * @brief Inserta a la derecha del cursor.
 * @param this Puntero a DLL, _data valor a insertar.
 * @return True si inserto, False si no.
 */
bool   DLL_InsertAfter( DLL* this, Item _data );



/**
 * @brief Inserta a la izquierda del cursor.
 * @param this Puntero a DLL, _data valor a insertar.
 * @return True si inserto, False si no.
 */
bool   DLL_InsertBefore(DLL* this, Item _data );



/**
 * @brief Extrae valor donde apunta cursor.
 * @param this Puntero a DLL, _data_back valor devuelto.
 * @return True si removio, False si no.
 */
bool   DLL_Remove(      DLL* this, ItemPtr _data_back );



/**
 * @brief Extrae valor en el Front.
 * @param this Puntero a DLL, _data_back valor devuelto.
 * @return True si removio, False si no.
 */
bool   DLL_RemoveFront( DLL* this, ItemPtr _data_back );



/**
 * @brief Extrae valor en el Back.
 * @param this Puntero a DLL, _data_back valor devuelto.
 * @return True si removio, False si no.
 */
bool   DLL_RemoveBack(  DLL* this, ItemPtr _data_back );



/**
 * @brief Extrae valor a la derecha de donde apunta cursor.
 * @param this Puntero a DLL, _data_back valor devuelto.
 * @return True si removio, False si no.
 */
bool   DLL_RemoveAfter( DLL* this, ItemPtr _data_back );



/**
 * @brief Extrae valor a la izquierda de donde apunta cursor.
 * @param this Puntero a DLL, _data_back valor devuelto.
 * @return True si removio, False si no.
 */
bool   DLL_RemoveBefore(DLL* this, ItemPtr _data_back );



/**
 * @brief Indica cantidad de elementos actuales en la DLL.
 * @param this Puntero a DLL.
 * @return Elementos o nodos en la DLL.
 */
size_t DLL_Len(         DLL* this );



/**
 * @brief Indica si esta vacia la DLL.
 * @param this Puntero a DLL.
 * @return True si esta vacia, False si no.
 */
bool   DLL_IsEmpty(     DLL* this );



/**
 * @brief Vacia la DLL.
 * @param this Puntero a DLL.
 */
void   DLL_MakeEmpty(   DLL* this );



/**
 * @brief Muestra el valor al que apunta el cursor. Sin alterar la lista
 * @param this Puntero a DLL, _data_back el valor a mostrar.
 * @return True si muestra valor, False si no.
 */
bool   DLL_Peek(        DLL* this, ItemPtr _data_back );



/**
 * @brief Coloca el cursor en First.
 * @param this Puntero a DLL.
 */
void   DLL_CursorFirst( DLL* this );



/**
 * @brief Coloca el cursor en Last.
 * @param this Puntero a DLL.
 */
void   DLL_CursorLast(  DLL* this );



/**
 * @brief Mueve el cursor al siguiente nodo.
 * @param this Puntero a DLL.
 * @pre La lista no debe estar vacia
*/
void   DLL_CursorNext(  DLL* this );



/**
 * @brief Regresa el cursor un nodo.
 * @param this Puntero a DLL.
 * @pre La lista no debe estar vacia
*/
void   DLL_CursorPrev(  DLL* this );



/**
 * @brief Busca valor en la DLL.
 * @param this Puntero a DLL, _data valor a buscar.
 * @return True si encontro, False si no.
 * @post La pocision del cursor no se modifica.
 */
bool DLL_FindIf( DLL* this, Item _key, bool (*cmp)(Item s0, Item s1) );



/**
 * @brief Busca valor en la DLL
 * @param this Puntero a DLL, _data valor a buscar.
 * @return True si encontro, False si no.
 * @post Coloca al cursor en el nodo donde encontro el valor. 
 */

//bool   DLL_Search(      DLL* this, Item _key );

bool   DLL_Search(      DLL* this, char* _key );



/**
 * @brief Realiza una funcion inyectada. En este caso: Imprimir.
 * @param this Puntero a DLL, funcion a inyectar
 */
void   DLL_Traverse(    DLL* this, void (*pfun)(Item) );

#endif // _DLL_H_
