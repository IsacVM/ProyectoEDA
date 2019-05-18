/******         SLL.c         ******/

#include "SLL.h"

/**
 * @fn Funcion crea nodos dinamicos.
 */
static NodePtr newNode( Item _data ){
    NodePtr node = (NodePtr) malloc( sizeof(Node) );

    if( node ){
        node->data = _data;
        node->next = NULL;
    }
    return node;
}

/**
 * @fn Funcion resetea SLL a vacia.
 */
static void reset( SLLPtr this ){
	this->first = this->last = this->cursor = NULL;
	this->len = 0;
}


SLLPtr SLL_New( ){
    SLLPtr list = (SLLPtr) malloc( sizeof(SLL) );

    if( list ){
        reset ( list );
    }
    return list;
}

void SLL_Delete( SLLPtr this ){
    if( this ){
        SLL_MakeEmpty( this );
        free( this );
    }
}

bool SLL_InsertFront( SLLPtr this, Item _data ){
    assert( this );
    bool done = false;

    NodePtr node = newNode( _data );
    if( node ){
        done = true;

        // lista vacia, crea primer nodo
        if( SLL_IsEmpty( this ) ){
            this->first = this->last = node;
            this->len = 1;
        }

        // lista con nodos, añade nodo en Back
        else{
            node->next = this->first;
            this->first = node;
            ++this->len;
        }
    }
    return done;
}

bool SLL_InsertBack( SLLPtr this, Item _data ){
    assert( this );
    bool done = false;

    NodePtr node = newNode( _data );
    if( node ){
        done = true;

        // lista vacia, crea primer nodo
        if( SLL_IsEmpty( this ) ){
            this->first = this->last = node;
            this->len = 1;
        }

        // lista con nodos, añade nodo en Back
        else{
            this->last->next = node;
            this->last = node;
            ++this->len;
        }
    }
    return done;
}

bool SLL_InsertAfter( SLLPtr this, Item _data ){
    assert( this->cursor );
    bool done = false;

    if( SLL_IsEmpty( this ) ){
        done = SLL_InsertBack( this, _data);
    }
    else{
        NodePtr node = newNode( _data );

        if( node ){
            done = true;

            node->next = this->cursor->next;
            this->cursor->next = node;
            this->cursor = node;
            ++this->len;
        }
    }
    return done;
}

bool SLL_RemoveFront( SLLPtr this, ItemPtr _data_back ){
    assert( this );

    if( SLL_IsEmpty( this ) ){ return false; }

    *_data_back = this->first->data;

    NodePtr after = this->first->next;
    free( this->first );
    this->first = after;

    --this->len;
    return true;
}

bool SLL_Peek( SLLPtr this, ItemPtr _data_back ){
    assert( this );

    if( SLL_IsEmpty( this ) ){  return false;  }

    *_data_back = this->cursor->data;
    return true;
}

size_t SLL_Len( SLLPtr this ){
    assert( this );
    return this->len;
}

bool SLL_IsEmpty( SLLPtr this ){
    assert( this );
    return this->first == NULL;
}

void SLL_MakeEmpty( SLLPtr this ){
    assert( this );

    while( !SLL_IsEmpty( this ) ){
        NodePtr after = this->first->next;
        free ( this->first );
        this->first = after;
    }

    // Asegurarse de que vacio la lista
    assert( this->first == NULL );
    reset( this );
}

void SLL_CursorFirst( SLLPtr this ){
    assert( this );
    this->cursor = this->first;
}

void SLL_CursorLast( SLL* this ){
    assert( this );
    this->cursor = this->last;
}

void SLL_CursorNext( SLL* this ){
    assert( this->cursor );

    if( this->cursor == this->last ){
        this->cursor = NULL;
    }
    else{
        this->cursor = this->cursor->next;
    }
}

bool SLL_FindIf( SLLPtr this, Item _data ){
    assert( this );

    bool found = false;
    NodePtr it = this->first;

    if( !SLL_IsEmpty( this) ){
        while( it->next != NULL ){
            if( _data == it->data){
                found = true;
                break;
            }
            it = it->next;
        }
    }
    return found;
}

bool SLL_Search( SLLPtr this, Item _data ){
    assert( this );

    bool found = false;
    NodePtr it = this->first;

    if( !SLL_IsEmpty( this) ){
        while( it->next != NULL ){
            if( _data == it->data){
                this->cursor = it;
                found = true;
                break;
            }
            it = it->next;
        }
    }
    return found;
}
