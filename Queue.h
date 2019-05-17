#include "DLL.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdbool.h>



typedef struct Queue{

	DLL* Queue;
	int capacity;
	int len;
	 //final

}Queue;


Queue* Queue_New(size_t _capacity);
void Queue_Delete(DLL* this);
void Queue_Enqueue(DLL* this, int _val);
int Queue_Dequeue(DLL* this);
int Queue_Peek(DLL* this);
bool Queue_IsEmpty(DLL* this);
bool Queue_IsFull(DLL* this);
size_t Queue_Len(DLL* this);
size_t Queue_Capacity(DLL* this);
void Queue_MakeEmpty(DLL* this);


