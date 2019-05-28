/**
 * @file Stack.h
 * @Author Team
 * @date mayo 2019
 * @brief Proyecto - EDA-I
 * @note Grupo: 0007, Semestre 2019-2
 */

#ifndef _STACK_H_
#define _STACK_H_

#include "SLL.h"

/**
 * @typedef TDA Stack de tipo estructura.
 * @struct stack referida a una Pila.
 * @brief TDA pila basada en Lista.
 */
typedef struct{
    SLLPtr stack; /**< Contenedor con EDS (SLL) */
    size_t capacity;
} Stack;

/**
 * @typedef StackPtr Puntero a estructura Stack.
 */
typedef Stack* StackPtr;

/**< tag::API_METODOS[] */

/**
 * @brief Crea una Pila.
 * @param _capacity por el momento no se utiliza.
 * @return Apuntador a la Pila creada.
 */
StackPtr Stack_New( size_t _capacity );

/**
 * @brief Elimina una Pila.
 * @param this apuntador a Pila.
 */
void Stack_Delete( StackPtr this );

/**
 * @brief Inserta en la Pila.
 * @param this Apuntador a Pila, _value valor a insertar.
 * @return True si inserto, False si no.
 */
bool Stack_Push( StackPtr this, ItemI _value );

/**
 * @brief Extrae de la Pila.
 * @param this Apuntador a Pila.
 * @return Valor extraido.
 */
ItemI Stack_Pop( StackPtr this );

/**
 * @brief Muestra ultimo valor de la Pila.
 * @param this Apuntador a Pila.
 * @return Valor a mostrar.
 */
ItemI Stack_Peek( StackPtr this );

/**
 * @brief Indica si esta vacia la Pila.
 * @param this Apuntador a Pila.
 * @return True si esta vacia, False si no.
 */
bool Stack_IsEmpty( StackPtr this );

/**
 * @brief Muestra elementos en la Pila.
 * @param this Apuntador a Pila.
 * @return Cantidad de elementos en la Pila.
 */
size_t Stack_Len( StackPtr this );

/**
 * @brief Vacia la Pila
 * @param this Apuntador a Pila.
 */
void Stack_MakeEmpty( StackPtr this );


/**< end::API_METODOS[] */

/**
 * @brief Indica si esta llena la Pila.
 * @param this Apuntador a Pila.
 * @return True si esta llena, False si no.
 */
bool Stack_IsFull( StackPtr this );

/**
 * @brief Muestra capaciad de la Pila.
 * @param this Apuntador a Pila.
 * @return Capacidad de la Pila.
 */
size_t Stack_Capacity( StackPtr this );

void horarios_Init( StackPtr this,StackPtr other );


#endif  // _STACK_H_