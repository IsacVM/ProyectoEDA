#include "DLL.h"

static NodePtr newNode( Item _data )
{
	NodePtr n = (NodePtr) malloc( sizeof( Node ) );
	if( n ){
		n->data = _data;
		n->next = NULL;
		n->prev = NULL;
	}
	return n;
}

static void reset( DLL* this )
{
	this->first = this->last = this->cursor = NULL;
	this->len = 0;
}

DLL* DLL_New()
{
	DLL* list = (DLL*) malloc( sizeof( DLL ) );
	if( list ){
		reset( list );
	}
	return list;
}

void DLL_Delete( DLL* this )
{
	if( this ){
		DLL_MakeEmpty( this );
		free( this );
	}
}

bool DLL_InsertBack( DLL* this, Item _data )
{
	assert( this );
	
	bool done = false;

	NodePtr n = newNode( _data );
	if( n ){
		done = true; 

		if( DLL_IsEmpty( this ) ){
			this->first = this->last = n;
			this->len = 1;
		} else {
			this->last->next = n;
			n->prev = this->last;
			this->last = n;
			++this->len;
		}
	}
	return done;
}

bool DLL_InsertFront( DLL* this, Item _data )
{
	assert( this );
	
	bool done = false;

	NodePtr n = newNode( _data );
	if( n ){
		done = true; 
		
		if( DLL_IsEmpty( this ) ){
			this->first = this->last = n;
			this->len = 1;
		} else {
			n->next = this->first;
			this->first->prev = n;
			this->first = n;
			++this->len;
		}
	}
	return done;
}

bool DLL_InsertAfter( DLL* this, Item _data )
{
	assert( this );

	bool done = false;

	if( DLL_IsEmpty( this ) || this->cursor == this->last ){
		done = DLL_InsertBack( this, _data );
	} else {
		NodePtr n = newNode( _data );
		if( n ){
			done = true;

			n->next = this->cursor->next;
			this->cursor->next->prev = n;
			this->cursor->next = n;
			n->prev = this->cursor;
			++this->len;
		}
	}
	return done;
}

bool DLL_InsertBefore( DLL* this, Item _data )
{
    assert( this );

	bool done = false;

	if( DLL_IsEmpty( this ) || this->cursor == this->first ){
		done = DLL_InsertFront( this, _data );
	} else {
		NodePtr n = newNode( _data );
		if( n ){
			done = true;

			n->prev= this->cursor->prev;
			this->cursor->prev->next = n;
			this->cursor->prev = n;
			n->next = this->cursor;
			++this->len;
		}
	}
	return done;


}

bool DLL_Remove( DLL* this, ItemPtr _data_back )
{
	assert( this );

	bool done = false;

	if( !DLL_IsEmpty( this ) && NULL != this->cursor ){
		done = true; 

		*_data_back = this->cursor->data;

		NodePtr left = this->cursor->prev;
		NodePtr right = this->cursor->next;
		free( this->cursor );

		if( left == NULL && right == NULL ){
			reset( this );
		} else {
			this->cursor = left;
			this->cursor->next = right;
			right->prev = this->cursor;
			--this->len;
		}
	}
	return done;
}

bool DLL_RemoveFront( DLL* this, ItemPtr _data_back )
{
	assert( this );

	bool done = false;

	if( !DLL_IsEmpty( this ) ){
		done = true;
		*_data_back = this->first->data;
		NodePtr tmp = this->first->next;
		free( this->first );
		this->first = tmp;

		if( NULL != this->first ){
			this->first->prev = NULL;
			--this->len;
		} else {
			reset( this );
		}
	}
	return done;
}

bool DLL_RemoveBack( DLL* this, ItemPtr _data_back )
{
    assert( this );
	bool done = false;

	if(!DLL_IsEmpty( this ) ){
		done = true;
		//solo un elemento
		if(this->first == this->last){
			*_data_back = this->first->data;
			reset(this);
		}else{

			*_data_back = this->last->data;
			NodePtr tmp = this->last->prev;
			free(this->last);
			this->last=tmp;	
            --this->len;	
		}
	}
	return done;
}

