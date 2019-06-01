/**
 * @file main.c
 * @Author Team
 * @date 1 junio 2019
 * @brief Proyecto - EDA-I
 * @note Grupo: 0007, Semestre 2019-2
 */

#include "DLL.h"
#include "Pistas.h"
#include "StackHorarios.h"

#include <time.h>
#include <ctype.h>
#include <pthread.h>

#define R 24
#define C 76


/**
 * @brief Obtiene una hora 
 * @param Apuntador de tipo int
 * @param Apuntador de tipo int	
 */
void Obtiene_reloj(int* _hora,int* _minuto){
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);

        *_hora=tm.tm_hour;
        *_minuto=tm.tm_min;
}

/**
 * @brief Lee un archivo e interpreta los caracteres 
 * @param cadena de tipo char 	
 */                
void pantalla(char nom[])
{
    FILE *pant;
    int n,m,carac;
    char cadcarac[2];
    char mtr[R][C];
    pant=fopen("princi.txt","r");
    for(n=0;n<R;n++)
     {
        //Sleep(20);
        for(m=0;m<C;m++)
        {
            mtr[n][m]=fgetc(pant);
            if(nom)
            {
                if (isdigit(mtr[n][m])==0)
                {
                    carac=mtr[n][m];
                    printf("%c",(char)carac);
                }else{
                    cadcarac[0]=mtr[n][m];
                    cadcarac[1]='\0';
                    carac=atoi(cadcarac);
                    printf("%c",'o');
                }
            }else{
                if (isdigit(mtr[n][m])==0)
                {
                    carac=mtr[n][m];
                    printf("%c",(char)carac);
                }else{
                    cadcarac[0]=mtr[n][m];
                    cadcarac[1]='\0';
                    carac=atoi(cadcarac);
                    printf("%c",'o');
                } 
            }
                                     
        }
    }

    fclose(pant); 
}

/**
 * @brief Solicita arrivo automático 
 * @param Apuntador de tipo void
 */
void* notifArrivos(void* arg){
    int* hora_arrivo = (int*) arg;
    int hora_actual = 0;

    while(*hora_arrivo != hora_actual){
        hora_actual = Get_hora_actual();
    }
    printf("\n\t---------------------------\n");
    printf("\n\t**...AVION ATERRIZANDO...**\n");
    printf("\n\t---------------------------\n\n");
    printf("Opcion Menu @: ");
    sleep(1);
    return NULL;
}

/**
 * @brief Solicita despegue automático 
 * @param Apuntador de tipo void
 */
void* notifDespegues(void* arg){
    int* hora_despegue = (int*) arg;
    int hora_actual = 0;

    while(*hora_despegue != hora_actual){
        hora_actual = Get_hora_actual();
    }
    printf("\n\t--------------------------\n");
    printf("\n\t**...AVION DESPEGANDO...**\n");
    printf("\n\t--------------------------\n");
    printf("Opcion Menu @: ");
    sleep(1);
    return NULL;
}

/**< Funcion menu */
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
        }else{ 
            printf( "Opcion no reconocida.\n" ); 
        }
    }
}

