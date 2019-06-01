/******         DLL.c         ******/

#include "DLL.h"

// corregir el 2 en el nombre de la funcion
void Segundos_a_horas(Item this, int* _h1, int* _m1,int* _h2, int* _m2){

    *_h1=this.hora_salida/3600;
    *_m1=(this.hora_salida%3600)/60;
    *_h2=this.hora_llegada/3600;
    *_m2=(this.hora_llegada%3600)/60;

}

void print( Item item )
{
    printf("Avion: %s\n", item._nombre);
    printf("Pasajeros: %d\n",item.pasajeros);
    printf("Capacidad: %d\n", item.capacidad);
    if(item.estado==1)printf("Estado: Ocupado\n");
    if(item.estado==2)printf("Estado: Disponible\n");
    if(item.estado==3)printf("Estado: Danado\n");
    int h1,m1,h2,m2;
    Segundos_a_horas(item,&h1,&m1,&h2,&m2);
    printf("Hora salida: %02d:%02d\n",h1,m1);
    printf("Hora llegada: %02d:%02d\n",h2,m2);
    printf("\n\n");
    sleep(1);
}

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

static void reset( DLLPtr this )
{
	this->first = this->last = this->cursor = NULL;
	this->len = 0;
}

DLLPtr DLL_New()
{
	DLLPtr list = (DLLPtr) malloc( sizeof( DLL ) );
	if( list ){
		reset( list );
	}
	return list;
}

void DLL_Delete( DLLPtr this )
{
	if( this ){
		DLL_MakeEmpty( this );
		free( this );
	}
}

bool DLL_InsertBack( DLLPtr this, Item _data )
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

bool DLL_InsertFront( DLLPtr this, Item _data )
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

bool DLL_InsertAfter( DLLPtr this, Item _data )
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

bool DLL_InsertBefore( DLLPtr this, Item _data ){
    assert( this );
	bool done = false;

	if( DLL_IsEmpty( this ) || this->cursor == this->first ){
		done = DLL_InsertFront( this, _data );
	} else {
		NodePtr n = newNode( _data );
		if( n ){
			done = true;

			n->prev = this->cursor->prev;
			this->cursor->prev->next = n;
			this->cursor->prev = n;
			n->next = this->cursor;
			++this->len;
		}
	}
	return done;
}

bool DLL_Remove( DLLPtr this, ItemPtr _data_back )
{
	assert( this );
	bool done = false;

	if( !DLL_IsEmpty( this ) && this->cursor != NULL ){
		done = true;
		*_data_back = this->cursor->data;

		NodePtr left = this->cursor->prev;
		NodePtr right = this->cursor->next;
		free( this->cursor );
		this->cursor = NULL;
        --this->len;

		if( NULL == left && right == NULL ){ reset( this ); }
		else if( NULL == right ){
                left->next = NULL;
                this->last = left;
        }
		else if( NULL == left){
                right->prev = NULL;
                this->first = right;
        }
		else{
            left->next = right;
            right->prev = left;
		}
	}
	return done;
}

bool DLL_RemoveFront( DLLPtr this, ItemPtr _data_back )
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

bool DLL_RemoveBack( DLLPtr this, ItemPtr _data_back ){
    assert( this );
	bool done = false;

	if( !DLL_IsEmpty( this ) ){
	    done = true;
		*_data_back = this->last->data;

		NodePtr tmp = this->last->prev;
		free( this->last );
		this->last = tmp;

		if( this->last != NULL ){
			this->last->next = NULL;
			--this->len;
		} else {
			reset( this );
		}
	}
	return done;
}


bool DLL_RemoveAfter( DLLPtr this, ItemPtr _data_back ){
    assert( this );
	bool done = false;

	if( !DLL_IsEmpty( this ) && this->cursor->next != NULL ){
		done = true;
		*_data_back = this->cursor->next->data;

		NodePtr right = this->cursor->next->next;
		free( this->cursor->next );

		if( right == NULL ){
			this->cursor->next = NULL;
		} else {
			this->cursor->next = right;
			right->prev = this->cursor;
			--this->len;
		}
	}
	return done;
}


bool DLL_RemoveBefore( DLLPtr this, ItemPtr _data_back )
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

size_t DLL_Len( DLLPtr this )
{
	assert( this );
	return this->len;
}

bool DLL_IsEmpty( DLLPtr this )
{
	assert( this );
	return this->first == NULL;
}

void DLL_MakeEmpty( DLLPtr this )
{
	assert( this );
	while( NULL != this->first){
		NodePtr tmp = this->first->next;
		free( this->first );
		this->first = tmp;
	}
	reset( this );
}

bool DLL_Peek( DLLPtr this, ItemPtr _data_back )
{
   assert(this);
   bool done;
   if(!DLL_IsEmpty(this)){
       *_data_back=this->cursor->data;
       done=true;
   }
   return done;
}

void DLL_CursorFirst( DLLPtr this )
{
	assert( this );
	this->cursor = this->first;
}

void DLL_CursorLast( DLLPtr this )
{
	assert( this );
	this->cursor = this->last;
}

void DLL_CursorNext( DLLPtr this )
{
	assert( this );
	if( this->cursor != NULL ){
		this->cursor = this->cursor->next;
	}
}

void DLL_CursorPrev( DLLPtr this )
{
	assert( this );
	if( this->cursor != NULL ){
		this->cursor = this->cursor->prev;
	}
}

bool DLL_FindIf( DLLPtr this, Item _key, bool (*cmp)(Item, Item) )
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


bool DLL_Search( DLLPtr this, char* _key )
{
    assert( this );
	bool found = false;

	for( NodePtr it = this->first; it != NULL; it = it->next ){
	    if( strcmp(_key,it->data._nombre)==0 ){
	        this->cursor = it;
    		found = true;
    		break;
		}
	}
	return found;

}

void DLL_Traverse(DLLPtr this, void (*pfun)(Item) )
{
	assert( this );

	for( NodePtr it = this->last; it != NULL; it = it->prev){
		pfun( it->data );
	}
}

static void quicksort( ItemPtr arreglo, int lim_izq, int lim_der ){
    int izq = lim_izq, der = lim_der;
    int pivote = arreglo[(izq+der)/2].hora_llegada;
    Item temporal;

    do{
        while(arreglo[izq].hora_llegada<pivote && izq<lim_der){
            izq++;
        }
        while(pivote<arreglo[der].hora_llegada && der>lim_izq){
            der--;
        }
        if(izq <= der){
            temporal = arreglo[izq];
            arreglo[izq] = arreglo[der];
            arreglo[der]=temporal;
            izq++;
            der--;
        }
    }while(izq <= der);

    if( lim_izq < der ){
        quicksort(arreglo, lim_izq, der);
    }
    if( lim_der > izq ){
        quicksort(arreglo, izq, lim_der);
    }

}

void DLL_Sort(DLLPtr other){
    int tamanio = DLL_Len(other);
    ItemPtr arreglo_aux = (ItemPtr)malloc( tamanio * sizeof(Item));
    
    for( size_t i = 0 ; i < tamanio ; ++i ){
        Item temporal;
        DLL_RemoveFront( other, &temporal);
        arreglo_aux[i] = temporal;
    }

    quicksort(arreglo_aux, 0, tamanio-1 );

    for( size_t j = 0 ; j < tamanio ; ++j ){
        Item tmp = arreglo_aux[j];
        DLL_InsertFront( other, tmp);
    }

	free(arreglo_aux);
}

