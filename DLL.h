#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdbool.h>

#include "Avion.h"

///Estructura de nodos contenedores
typedef struct Node     
{
	Item data;          
	struct Node* next; 
	struct Node* prev; 
} Node;               

typedef Node* NodePtr; 

//Estructura de la lista enlazada doble
typedef struct DLL
{
	NodePtr first;     
	NodePtr last;
	NodePtr cursor;
	size_t len;

} DLL;

/**Esta función crea una nueva lista DLL
*/
DLL*   DLL_New();
/**Esta función borra una lista DLL
*/
void   DLL_Delete(      DLL* this );
/**Inserta un elemento en el back de la lista
*/
bool   DLL_InsertBack(  DLL* this, Item _data );
/**Inserta un elemento en el front de la lista
*/
bool   DLL_InsertFront( DLL* this, Item _data );
/**Inserta un elemento a la derecha de donde apunte cursor
*/
bool   DLL_InsertAfter( DLL* this, Item _data );
/**Inserta un elemento a la izquierda de donde apunte cursor.
*/
bool   DLL_InsertBefore(DLL* this, Item _data );
/**Extrae el elemento a la izquierda de donde apunte cursor.
*/
bool   DLL_Remove(      DLL* this, ItemPtr _data_back );
/**Extrae un elemento del front de la lista
*/
bool   DLL_RemoveFront( DLL* this, ItemPtr _data_back );
/**Extrae un elemento del back de la lista.
*/
bool   DLL_RemoveBack(  DLL* this, ItemPtr _data_back );
/**Extrae el elemento a la derecha de donde apunte cursor
*/
bool   DLL_RemoveAfter( DLL* this, ItemPtr _data_back );
/**Extrae el elemento a la izquierda de donde apunte cursor
*/
bool   DLL_RemoveBefore(DLL* this, ItemPtr _data_back );
/**
Indica la cantidad de elementos actuales en la lista.
*/
size_t DLL_Len(         DLL* this );
/**Indica si la lista está vacía.
*/
bool   DLL_IsEmpty(     DLL* this );
/**Vacía la lista.
*/
void   DLL_MakeEmpty(   DLL* this );
/**Devuelve el valor asociado al nodo al cual apunta cursor. La lista no se altera.
*/
bool   DLL_Peek(        DLL* this, ItemPtr _data_back );
/**Coloca al cursor al principio de la lista.
*/
void   DLL_CursorFirst( DLL* this );
/**Coloca al cursor al final de la lista
*/
void   DLL_CursorLast(  DLL* this );
/**Mueve al cursor un nodo a la derecha de su posición actual. No hace nada si la lista
estuviera vacía.
*/
void   DLL_CursorNext(  DLL* this );
/**Mueve al cursor un nodo a la izquierda de su posición actual. No hace nada si la lista
estuviera vacía.
*/
void   DLL_CursorPrev(  DLL* this );
/**Recorre la lista buscando una coincidencia. Si la encuentra devuelve true; en caso
contrario devuelve false. El cursor no es afectado. Esta función se utiliza cuando
únicamente queremos saber si un valor está en la lista o no.
*/
bool DLL_FindIf( DLL* this, Item _key, bool (*cmp)(Item s0, Item s1) );
/**Recorre la lista buscando una coincidencia. Si la encuentra devuelve true y coloca al
cursor en la posición correspondiente; en caso contrario devuelve false y el cursor no se
modifica. Esta función se utiliza cuando queremos accesar, insertar a la derecha o
izquierda de, ver o remover el nodo que cumple la condición.
*/
//bool   DLL_Search(      DLL* this, Item _key );
/**Esta funcion utiliza otra funcion simple para hacer una determinada tarea
 * en este caso imprimir los elementos de la lista
*/
void   DLL_Traverse(    DLL* this, void (*pfun)(Item) );