#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include "DLL.h"
//Funcion privada
void Segundos_a_horas(Item this, int* _hora1, int* _minutos1,int* _hora2, int* _minutos2){

 *_hora1=this.hora_salida/3600;
 *_minutos1=(this.hora_salida%3600)/60;
 *_hora2=this.hora_llegada/3600;
 *_minutos2=(this.hora_llegada%3600)/60;

}

int Horas_a_segundos (int horas,int minutos)
{
	horas=(horas*3600);
	minutos=(minutos*60);
	int segundos= horas+minutos ;
	
	return segundos; 
}

void imprime( Item item )
{
  printf("Nombre: %s\n", item._nombre);
  printf("Pasajeros: %d\n",item.pasajeros);
  printf("Capacidad: %d\n", item.capacidad);
  if(item.estado==1)printf("Estado: Ocupado\n");
  if(item.estado==2)printf("Estado: Disponible\n");
  if(item.estado==3)printf("Estado: Danado\n");
  int h1,m1,h2,m2;
  Segundos_a_horas(item,&h1,&m1,&h2,&m2);
  printf("Hora salida: %d:%d\n",h1,m1);
  printf("Hora llegada: %d:%d\n",h2,m2);
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

                "\t\t\t0) Salir\n"
         	 );

        int opcion;
        printf("\n");
        printf("\tSelecciona una opcion: ");
        scanf( "%d", &opcion );

        if( 0 <= opcion && opcion <= 10) { 
            return opcion; 
        }else{ printf( "Opcion no reconocida.\n" ); }
    }
}

int main(void){
    
    //listas de aviones
    DLL* danados=DLL_New();
    DLL* disponible=DLL_New();
    DLL* entrada=DLL_New();
    DLL* sol_entrada=DLL_New();
    DLL* salida=DLL_New();
    DLL* sol_salida=DLL_New();

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
    Item avi7=(Avion){"Aero1",150,300,1,37200,41400};
    Item avi8=(Avion){"Aero2",250,320,1,38400,44400};
    DLL_InsertFront( entrada, avi7);
    DLL_InsertFront( entrada, avi8);

    //aviones para despegue
    Item avi9=(Avion){"Aero3",100,300,1,48600,63600};
    Item avi10=(Avion){"Aero4",110,200,1,49800,66600};
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
                    DLL_Delete(sol_entrada);
                    DLL_Delete(salida);
                    DLL_Delete(sol_salida);
                
                    return 0;
                }
            case 1:
                {
                    printf("\t\tProximos arrivos: \n");
                    DLL_Traverse(entrada, imprime);
                    break;
                }  
            case 2:
                {
                    printf("\t\tSolicitar aterrizaje: \n");

                    DLL_CursorLast(entrada);
                    Item enter;
                    DLL_Peek(entrada,&enter);
                    imprime(enter);

                    int otc;
                    printf("Solicitar aterrizaje(Si=1): ");
                    scanf("%d",&otc);
                    if(otc==1){
                        Item solicitado;
                        DLL_RemoveBack(entrada,&solicitado);
                        DLL_InsertFront(sol_entrada,solicitado);
                    }
                    break;
                }
            case 3:
                {
                    printf("\t\tAutorizar aterrizaje: \n");
                    DLL_Traverse(sol_entrada,imprime);
                
                    int otc2;
                    printf("Aceptar solicitud de aterrizaje(Si=1): ");
                    scanf("%d",&otc2);
                    if(otc2==1){
                            Item autorizado;
                            DLL_RemoveBack(sol_entrada,&autorizado);
                            //limpiar pasajeros, horarios, estado
                            Avion_Reset(&autorizado);
                            DLL_InsertFront(disponible,autorizado);
                    }
                    
                    break;
                }
            case 4:
                {
                    
                    printf("\t\tProximos despegues: \n");
                    DLL_Traverse( salida, imprime);
                    break;
                   
                }   
            case 5:
                { 
                   
                    printf("\t\tSolicitar despegue: \n");
                    DLL_CursorLast(salida);
                    Item salir;
                    DLL_Peek(salida,&salir);
                    imprime(salir);

                    int o;
                    printf("Solicitar despegue(Si=1): ");
                    scanf("%d",&o);
                    if(o==1){
                        DLL_InsertFront(sol_salida,salir);
                    }
                        
                    break;
                }   
            case 6:
                {
                    printf("\t\tAutorizar despegue: \n");
                    DLL_Traverse(sol_salida,imprime);
                
                    int t;
                    printf("Aceptar solicitud de despegue(Si=1): ");
                    scanf("%d",&t);
                    if(t==1){
                            Item sal1,sal2;
                            DLL_CursorLast(salida);
                            DLL_RemoveBack(salida,&sal1);
                            DLL_RemoveBack(sol_salida,&sal2);
                           
                            Avion_Delete(&sal1);
                            Avion_Delete(&sal2);
                        }
                    break;
                   
                }       
            case 7:
                { 
                    printf("\t\tAviones disponibles: \n");
                    DLL_Traverse( disponible, imprime);    
                    break;
                   
                }

            case 8:
                {
                    printf("\t\tCargar avion \n");
                      
                    Item aviNew; 
                    
                    printf ("\n Nombre: ");
                    char name[20];  
					          scanf ("%s", &aviNew._nombre);
				
                    printf ("\nPasajeros: ");
					          int pasaj; 
					          scanf ("%d",&pasaj ); 
					          aviNew.pasajeros=pasaj;  
					
                    printf ("\nCapacidad: "); 
                    int cap; 
					          scanf ("%d",&cap); 
					          aviNew.capacidad=cap; 
					
                    printf ("\nEstado (1=ocupado,2=disponible,3=dañado): ");
                    int mode; 
					          scanf ("%d",&mode );
					          aviNew.estado=mode;  
					
					          printf ("\nHorario de salida \n Horas:   ");
					          int hrs1; 
					          scanf ("%d",&hrs1 );   
                    printf ("Minutos: ");
                    int min1; 
                    scanf ("%d",&min1 );
                    int seg1= Horas_a_segundos (hrs1,min1);
                    aviNew.hora_salida=seg1; 

					
                    printf ("\nHorario de llegada\nHoras: ");
                    int hrs2; 
                    scanf ("%d",&hrs2 );  
                    printf ("Minutos: ");
                    int min2; 
                    scanf ("%d",&min2 ); 
                    int seg2= Horas_a_segundos (hrs2,min2); 
                    aviNew.hora_llegada=seg2;


                    DLL_InsertFront( disponible, aviNew);
                     
                    break;
                }

            case 9:
                {
                    printf("\t\tAviones danados: \n");
                    DLL_Traverse( danados, imprime);
                    
                    break;
                } 
            case 10:
                {
                    printf("\t\tReparar aviones: \n");
                    break;
                }    

            
            default:
                printf( "Opcion no reconocida\n" );
                break;
        }
    
    }


    return 0;
}
