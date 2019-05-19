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

/*llenado de pilas de horarios*/

void salidas_Init( StackPtr this ){
    //Abajo de 12 pm a 12 am
    Stack_Push( this, 84600 );
    Stack_Push( this, 82800 );Stack_Push( this, 81000 );
    Stack_Push( this, 79200 );Stack_Push( this, 77400 );
    Stack_Push( this, 75600 );Stack_Push( this, 73800 );
    Stack_Push( this, 72000 );Stack_Push( this, 70200 );
    Stack_Push( this, 68400 );Stack_Push( this, 66600 );
    Stack_Push( this, 64800 );Stack_Push( this, 63000 );
    Stack_Push( this, 61200 );Stack_Push( this, 59400 );
    Stack_Push( this, 57600 );Stack_Push( this, 55800 );
    Stack_Push( this, 54000 );Stack_Push( this, 52200 );
    Stack_Push( this, 50400 );Stack_Push( this, 48600 );
    Stack_Push( this, 46800 );Stack_Push( this, 45000 );
    //Abajo de 1 am a 12 pm
    Stack_Push( this, 43200 );
    Stack_Push( this, 41400 );Stack_Push( this, 39600 );
    Stack_Push( this, 37800 );Stack_Push( this, 36000 );
    Stack_Push( this, 34200 );Stack_Push( this, 32400 );
    Stack_Push( this, 30600 );Stack_Push( this, 28800 );
    Stack_Push( this, 27000 );Stack_Push( this, 25200 );
    Stack_Push( this, 23400 );Stack_Push( this, 21600 );
    Stack_Push( this, 19800 );Stack_Push( this, 18000 );
    Stack_Push( this, 16200 );Stack_Push( this, 14400 );
    Stack_Push( this, 12600 );Stack_Push( this, 10800 );
    Stack_Push( this, 9000 );Stack_Push( this, 7200 );
    Stack_Push( this, 5400 );Stack_Push( this, 3600 );
}

void llegadas_init( StackPtr this ){
    //Abajo de 12 pm a 12 am
    Stack_Push( this, 84600+7200 );
    Stack_Push( this, 82800+7200 );Stack_Push( this, 81000+7200 );
    Stack_Push( this, 79200+7200 );Stack_Push( this, 77400+7200 );
    Stack_Push( this, 75600+7200 );Stack_Push( this, 73800+7200 );
    Stack_Push( this, 72000+7200 );Stack_Push( this, 70200+7200 );
    Stack_Push( this, 68400+7200 );Stack_Push( this, 66600+7200 );
    Stack_Push( this, 64800+7200 );Stack_Push( this, 63000+7200 );
    Stack_Push( this, 61200+7200 );Stack_Push( this, 59400+7200 );
    Stack_Push( this, 57600+7200 );Stack_Push( this, 55800+7200 );
    Stack_Push( this, 54000+7200 );Stack_Push( this, 52200+7200 );
    Stack_Push( this, 50400+7200 );Stack_Push( this, 48600+7200 );
    Stack_Push( this, 46800+7200 );Stack_Push( this, 45000+7200 );
    //Abajo de 1 am a 12 pm
    Stack_Push( this, 43200+7200 );
    Stack_Push( this, 41400+7200 );Stack_Push( this, 39600+7200 );
    Stack_Push( this, 37800+7200 );Stack_Push( this, 36000+7200 );
    Stack_Push( this, 34200+7200 );Stack_Push( this, 32400+7200 );
    Stack_Push( this, 30600+7200 );Stack_Push( this, 28800+7200 );
    Stack_Push( this, 27000+7200 );Stack_Push( this, 25200+7200 );
    Stack_Push( this, 23400+7200 );Stack_Push( this, 21600+7200 );
    Stack_Push( this, 19800+7200 );Stack_Push( this, 18000+7200 );
    Stack_Push( this, 16200+7200 );Stack_Push( this, 14400+7200 );
    Stack_Push( this, 12600+7200 );Stack_Push( this, 10800+7200 );
    Stack_Push( this, 9000+7200 );Stack_Push( this, 7200+7200 );
    Stack_Push( this, 5400+7200 );Stack_Push( this, 3600+7200 );
}