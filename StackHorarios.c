/**
 * @file StackHorarios.c
 * @Author Team
 * @date 1 junio 2019
 * @brief Proyecto - EDA-I
 * @note Grupo: 0007, Semestre 2019-2
 */
#include "StackHorarios.h"

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

int Get_hora_actual(){
   
    time_t tiempo;
    struct tm *info;
    time(&tiempo);
    info = gmtime(&tiempo); /**< Obtiene GMTime */
   
    int hora_actual = ((info->tm_hour-CST)%24)*3600+(info->tm_min)*60+(info->tm_sec);
    return hora_actual;
}

void horarios_Init( StackPtr this, StackPtr other ){
    int hora1 = Get_hora_actual();
    int hora2 = hora1 + 1200;

    srand( time(NULL) );
    /**< Simula horarios en los proximos 30 minutos de ejecucion */
    for(size_t i=0; i < 30;i++){
        int randomplus = rand() % 121 + 300;
        int time = rand() % (hora2-hora1+1) + hora1;
        Stack_Push(this, time + randomplus + 120);
        Stack_Push(other, time + randomplus + 7200);
        sleep(0.2);
    }
}
