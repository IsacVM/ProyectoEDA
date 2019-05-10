//API del avion
#include "Avion.h"
/*
DLL* danados=DLL_New();
DLL* disponible=DLL_New();
DLL* entrada=DLL_New();
DLL* salida=DLL_New();

AvionPtr Avion_New(ItemC* _nombre,ItemI pasajeros, ItemI capacidad, ItemC* estado,ItemC* h_ll, ItemC* h_s){

    AvionPtr avi = (AvionPtr) malloc( sizeof ( Avion ) );
    if( avi ){
        avi->avion = DLL_New();

        if( avi->avion ){
        
           
           DLL_InsertFront(avi->avion,_nombre);
           DLL_InsertFront(avi->avion,pasajeros);
           DLL_InsertFront(avi->avion,capacidad);
           DLL_InsertFront(avi->avion,estado);
           DLL_InsertFront(avi->avion,h_ll);
           DLL_InsertFront(avi->avion,h_s);
          
        }
    }
    return avi;


}*/


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

void Avion_Print(ItemPtr this ){

   if(DLL_IsEmpty(this->plane)==true){
        printf("Empty set");
   }else{
        DLL_Traverse(this->plane,imprime);
   }
   
}

/*void    Avion_eliminar(   AvionPtr this ){
      if( this ){
        DLL_Delete( this->avion );
        free( this );
    }
}

void imprime( ItemC item )
{
  printf( "Nombre: %s\n", item._nombre);
  printf( "Pasajeros: %s\n",item.pasajeros);
  printf( "Capacidad: %s\n", item.capacidad);
  printf( "Estado: %s\n", item.estado);
  printf( "Hora llegado: %s\n", item.h_ll);
  printf( "Hora salida: %s\n", item.h_s);

}

void Aviones_Imprimir(AvionPtr this ){

   if(DLL_IsEmpty(this->avion)==true){
        printf("No hay aviones");
   }else{
        DLL_Traverse(this->avion,imprime);
   }
   
}*/