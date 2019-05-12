#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdbool.h>




//cambiar ints a aviones
Queue* Queue_New(size_t _capacity){

	DLL* d_lista = DLL_New();
	this->capacity= _capacity;
	this->len=0;

}


void Queue_Delete(Queue* this){
	DLL_Delete(this);
	free(this);
}
void Queue_Enqueue(Queue* this, int _val){
	assert(this);
	DLL_InsertBack(this, _val);
	this->len+=1;
}
int Queue_Dequeue(Queue* this){
	assert(this);
	int salida;
	DLL_RemoveFront(this,salida);
	this->len-=1;
	return salida;
}
int Queue_Peek(Queue* this){

	int pik;
	DLL_Peek(this,&pik);
	return pik;
}
bool Queue_IsEmpty(Queue* this){
	if(DLL_IsEmpty(this)){
		return true;
	}else{
		return false;
	}
}
bool Queue_IsFull(Queue* this){
	return this->capacity==this->len;
}
size_t Queue_Len(Queue* this){
	return this->len;
}
size_t Queue_Capacity(Queue* this){
	return this->capacity;
}
void Queue_MakeEmpty(Queue* this){
	DLL_MakeEmpty(this);
	this->len=0;
}


