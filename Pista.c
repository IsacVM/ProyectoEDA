/******         Pista.c         ******/

#include "Pista.h"

//Funcion privada para convertir Segundos a horas en formato (hh:mm)
void Segundos_a_horas(Item this, int* _hora1, int* _minutos1,int* _hora2, int* _minutos2){

 *_hora1=this.hora_salida/3600;
 *_minutos1=(this.hora_salida%3600)/60;
 *_hora2=this.hora_llegada/3600;
 *_minutos2=(this.hora_llegada%3600)/60;

}
//Función privada para imprimir aviones
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
  printf("Hora salida: %02d:%02d\n",h1,m1);
  printf("Hora llegada: %02d:%02d\n",h2,m2);
  printf("\n\n");
}


PistaPtr Pista_New(	 int _capacidad){
	PistaPtr n_pista=(PistaPtr)malloc(sizeof(Pista));

	if(n_pista){
		n_pista->track=DLL_New();

		if(n_pista->track){
			n_pista->capacidad=_capacidad;
			n_pista->espacio_libre=_capacidad;
		}

	}
	
	return n_pista;
}

bool Pista_Landing(	PistaPtr this,Item _avion){

	assert( this );
	
	bool done=false;
	if (DLL_InsertFront(this->track,_avion)){
		done=true;
		this->espacio_libre--;
	}
	return done;
}

bool Pista_Takeoff(	PistaPtr this,ItemPtr _avion){
	assert( this );
	bool done=false;
	Item salida;
	if(DLL_RemoveBack(this->track,&salida)){
		done=true;
		this->espacio_libre++;
	}
	*_avion=salida;
	
	//liberamos memoria
	Avion_Delete(&salida);

	return done;

}

void Pista_Imprimir( PistaPtr this){
	assert( this );
	DLL_Traverse(this->track,imprime);
}

void Pista_Delete(PistaPtr this){
	assert( this );
	DLL_Delete(this->track);
	free(this);
}

bool Pista_IsEmpty( PistaPtr this ){
    assert( this );
    return DLL_IsEmpty( this->track );
}

void Pista_Peek( PistaPtr this,ItemPtr _avion ){
    assert( !DLL_IsEmpty( this->track ) );

    Item value;
    DLL_CursorLast( this->track );
    DLL_Peek( this->track, &value );

	*_avion=value;

	Avion_Delete(&value);
    
}

