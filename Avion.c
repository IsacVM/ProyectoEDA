/***------API Avion--------***/

#include "Avion.h"

void Avion_Reset(Avion* this){

	 this->pasajeros=0;
	 this->hora_llegada=0;
	 this->hora_salida=0;
	 this->estado=2;
}


void Avion_Llenar(Avion* this,int _hora_llegada, int _hora_salida){

	srand( time( 0 ) );
    // inicializamos al generador de numeros aleatorios
	 int capacidad=this->capacidad;
	 // genera un numero aleatorio en el rango 0 hasta capacidad del avion
	 int value = rand() % capacidad;
     this->pasajeros=value;
	 this->hora_llegada=_hora_llegada;
	 this->hora_salida=_hora_salida;
	 this->estado=1;
}

void Avion_Delete(Avion* this){
     if( this ){
       
        free( this );
    }
}


void Avion_ResetHorario(Avion* this, int _hora_salida, int _hora_llegada){

	this->hora_salida=_hora_salida;
	this->hora_llegada=_hora_llegada;
	 
}