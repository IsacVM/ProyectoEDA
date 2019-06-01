 /******         Pista.c         ******/

#include "Pistas.h"

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

	return done;

}

void Pista_Imprimir( PistaPtr this){
	assert( this );
	DLL_Traverse(this->track, print );
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
    
}

void Pista_sort(PistaPtr this){
	assert( this );
	
	DLL_Sort(this->track);
}
