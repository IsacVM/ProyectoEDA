
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct {
	int* queue;   /**!< Contenedor de la cola. Es un arreglo dinamico de reales*/
	size_t front;    /**!< Índice al elemento mas antiguo. */
	size_t back;     /**!< Índice al elemento mas reciente. */
	size_t len;      /**!< NUmero actual de elementos en la cola*/
	size_t capacity; /**!<Numero maximo de elemetos en la cola*/
}Queue;

Queue* Queue_New(size_t _capacity);
void Queue_Delete(Queue* this);
void Queue_Enqueue(Queue* this, int _val);
int Queue_Dequeue(Queue* this);
int Queue_Peek(Queue* this);
bool Queue_IsEmpty(Queue* this);
bool Queue_IsFull(Queue* this);
size_t Queue_Len(Queue* this);
size_t Queue_Capacity(Queue* this);
void Queue_MakeEmpty(Queue* this);

void Queue_Imprimir(Queue* this);
