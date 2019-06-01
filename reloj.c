/******         main.c         ******/

#include "SLL.h"

#include <string.h>
#include <time.h>
#include <pthread.h>

#define CST (-7) //UTC CDMX

static void segundos_a_horas( int _segundos, int* h, int* m, int* s){
    if( 86400 > _segundos){
        *h = _segundos / 3600;
        *m = (_segundos- *h *3600 ) / 60;
        *s = _segundos - ( *h *3600 + *m *60 );
    }
    else{ *h = 0; *m = 0; *s= 0; }
}

struct timespec pausa = { 5, 0 };

void menu(){

}

int main(void){
    SLLPtr Horarios = SLL_New();

    printf("Ingresar horario: ");
    int _segundos;
    scanf("%d", &_segundos);
    SLL_InsertBack( Horarios, _segundos);
    SLL_CursorFirst(Horarios);
    int horario1;
    SLL_Peek( Horarios, &horario1 );

    int h = 1, m = 2, s = 3;
    printf("horas: %d", h);
    segundos_a_horas( horario1, &h, &m, &s);
    printf("\nHorario (1) : %02d:%02d:%02d\n", h, m, s);

    setbuf(stdin,NULL);
    printf("\n\tEnter para continuar...\n");
    getchar();

    SLL_Delete( Horarios );
    bool bandera = true;
    while( bandera ){
        time_t tiempo;
        struct tm *info;
        time(&tiempo);
        info = gmtime(&tiempo );/* Get GMT time */
        if( m == info->tm_min){
            bandera = false;
        }
        system("cls");
    }
    return 0;
}

//printf("CDMX: %02d:%02d:%02d\n", (info->tm_hour-CST)%24, info->tm_min, info->tm_sec);

/**
setbuf(stdin,NULL);
printf("\n\tEnter para continuar...\n");
getchar();
*/

/** (_horas*3600)+(_minutos*60)+(_segundos) */

