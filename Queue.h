#include "DLL.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdbool.h>



typedef struct Queue{

	 DLL* Queue;
	 int capacity;
	 // inicio
	 //final

}Queue;


Queue* Queue_New(size_t _capacity);
void Queue_Delete(DLL* this);
void Queue_Enqueue(Queue* this, int _val);
int Queue_Dequeue(Queue* this);
int Queue_Peek(Queue* this);
bool Queue_IsEmpty(Queue* this);
bool Queue_IsFull(Queue* this);
size_t Queue_Len(Queue* this);
size_t Queue_Capacity(Queue* this);
void Queue_MakeEmpty(Queue* this);