bool DLL_RemoveAfter( DLL* this, ItemPtr _data_back )
{
    assert( this );
	bool done = false;
	
	if(!DLL_IsEmpty( this ) ){
		done = true;
		//solo un elemento, no hay un nodo después para remover
		//entonces se elimina el mismo
		if(this->first == this->last){
			*_data_back = this->first->data;
			reset(this);

        }else if(this->cursor == this->last)
        {
            done=false;
            //no se puede hacer la operación si el cursor esta en last
        
		}else{

            *_data_back=this->cursor->next->data;
            NodePtr tmp=this->cursor->next->next;
            free(this->cursor->next);
            tmp->prev=this->cursor;
            this->cursor->next=tmp;
            --this->len;
		}

	}
	return done;

}

bool DLL_RemoveBefore( DLL* this, ItemPtr _data_back )
{
    assert( this );
	bool done = false;
	
	if(!DLL_IsEmpty( this ) ){
		done = true;
	
		if(this->first == this->last){
			*_data_back = this->first->data;
			reset(this);

        }else if(this->cursor == this->first)
        {
            done=false;
            //no se puede hacer la operación si el cursor esta en first
        
		}else{

            *_data_back=this->cursor->prev->data;
            NodePtr tmp=this->cursor->prev->prev;
            free(this->cursor->prev);
            tmp->next=this->cursor;
            this->cursor->prev=tmp;
            --this->len;
		}

	}
	return done;

}

size_t DLL_Len( DLL* this )
{
	assert( this );
	return this->len;
}

bool DLL_IsEmpty( DLL* this )
{
	assert( this );
	return this->first == NULL;
}

void DLL_MakeEmpty( DLL* this )
{
	assert( this );
	while( NULL != this->first){
		NodePtr tmp = this->first->next;
		free( this->first );
		this->first = tmp;
	}
	reset( this );
}

bool DLL_Peek( DLL* this, ItemPtr _data_back )
{
   assert(this);
   bool done;
   if(!DLL_IsEmpty(this)){
       *_data_back=this->cursor->data;
       done=true;
   }
   return done;
}

void DLL_CursorFirst( DLL* this )
{
	assert( this );
	this->cursor = this->first;
}

void DLL_CursorLast( DLL* this )
{
	assert( this );
	this->cursor = this->last;
}

void DLL_CursorNext( DLL* this )
{
	assert( this );
	if( this->cursor != NULL ){
		this->cursor = this->cursor->next;
	}
}

void DLL_CursorPrev( DLL* this )
{
	assert( this );
	if( this->cursor != NULL ){
		this->cursor = this->cursor->prev;
	}
}

/*bool DLL_FindIf( DLL* this, Item _key )
{
	assert( this );

	bool found = false;
	
	for( NodePtr it = this->first; it != NULL; it = it->next ){
		if( _key == it->data ){
			found = true;
			break;
		}
	}
	return found;
}*/

bool DLL_FindIf( DLL* this, Item _key, bool (*cmp)(Item, Item) )
{
  assert( this );
  bool found = false;
  for( NodePtr it = this->first; it != NULL; it = it->next ){
	if( cmp( it->data, _key ) ){
	found = true;
	break;
	}
  }
  return found;
}

/*
bool DLL_Search( DLL* this, Item _key )
{
   assert(this);
   bool encontrado= false;
   if(!DLL_IsEmpty(this)){
       NodePtr tmp=this->cursor;
       for(this->cursor=this->first;this->cursor->next!=NULL;this->cursor=this->cursor->next)
        {
           if(_key==this->cursor->data){
               encontrado= true;
           }

       	}
       //NO ENCONTRADO
        if(!encontrado){
           this->cursor=tmp;
        }

    }
   return encontrado;
}*/

void DLL_Traverse(DLL* this, void (*pfun)(Item) )
{
	assert( this );

	for( NodePtr it = this->first; it != NULL; it = it->next){
		pfun( it->data );
	}
}

