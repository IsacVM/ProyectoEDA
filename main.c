#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <time.h>

#include "DLL.h"
#include "Stack.h"
#include "Pista.h"

                                                        
//Funcion privada
void Segundos_a_horas2(Item this, int* _hora1, int* _minutos1,int* _hora2, int* _minutos2){

 *_hora1=this.hora_salida/3600;
 *_minutos1=(this.hora_salida%3600)/60;
 *_hora2=this.hora_llegada/3600;
 *_minutos2=(this.hora_llegada%3600)/60;

}

void print( Item item )
{
  printf("Nombre: %s\n", item._nombre);
  printf("Pasajeros: %d\n",item.pasajeros);
  printf("Capacidad: %d\n", item.capacidad);
  if(item.estado==1)printf("Estado: Ocupado\n");
  if(item.estado==2)printf("Estado: Disponible\n");
  if(item.estado==3)printf("Estado: Danado\n");
  int h1,m1,h2,m2;
  Segundos_a_horas2(item,&h1,&m1,&h2,&m2);
  printf("Hora salida: %02d:%02d\n",h1,m1);
  printf("Hora llegada: %02d:%02d\n",h2,m2);
  printf("\n\n");
}

//Funcion menu
int menu()
{
    while( 1 )
    {
        printf( "\n"
                "\t\t\t1) Aviones para aterrizaje\n"
                "\t\t\t2) Solicitar aterrizaje\n"
                "\t\t\t3) Autorizar aterrizaje\n"
                "\t\t\t4) Aviones para despegue\n"
                "\t\t\t5) Solicitar despegue\n"
                "\t\t\t6) Autorizar despeque\n"
                "\t\t\t7) Ver lista de aviones disponibles\n"
                "\t\t\t8) Cargar un avion disponible\n"
                "\t\t\t9) Ver lista de aviones danados\n"
                "\t\t\t10) Reparar aviones\n"
                "\t\t\t11) Fenomeno meterologico\n"
                "\t\t\t0) Salir\n"
         	 );

        int opcion;
        printf("\n");
        printf("\tSelecciona una opcion: ");
        scanf( "%d", &opcion );

        if( 0 <= opcion && opcion <= 11) { 
            return opcion; 
        }else{ printf( "Opcion no reconocida.\n" ); }
    }
}

bool salir=false;