/**< ----------------------------------------------------------------- */
int main(void){
    system("clear");
    
    pantalla("princi.txt");
    setbuf(stdin,NULL);
    getchar();  

    /**< variables para el reloj general */
    int hra,min;

    /**< Archivo Aterrizajes */
    FILE *reporteAt; 	
	reporteAt = fopen("reporteAt.txt", "w+"); 
	
    if(reporteAt== NULL){ 
        printf("No se pudo crear el archivo... \n"); 
        return -1; 
    }else{
        fprintf(reporteAt,"\n");
        fprintf(reporteAt,"\t\t\t\t\tTorre De Control NAICM\n\n\t\t\t\t\t\tATERRIZAJES\n");
		fprintf(reporteAt,"Nombre:\t\tPasajeros:\t\tCapacidad:\t\tHora Llegada:\t\tHora Salida:\n");
    }

	/**< Archivo Despegues */
	FILE *reporteDes; 	
	reporteDes = fopen("reporteDes.txt", "w+"); 
	
    if(reporteDes== NULL){ 
        printf("No se pudo crear el archivo... \n"); 
        return -1; 
    }else{
        fprintf(reporteDes,"\n");
        fprintf(reporteDes,"\t\t\t\t\t\t\tTorre De Control NAICM\n\n\t\t\t\t\t\tDESPEGUES\n");
		fprintf(reporteDes,"Nombre:\t\tPasajeros:\t\tCapacidad:\t\tHora Llegada:\t\tHora Salida:\n");
    }
    
    /**< lista para aviones danados */
    DLL* danados=DLL_New();
    /**< lista para aviones disponibles */
    DLL* disponible=DLL_New();
    /**< lista de aviones para aterrizaje(estan en el aire) */
    DLL* entrada=DLL_New();
    /**< lista para solicitudes de aterrizaje */
    DLL* sol_entrada=DLL_New();
    /**< pista para aterrizajes basada en una DLL */
    PistaPtr pista1=Pista_New(10);
    /**< lista para solicitudes de despegue */
    DLL* sol_salida=DLL_New();
    /**< pista para despegues basada en una DLL */
    PistaPtr pista2=Pista_New(10);
    /**< pila de horarios de salida */
    StackPtr horarios_salida = Stack_New( 0 );
    /**< pila de horarios de llegada */
    StackPtr horarios_llegada = Stack_New( 0 );
    /**< llenanado de pilas de horarios */
    horarios_Init( horarios_salida,horarios_llegada);

    /**< creacion de algunos aviones danados */
    Item avi1=(Avion){"BoingMX2",0,250,3,0,0};
    Item avi2=(Avion){"Airbus280",0,350,3,0,0};
    DLL_InsertFront( danados, avi1);
    DLL_InsertFront( danados, avi2);

    /**< creacion de algunos disponibles */
    Item avi4=(Avion){"BoingMZY",0,350,2,0,0};
    Item avi5=(Avion){"Airbus760",0,400,2,0,0};
    DLL_InsertFront( disponible, avi4);
    DLL_InsertFront( disponible, avi5);
  
    /**< creacion de algunos aviones para aterrizaje */
    int dif = 7200; /**< Dos horas de diferencia con respecto a los despegues */
    Item avi6=(Avion){"Aero1",150,300,1,Stack_Pop(horarios_salida)-dif,Stack_Pop(horarios_llegada)-dif};
    Item avi7=(Avion){"Aero2",220,320,1,Stack_Pop(horarios_salida)-dif,Stack_Pop(horarios_llegada)-dif};
    Item avi8=(Avion){"Aero3",260,350,1,Stack_Pop(horarios_salida)-dif,Stack_Pop(horarios_llegada)-dif};
    Item avi9=(Avion){"Aero4",250,380,1,Stack_Pop(horarios_salida)-dif,Stack_Pop(horarios_llegada)-dif};
    Item avi10=(Avion){"Aero5",350,420,1,Stack_Pop(horarios_salida)-dif,Stack_Pop(horarios_llegada)-dif};
    DLL_InsertFront( entrada, avi6);
    DLL_InsertFront( entrada, avi7);
    DLL_InsertFront( entrada, avi8);
    DLL_InsertFront( entrada, avi9);
    DLL_InsertFront( entrada, avi10);

    /**< ordenar arrivos y despegues de pista 2 */
    DLL_Sort(entrada);
    Pista_sort(pista2);

    /**< creacion de algunos aviones para despegue */
    Item avi11=(Avion){"Aero6",100,300,1,Stack_Pop(horarios_salida),Stack_Pop(horarios_llegada)};
    Item avi12=(Avion){"Aero7",110,200,1,Stack_Pop(horarios_salida),Stack_Pop(horarios_llegada)};
    
    /**< insertando aviones para despegue en pista2 de despegue */
    Pista_Landing(pista2,avi11);
    Pista_Landing(pista2,avi12);

    /**< Definiendo los dos hilos (prcesos) */
    pthread_t proceso1;
    pthread_t proceso2;

    while (1)
    {  
        system("clear");
        system("clear");

        /**< Notifica sobre el proximo arrivo (proceso 1) */
        if( !DLL_IsEmpty( entrada ) ){
            Item prox_arrivo;
            DLL_CursorLast( entrada );
            DLL_Peek( entrada, &prox_arrivo );
            int arrivo_temp = prox_arrivo.hora_llegada;
            pthread_create(&proceso1, NULL, notifArrivos, &arrivo_temp );
        }

        /**< Notifica sobre el proximo despegue (proceso 2) */
        if( !DLL_IsEmpty( pista2->track ) ){
            Item prox_despegue;
            DLL_CursorLast( pista2->track );
            DLL_Peek( pista2->track, &prox_despegue );
            int despegue_temp = prox_despegue.hora_salida;

            pthread_create(&proceso2, NULL, notifDespegues, &despegue_temp );
        }

        printf("\t\tSISTEMA DE ADMINISTRACION AEROPORTUARIA TORRE DE CONTROL\n\n");
        
        Obtiene_reloj(&hra,&min);

        printf("\nHora de inicio: %02d:%02d\n",hra,min );

        /**< CASO Particular de Fenomeno Meteorologico */
     	static int stop = 1;
     	if ( stop == 0 )
     	{
     	 	printf ("\nDeseas reanudar las actividades del aeropuerto?\nSI -> 1      N0-> 0 \n"); 
     	 	int option; 
     	 	scanf ("%d",&option );
     	 	if (option == 1)
     	 	{
     	 	    stop = 1; 
     	 	    printf ("\nActividades reanudadas\n"); 
     	    }else{
     	 		    printf ("\nCerrando sesion\nGenerando archivo de reporte\n");
     	 		    /**< liberando memoria dinamica */
                    DLL_Delete(danados);
                    DLL_Delete(disponible);
                    DLL_Delete(entrada);
                    DLL_Delete(sol_entrada);
                    Pista_Delete(pista1);
                    DLL_Delete(sol_salida);
                    Pista_Delete(pista2);
                    Stack_Delete( horarios_salida );
                    Stack_Delete( horarios_llegada );
                    /**< Cierra archivos */
                    fclose ( reporteAt );
                    fclose ( reporteDes ); 

                    return 0;    
     	 	}
     	}

        /**< OPCIONES DE MENU */
        switch( menu() ){
 
            case 0:
                {
                 
                    /**< liberando memoria dinamica */
                    DLL_Delete(danados);
                    DLL_Delete(disponible);
                    DLL_Delete(entrada);
                    DLL_Delete(sol_entrada);
                    Pista_Delete(pista1);
                    DLL_Delete(sol_salida);
                    Pista_Delete(pista2);
                    Stack_Delete( horarios_salida );
                    Stack_Delete( horarios_llegada );
                    /**< Cierra archivos */
                    fclose ( reporteAt );
                    fclose ( reporteDes );
                   
                    return 0;
                }
            case 1:
                {
                   
                    printf("\t\tAVIONES PARA ATERRIZAJE\n");
                    DLL_Traverse(entrada, print);
                    printf ("Presione Enter para regresar al menu principal\n"); 
                    setbuf(stdin, NULL);
                    getchar();  

                    break;
                }  
            case 2:
                {
                    printf("\t\tSOLICITAR ATERRIZAJE \n");

                    if(!DLL_IsEmpty(entrada)){

                        DLL_CursorLast(entrada);
                        Item enter;
                        DLL_Peek(entrada,&enter);
                        print(enter);

                        int otc;
                        printf("Solicitar aterrizaje(Si= 1): ");
                        scanf("%d",&otc);
                        if(otc==1){
                            DLL_InsertFront(sol_entrada,enter);
                            printf ("\nSolicitud realizada!\n"); 
                        }
                        
                        
                    }else{
                        printf("Lista vacia");
                    }  
                    printf ("Presione Enter para regresar al menu principal\n"); 
                    setbuf(stdin, NULL);
                    getchar(); 
					  
                    break; 
                }
            case 3:
                {
                    printf("\t\tAUTORIZAR ATERRIZAJE \n");

                    if(!DLL_IsEmpty(sol_entrada)){

                        DLL_Traverse(sol_entrada,print);
                        int otc2;
                        printf("Aceptar solicitud de aterrizaje(Si=1): ");
                        scanf("%d",&otc2);
                        if(otc2==1)
                        {
                                Item eliminado;
                                Item autorizado;
                                /**< sacamos el avion de la lista de entrada */
                                DLL_RemoveBack(entrada,&eliminado);
                                /**< sacamos el avion de solicitudes de entrada */
                                DLL_RemoveBack(sol_entrada,&autorizado);
                                /**< guardamos este avion en el registro de aterrizajes */
                                Avion_archivo(reporteAt,eliminado);

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
                                                /**< limpiamos los valores del avion */
                                                Avion_Reset(&autorizado);
                                                /**< la sacamos de la pista 1 de aterrizaje */
                                                Item retira;
                                                Pista_Takeoff(pista1,&retira);
                                                /**< se inserta el avion en disponibles */
                                                DLL_InsertFront(disponible,autorizado);
            
                                                printf ("\nRealizado con exito!\n");
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
                                                printf ("\nAvion listo en pista 2\n"); 

                                                break;
                                            }

                                        default:
                                            printf( "Opcion no reconocida\n" );
                                            break;
                                    }

                                }else{

                                    printf("\t\t\tCHOQUE DE AVIONES!!\n");
                                    Item chocado1,chocado2;
                                    Pista_Takeoff(pista1,&chocado1);
                                    Pista_Takeoff(pista1,&chocado2);
                                    printf("\n\t\tMandando avion '%s' y '%s' a lista de aviones danados...\n",chocado1._nombre,chocado2._nombre);
                                    Avion_Reset(&chocado1);
                                    Avion_Reset(&chocado2);
                                    DLL_InsertFront(danados,chocado1);
                                    DLL_InsertFront(danados,chocado2);
                                }    
                        }

                    }else{
                        printf("\nNo hay solicitudes de aterrizaje\n");
                    }    
                    
                    printf ("Presione Enter para regresar al menu principal\n"); 
                    setbuf(stdin, NULL);
                    getchar(); 
                    break;    

                }
            case 4:
                {
                    Pista_sort(pista2);

                    printf("\t\tPROXIMOS DESPEGUES\n");
                    Pista_Imprimir(pista2);
                    
                    printf ("Presione Enter para regresar al menu principal\n"); 
                    setbuf(stdin, NULL);
                    getchar();

                    break; 
                }   
            case 5:
                { 
                    printf("\t\tSOLICITAR DESPEGUE\n");
                    
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
                       
                        printf ("\nRealizado con exito!\n");
                    }else{
                        printf("\nNo hay solicitudes de despegue\n");
                    }
                    
                    printf ("Presione Enter para regresar al menu principal\n"); 
                    setbuf(stdin, NULL);
                    getchar();
                    
                    break;
                }   
            case 6:
                {
                    printf("\t\tAUTORIZAR DESPEGUE\n");

                    if(!DLL_IsEmpty(sol_salida)){

                        DLL_Traverse(sol_salida,print);
                        int t;
                        printf("Aceptar solicitud de despegue(Si=1): ");
                        scanf("%d",&t);
                        if( t == 1 )
                        {
                                Item sal1,sal2;
                                Pista_Takeoff(pista2,&sal1);
                                DLL_RemoveBack(sol_salida,&sal2);
                        
                                Avion_archivo(reporteDes,sal1);
                                printf ("\nRealizado con exito!\n");
                        }

                    }else{
                        printf("\nNo hay ninguna solicitud de salida\n");
                    }
                    printf ("Presione Enter para regresar al menu principal\n"); 
                    setbuf(stdin, NULL);
                    getchar();
                    
                    break;   
                }       
            case 7:
                { 
                    printf("\t\tAVIONES DISPONIBLES \n");
                    DLL_Traverse( disponible, print); 
                    
					printf ("Presione Enter para regresar al menu principal\n"); 
                    setbuf(stdin, NULL);
                    getchar ( );  

                    break;
                }
            case 8:
                {
                    printf("\t\tCARGAR AVION \n");

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
                            printf ("\nAvion cargado con exito!\n"); 
                        }else{
                            printf("\nAvion NO cargado\n");
                        }

                    }else{
                        printf("No hay aviones disponibles");
                    }
                    
                    printf ("Presione Enter para regresar al menu principal\n"); 
                    setbuf(stdin, NULL);
                    getchar();
                    
                    break;        
                }
            case 9:
                {
                    printf("\t\tAVIONES DANADOS\n");
                    DLL_Traverse( danados, print);
                    printf ("Presione Enter para regresar al menu principal\n"); 
                    setbuf(stdin, NULL);
                    getchar();

                    break;
                } 
            case 10:
                {
                    printf("\t\tREPARAR AVIONES \n");

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
                            }
                        }

                    }
					printf ("Presione Enter para regresar al menu principal\n"); 
                    setbuf(stdin, NULL);
                    getchar();
                    break;  
                }   
            case 11:
                {
                    printf("\n\t\tFENOMENO METEREOLOGICO\n");
                    printf ("\nDetener todas las actividades -> 1\nRegresar al menu principal -> 0\n"); 
					int choice; 
					scanf ("%d", &choice );  
                    if (choice == 1)
                    {
                    	stop = 0; 
                    	printf ("\nDeteniendo todas las actividades\n"); 
                    	printf ("Presione Enter para regresar al menu principal\n"); 
                   		setbuf(stdin, NULL);
                    	getchar();
                    }
                    else{
                    	break; 
                    }
                    
                    break;
                }     

            default:
                    printf( "Opcion no reconocida\n" );
                    break;
        }
    
    }

    return 0;
}
