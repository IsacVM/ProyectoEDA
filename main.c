#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include "DLL.h"

void imprime( Item item )
{
  printf( "Nombre: %s\n", item._nombre);
  printf( "Pasajeros: %s\n",item.pasajeros);
  printf( "Capacidad: %s\n", item.capacidad);
  printf( "Estado: %s\n", item.estado);
  printf( "Hora salida: %s\n", item.hora_salida);
  printf( "Hora llegada: %s\n", item.hora_llegada);
  printf("\n\n");
}

//Funcion menu
int menu()
{
    while( 1 )
    {
        printf( "\n"

                "\t\t\t1) Aviones para aterrizaje\n"
                "\t\t\t2) Aviones para despegue\n"
                "\t\t\t3) Ver lista de aviones disponibles\n"
                "\t\t\t4) Ver lista de aviones danados\n"
                "\t\t\t5) Solicitar aterrizaje\n"
                "\t\t\t6) Autorizar aterrizaje\n"
                "\t\t\t7) Solicitar despegue\n"
                "\t\t\t8) Autorizar despeque\n"
                "\t\t\t0) Salir\n"
         	 );

        int opcion;
        printf("Selecciona una opcion: ");
        scanf( "%d", &opcion );

        if( 0 <= opcion && opcion <= 8) { 
            return opcion; 
        }else{ printf( "Opcion no reconocida.\n" ); }
    }
}

int main(void){
    
    DLL* danados=DLL_New();
    DLL* disponible=DLL_New();
    DLL* entrada=DLL_New();
    DLL* salida=DLL_New();
    DLL* sol_entrada=DLL_New();

    Item avi1=(Avion){"BoingMX2","0","250","Danado","",""};
    Item avi2=(Avion){"Airbus280","0","350","Danado","",""};
    Item avi3=(Avion){"Latam100","0","300","Danado","",""};
    DLL_InsertFront( danados, avi1);
    DLL_InsertFront( danados, avi2);
    DLL_InsertFront( danados, avi3);

    Item avi4=(Avion){"BoingMZY","0","250","Disponible","",""};
    Item avi5=(Avion){"Airbus760","0","400","Disponible","",""};
    Item avi6=(Avion){"LatamSUR7","0","300","Disponible","",""};
    DLL_InsertFront( disponible, avi4);
    DLL_InsertFront( disponible, avi5);
    DLL_InsertFront( disponible, avi6);

    Item avi7=(Avion){"Aero1","150","300","Ocupado","10:20","11:30"};
    Item avi8=(Avion){"Aero2","250","300","Ocupado","10:40","12:20"};
    DLL_InsertFront( entrada, avi7);
    DLL_InsertFront( entrada, avi8);

    Item avi9=(Avion){"Aero3","100","300","Ocupado","13:30","17:40"};
    Item avi10=(Avion){"Aero4","100","200","Ocupado","13:50","18:30"};
    DLL_InsertFront(salida, avi9);
    DLL_InsertFront(salida, avi10);

    printf("\t\tSISTEMA DE ADMINISTRACION AEROPORTUARIA TORRE DE CONTROL\n\n");


    while (1)
   {  
        switch( menu() ){

            case 0:
                {
                    //liberando memoria
                    DLL_Delete(danados);
                    DLL_Delete(disponible);
                    DLL_Delete(entrada);
                    DLL_Delete(salida);
                    DLL_Delete(sol_entrada);

                    return 0;
                }
            case 1:
                {
                    printf("\t\tProximos arrivos: \n");
                    DLL_Traverse( entrada, imprime);
                    break;
                }  
            case 2:
                {
                    printf("\t\tProximos despegues: \n");
                    DLL_Traverse( salida, imprime);
                    break;
                }
            case 3:
                {
                    printf("\t\tAviones disponibles: \n");
                    DLL_Traverse( disponible, imprime);    
                    break;
                }
            case 4:
                {
                    printf("\t\tAviones danados: \n");
                    DLL_Traverse( danados, imprime);
                    break;
                }   
            case 5:
                { 
                    printf("\t\tSolicitar aterrizaje: \n");
                    DLL_CursorLast(entrada);
                    Item enter;
                    DLL_Peek(entrada,&enter);
                    imprime(enter);

                    int otc;
                    printf("Solicitar aterrizaje: (Si=1)");
                    scanf("%d",&otc);
                    if(otc==1){
                        Item solicitado;
                        DLL_RemoveBack(entrada,&solicitado);
                        DLL_InsertFront(sol_entrada,solicitado);
                    }
                        
                    break;
                }   
            case 6:
                {
                    printf("\t\tAutorizar aterrizaje: \n");
                    DLL_Traverse(sol_entrada,imprime);
                    int otc2;
                    printf("Aceptar solicitud de aterrizaje: (Si=1)");
                    scanf("%d",&otc2);
                    if(otc2==1){
                        Item autorizado;
                        DLL_RemoveBack(sol_entrada,&autorizado);
                        //limpiar pasajeros, horarios, estado
                        DLL_InsertFront(disponible,autorizado);
                    }
                    break;
                }       
            case 7:
                { 
                    printf("\t\tSolicitar despegue: \n");
                   
                    break;
                }
           
            case 8:
                {
                    printf("\t\tAutorizar despegue: \n");
                    break;
                }
            
            default:
                printf( "Opcion no reconocida\n" );
                break;
        }
    
    }


    return 0;
}