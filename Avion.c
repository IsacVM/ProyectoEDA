//API Avión

void Avion_Reset(ItemPtr this){

	 this->pasajeros=0;
	 this->hora_llegada=0;
	 this->hora_salida=0;
	 this->estado=2;
}

void Avion_Llenar(ItemPtr this){
     this->pasajeros=100;
	 this->hora_llegada=7200;
	 this->hora_salida=3600;
	 this->estado=1;
}

void Avion_Delete(ItemPtr this){
     if( this ){
       
        free( this );
    }
}

/*void Avion_sacarFrente(DLL* this, ItemPtr salir){
     DLL_CursorLast(this);
     DLL_RemoveBack(this,salir);
}*/