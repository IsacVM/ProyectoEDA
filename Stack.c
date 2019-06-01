/******         Stack.c         ******/

#include "Stack.h"

StackPtr Stack_New( size_t _capacity ){
    StackPtr s = (StackPtr) malloc( sizeof ( Stack ) );
    if( NULL != s ){
        s->stack = SLL_New( );
        _capacity = _capacity; /**< No se usa */
        if( NULL == s->stack ){
            free( s );
            s = NULL;
        }
    }
    return s;
}

void Stack_Delete( StackPtr this ){
    assert( this );

    SLL_Delete( this->stack );
    free( this );
}

bool Stack_Push( StackPtr this, ItemI _value ){
    assert( this );

    return SLL_InsertFront( this->stack, _value );
}

ItemI Stack_Pop( StackPtr this ){
    assert( this );

    ItemI value;
    SLL_RemoveFront( this->stack, &value );
    return value;
}

ItemI Stack_Peek( StackPtr this ){
    assert( !SLL_IsEmpty( this->stack ) );

    ItemI value;
    SLL_CursorFirst( this->stack );
    SLL_Peek( this->stack, &value );
    return value;
}

bool Stack_IsEmpty( StackPtr this ){
    assert( this );

    return SLL_IsEmpty( this->stack );
}

size_t Stack_Len( StackPtr this ){
    assert( this );

    return SLL_Len( this->stack );
}

void Stack_MakeEmpty( StackPtr this ){
    assert( this );

    SLL_MakeEmpty( this->stack );
}

/***  llenado de pilas de horarios   ***/

void horarios_Init( StackPtr this, StackPtr other ){
    //Abajo de 12 pm a 12 am
srand( time( 0 ) );

for(size_t i=0; i < 30;i++){
   int time = rand() % 86400;

    Stack_Push(this, time);
    Stack_Push(other, time+7200);
   }
}
