/**
	Se modifico para funcionar con ints en vez de doubles
*/
#include "Queue.h"

Queue* Queue_New(size_t _capacity){
	Queue* q = (Queue*)malloc(sizeof(Queue));

	if(q != NULL){
		q->queue = (int*)malloc(_capacity*sizeof(int));

		if(q->queue == NULL){
			free(q);
			q = NULL;
		}else{
			q->front = 0;
			q->back = 0;
			q->len = 0;
			q->capacity = _capacity;
		}
	}
	return q;
}

void Queue_Delete(Queue* this){
	assert(this);
	free(this->queue);
	free(this);
}

void Queue_Enqueue(Queue* this, int _val){
	assert(this->back < this->capacity);

	this->queue[this->back] = _val;
	++this->back;
	++this->len;
}

int Queue_Dequeue(Queue* this){
	assert(this->len > 0);
	int f = this->queue[this->front];
	++this->front;
	--this->len;
	return f;
}

int Queue_Peek(Queue* this){
	return this->queue[this->front];
}

bool Queue_IsEmpty(Queue* this){
	return this->len == 0;
}

bool Queue_IsFull(Queue* this){
	return this->len == this->capacity ? true: false;
}

size_t Queue_Len(Queue* this){
	return this->len;
}

size_t Queue_Capacity(Queue* this){
	return this->capacity;
}

void Queue_MakeEmpty(Queue* this){
	this->front = 0;
	this->back = 0;
	this->len = 0;
}

void Queue_Imprimir(Queue* this){
	if(this->len > 0){
		for(size_t i = this->front; i<this->back; i++){
			printf("%d",this->queue[i]);
		}
		printf("\n");
	}else{
		printf("No hay elementos a imprimir. \n");
	}
}
