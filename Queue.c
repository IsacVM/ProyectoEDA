Queue* Queue_New(size_t _capacity){

	DLL* d_lista = DLL_New();
	this->capacity= _capacity;

}


void Queue_Delete(Queue* this){
	DLL_Delete(this);
}
void Queue_Enqueue(Queue* this, int _val);
int Queue_Dequeue(Queue* this);
int Queue_Peek(Queue* this);
bool Queue_IsEmpty(Queue* this);
bool Queue_IsFull(Queue* this);
size_t Queue_Len(Queue* this);
size_t Queue_Capacity(Queue* this);
void Queue_MakeEmpty(Queue* this);


