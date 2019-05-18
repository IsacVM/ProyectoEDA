/***------API Avion--------***/


void Avion_Reset(ItemPtr this){

	 this->pasajeros=0;
	 this->hora_llegada=0;
	 this->hora_salida=0;
	 this->estado=2;
}


void Avion_Llenar(ItemPtr this,int _hora_llegada, int _hora_salida){

	srand( time( 0 ) );
    // inicializamos al generador de nÃºmeros aleatorios
	 int capacidad=this->capacidad;
	 // genera un nÃºmero aleatorio en el rango 0..capacidad del avion
	 int value = rand() % capacidad;
     this->pasajeros=value;
	 this->hora_llegada=_hora_llegada;
	 this->hora_salida=_hora_salida;
	 this->estado=1;
}

void Avion_Delete(ItemPtr this){
     if( this ){
       
        free( this );
    }
}
