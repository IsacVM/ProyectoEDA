/***------API Avión--------***/

/**
 * @brief Resetea los valores hora_llegad,hora_salida,pasajeros
 *  y estado de un avion.
 * @param apuntador a un avión
 * @return nada
 */
void Avion_Reset(ItemPtr this){

	 this->pasajeros=0;
	 this->hora_llegada=0;
	 this->hora_salida=0;
	 this->estado=2;
}
/**
 * @brief Asigna valores a los campos:hora_llegad,hora_salida,pasajeros
 *  y estado de un avion.
 * @param apuntador a un avión, el valor de: hora_llegada, hora_salida
 * @return nada
 */
void Avion_Llenar(ItemPtr this,int _hora_llegada, int _hora_salida){

	srand( time( 0 ) );
    // inicializamos al generador de números aleatorios
	 int capacidad=this->capacidad;
	 // genera un número aleatorio en el rango 0..capacidad del avion
	 int value = rand() % capacidad;
     this->pasajeros=value;
	 this->hora_llegada=_hora_llegada;
	 this->hora_salida=_hora_salida;
	 this->estado=1;
}
/**
 * @brief Libera memoria utilizada por un avión
 * @param apuntador a un avión
 * @return nada
 */
void Avion_Delete(ItemPtr this){
     if( this ){
       
        free( this );
    }
}


void Avion_ResetHorario(ItemPtr this, int _hora_salida, int _hora_llegada){

	this->hora_salida=_hora_salida;
	this->hora_llegada=_hora_llegada;
	 
}