int main(void){
    
    //Archivo para serializacion
    FILE *reporte; 	
	reporte = fopen("reporte.txt", "w+");
    // Si no podemos crear el archivo, terminamos el programa.
    if(reporte== NULL){ 
        printf("No se pudo crear el archivo... \n"); 
        return -1; 
    }else{
        fprintf(reporte,"\n");
        fprintf(reporte,"\t\t\t\t\t\tTorre De Control NAICM\n\t\t\t\t\t\tATERRIZAJES\n");
		fprintf(reporte,"Nombre:\t\tPasajeros:\t\tCapacidad:\t\tHora Llegada:\t\tHora Salida:\n");
    }

    //listas de aviones
    DLL* danados=DLL_New();
    DLL* disponible=DLL_New();

    DLL* entrada=DLL_New();
    DLL* sol_entrada=DLL_New();
    //pista para aterrizajes
    PistaPtr pista1=Pista_New(10);

    //pista para despegues
    PistaPtr pista2=Pista_New(10);
    DLL* sol_salida=DLL_New();

    //pilas de horarios
    StackPtr horarios_salida = Stack_New( 0 );
    StackPtr horarios_llegada = Stack_New( 0 );

    //llenando pilas de horarios
    horarios_Init( horarios_salida,horarios_llegada);
    
    //aviones dañados
    Item avi1=(Avion){"BoingMX2",0,250,3,0,0};
    Item avi2=(Avion){"Airbus280",0,350,3,0,0};
    DLL_InsertFront( danados, avi1);
    DLL_InsertFront( danados, avi2);

    //aviones disponibles
    Item avi4=(Avion){"BoingMZY",0,350,2,0,0};
    Item avi5=(Avion){"Airbus760",0,400,2,0,0};
    DLL_InsertFront( disponible, avi4);
    DLL_InsertFront( disponible, avi5);
  
    //aviones para aterrizaje
    Item avi7=(Avion){"Aero1",150,300,1,Stack_Pop(horarios_salida),Stack_Pop(horarios_llegada)};
    Item avi8=(Avion){"Aero2",250,320,1,Stack_Pop(horarios_salida),Stack_Pop(horarios_llegada)};
    Item avi9=(Avion){"Aero3",250,320,1,Stack_Pop(horarios_salida),Stack_Pop(horarios_llegada)};
    Item avi10=(Avion){"Aero4",250,320,1,Stack_Pop(horarios_salida),Stack_Pop(horarios_llegada)};
    Item avi11=(Avion){"Aero5",250,320,1,Stack_Pop(horarios_salida),Stack_Pop(horarios_llegada)};
    DLL_InsertFront( entrada, avi7);
    DLL_InsertFront( entrada, avi8);
    DLL_InsertFront( entrada, avi9);
    DLL_InsertFront( entrada, avi10);
    DLL_InsertFront( entrada, avi11);

    DLL_Sort_llegada( entrada );

    //aviones para despegue
    Item avi12=(Avion){"Aero6",100,300,1,Stack_Pop(horarios_salida),Stack_Pop(horarios_llegada)};
    Item avi13=(Avion){"Aero7",110,200,1,Stack_Pop(horarios_salida),Stack_Pop(horarios_llegada)};
    
    //insertar en pista de despegue
    Pista_Landing(pista2,avi12);
    Pista_Landing(pista2,avi13);

   
    printf("\t\tSISTEMA DE ADMINISTRACION AEROPORTUARIA TORRE DE CONTROL\n\n");

   do
   {  
        switch( menu() ){
 
            case 0:
                {
                 
                    //liberando memoria
                    DLL_Delete(danados);
                    DLL_Delete(disponible);
                    DLL_Delete(entrada);
                    DLL_Delete(sol_entrada);
                    Pista_Delete(pista1);
                    DLL_Delete(sol_salida);
                    Pista_Delete(pista2);
                    Stack_Delete( horarios_salida );
                    Stack_Delete( horarios_llegada );
    
                    fflush ( reporte );
                    fclose ( reporte );

                    
                    salir=true;
                   
                    return 0;
                }
            case 1:
                {
                   
                        printf("\t\tProximos arrivos: \n");
                        DLL_Traverse(entrada, print);

           
                    break;
                }  
            case 2:
                {
                    printf("\t\tSolicitar aterrizaje: \n");

                    if(!DLL_IsEmpty(entrada)){

                        DLL_CursorLast(entrada);
                        Item enter;
                        DLL_Peek(entrada,&enter);
                        print(enter);

                        int otc;
                        printf("Solicitar aterrizaje(Si=1): ");
                        scanf("%d",&otc);
                        if(otc==1){
                            DLL_InsertFront(sol_entrada,enter);
                        }
                        //liberamos memoria
                        Avion_Delete(&enter);
                        
                    }else{
                        printf("Lista vacia");
                    }    

                    break;
                }
            case 3:
                {
                    printf("\t\tAutorizar aterrizaje: \n");

                    if(!DLL_IsEmpty(sol_entrada)){

                        DLL_Traverse(sol_entrada,print);
                        int otc2;
                        printf("Aceptar solicitud de aterrizaje(Si=1): ");
                        scanf("%d",&otc2);
                        if(otc2==1)
                        {
                               
                                Item eliminado;
                                Item autorizado;
                                //sacamos el avion de la lista de entrada
                                DLL_RemoveBack(entrada,&eliminado);
                                //sacamos el avion de solicitudes de entrada
                                DLL_RemoveBack(sol_entrada,&autorizado);
                                
                                //guardamos este avion en el registro de aterrizajes

                                Avion_archivo(reporte,eliminado);
                            

                                if(Pista_IsEmpty(pista1))
                                {

                                    printf("\n\tAterrizando en PISTA 1 ...");
                                    Pista_Landing(pista1,autorizado);

                                    printf( "\n"
                                            "\t\t\t1) Liberar avion y mandarlo a disponibles\n"
                                            "\t\t\t2) Mandar a pista 2 de despegue(es una escala)\n"
                                            "\t\t\t0) Salir\n"
                                        );
                                    int otc3;
                                    printf("\n");
                                    printf("\tSelecciona una opcion: ");
                                    scanf( "%d", &otc3);

                                    switch (otc3)
                                    {

                                        case 0:
                                            {
                                                break;
                                            }
                                        case 1:
                                            {
                                                //limpiamos los valores del avion
                                                Avion_Reset(&autorizado);
                                                //la sacamos de la pista 1 de aterrizaje
                                                Item retira;
                                                Pista_Takeoff(pista1,&retira);
                                                //se inserta el avion en disponibles
                                                DLL_InsertFront(disponible,autorizado);
                                                
                                                Avion_Delete(&retira);

                                                break;
                                            }
                                        case 2:
                                            {
                                                Item avion;  
                                                //sacamos al avion de la pista 1 de aterrizajes  
                                                Pista_Takeoff(pista1,&avion);
                                                //se le asigna un nuevo horario de salida y llegada
                                                Avion_ResetHorario(&avion,Stack_Pop(horarios_salida),Stack_Pop(horarios_llegada)); 
                                                //se pone en la lista de espera de despegue
                                                Pista_Landing(pista2,avion);

                                                //liberamos memoria
                                                Avion_Delete(&avion);

                                                break;
                                            }

                                        default:
                                            printf( "Opcion no reconocida\n" );
                                            break;
                                    }

                                }else{

                                    printf("\t\t\tCHOQUE DE AVIONES!!\n");
                                    Item chocado;
                                    Pista_Takeoff(pista1,&chocado);
                                    printf("\n\t\tMandando avion '%s' y '%s' a lista de aviones danados...\n",autorizado._nombre,chocado._nombre);
                                    Avion_Reset(&autorizado);
                                    Avion_Reset(&chocado);
                                    DLL_InsertFront(danados,autorizado);
                                    DLL_InsertFront(danados,chocado);

                                    Avion_Delete(&chocado);

                                }    

                                //liberamos memoria
                                Avion_Delete(&eliminado);
                                Avion_Delete(&autorizado);
                        }

                    }else{
                        printf("Lista vacia");
                    }    
                    
                    break;
                }
            case 4:
                {
                    Pista_sort(pista2);

                    printf("\t\tProximos despegues: \n");
                    Pista_Imprimir(pista2);

                    break; 
                }   
            case 5:
                { 
                    printf("\t\tSolicitar despegue: \n");
                    if(!Pista_IsEmpty(pista2)){
                    
                        Item salir;
                        Pista_Peek(pista2,&salir);
                        print(salir);

                        int o;
                        printf("Solicitar despegue(Si=1): ");
                        scanf("%d",&o);
                        if(o==1){
                            DLL_InsertFront(sol_salida,salir);
                        }
                        //liberamos memoria
                        Avion_Delete(&salir);
                    }else{
                        printf("Lista vacia");
                    }
                    
                    break;
                }   
            case 6:
                {
                    printf("\t\tAutorizar despegue: \n");

                    if(!DLL_IsEmpty(sol_salida)){

                        DLL_Traverse(sol_salida,print);
                        int t;
                        printf("Aceptar solicitud de despegue(Si=1): ");
                        scanf("%d",&t);
                        if(t==1)
                        {
                                Item sal1,sal2;
                                Pista_Takeoff(pista2,&sal1);
                                DLL_RemoveBack(sol_salida,&sal2);
                            
                                fprintf(reporte,"\n\t\t\tDESPEGUES\n");
		                        fprintf(reporte,"Nombre:\t\tPasajeros:\t\tCapacidad:\t\tHora Llegada:\t\tHora Salida:\n");

                                Avion_archivo(reporte,sal1);

                                Avion_Delete(&sal1);
                                Avion_Delete(&sal2);
                        }

                    }else{
                        printf("Lista vacia");
                    }
                    
                    break;
                   
                }       
            case 7:
                { 
                    printf("\t\tAviones disponibles: \n");
                    DLL_Traverse( disponible, print);   

                    break;
                }
            case 8:
                {
                    printf("\t\tCargar aviones: \n");

                    if(!DLL_IsEmpty(disponible))
                    {

                        DLL_Traverse(disponible,print);
                        char nombre[30];
                        printf("Escribe el nombre del avion que quieres cargar: ");
                        scanf("%s",nombre);

                        if( DLL_Search(disponible,nombre)==true)
                        {
                            Item temp;
                            DLL_Remove(disponible,&temp);
                            Avion_Llenar(&temp,Stack_Pop(horarios_llegada),Stack_Pop(horarios_salida));
                            //llevamos el avion a la pista de despegue
                            Pista_Landing(pista2,temp);

                            Avion_Delete(&temp);
                        }

                    }else{
                        printf("Lista vacia");
                    }
                    
                    break; 
                    
                }

            case 9:
                {
                    printf("\t\tAviones danados: \n");
                    DLL_Traverse( danados, print);
                    
                    break;
                } 
            case 10:
                {
                    printf("\t\tReparar aviones: \n");

                    if(!DLL_IsEmpty(danados))
                    {
      
                        DLL_Traverse(danados,print);
                        int oci;
                        printf("Reparar todos los aviones o reparar un avion en especifico (1=TODOS, 2=UNO): ");
                        scanf("%d",&oci);

                        if(oci==1)
                        {
                            printf("\n\tReparando todos...\n");
                            int i=0;
                            int tama=DLL_Len(danados);
                            while(i<tama){
                                Item reparado;
                                DLL_RemoveBack(danados,&reparado);
                                Avion_Reset(&reparado);
                                DLL_InsertFront(disponible,reparado);
                                i++;
                                Avion_Delete(&reparado);
                            }

                        }else if(oci==2){
                        
                            char name[30];
                            printf("Escribe el nombre del avion que quieres reparar: ");
                            scanf("%s",name);

                            if(DLL_Search(danados,name)==true)
                            {
                                printf("\n\tReparando...\n");
                                Item reparar;
                                DLL_Remove(danados,&reparar);
                                Avion_Reset(&reparar);
                                DLL_InsertFront(disponible,reparar);
                                Avion_Delete(&reparar); 
                            }
                            

                        }

                    }

                    break;
                }   
            case 11:
                {
                    printf("\t\tFenomeno meteorologico pendiente...\n");
                    break;
                }     

            default:
                
                    printf( "Opcion no reconocida\n" );
                    break;
                   
        }
    
    }while(!salir);

    return 0;
}