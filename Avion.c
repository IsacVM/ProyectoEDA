//API Avión

void Avion_Reset(ItemPtr this){

	 this->pasajeros=0;
	 this->hora_llegada=0;
	 this->hora_salida=0;
	 this->estado=2;
}

void Avion_Llenar(ItemPtr this){

	srand( time( 0 ) );
    // inicializamos al generador de números aleatorios
	 int capacidad=this->capacidad;
	 // genera un número aleatorio en el rango 0..capacidad del avion
	 int value = rand() % capacidad;
     this->pasajeros=value;
	 this->hora_llegada=7200;
	 this->hora_salida=3600;
	 this->estado=1;
}

void Avion_Delete(ItemPtr this){
     if( this ){
       
        free( this );
    }
}
