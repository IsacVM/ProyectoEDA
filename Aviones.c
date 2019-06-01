/**
 * @file Aviones
 * @Author Team
 * @date 1 junio 2019
 * @brief Proyecto - EDA-I
 * @note Grupo: 0007, Semestre 2019-2
 */
 
#include "Aviones.h"

/**
 * @fn Convierte segundos al formato hh:mm:ss
 */
static void Segundos_a_hora(Avion this, int* _hora1, int* _minutos1,int* _hora2, int* _minutos2){

 *_hora1 = this.hora_salida/3600;
 *_minutos1 = (this.hora_salida%3600)/60;
 *_hora2 = this.hora_llegada/3600;
 *_minutos2 = (this.hora_llegada%3600)/60;

}

void Avion_Reset(AvionPtr this){

	 this->pasajeros = 0;
	 this->hora_llegada = 0;
	 this->hora_salida = 0;
	 this->estado = 2;
}


void Avion_Llenar(AvionPtr this,int _hora_llegada, int _hora_salida){

	srand( time( 0 ) );
    /**< inicializamos al generador de numeros aleatorios */
	int capacidad=this->capacidad;
	/**< genera un numero aleatorio en el rango 0 hasta capacidad del avion */
	int value = rand() % capacidad;
    this->pasajeros = value;
	this->hora_llegada = _hora_llegada;
	this->hora_salida = _hora_salida;
	this->estado = 1;
}

void Avion_ResetHorario(AvionPtr this, int _hora_salida, int _hora_llegada){
	this->hora_salida=_hora_salida;
	this->hora_llegada=_hora_llegada;
}

void Avion_archivo(FILE* archivo, Avion this){

		fprintf(archivo,"\n");
		int h1,h2,m1,m2;
		Segundos_a_hora(this,&h1,&m1,&h2,&m2);
		fputs(this._nombre,archivo);
		fprintf(archivo,"\t\t\t");
		fprintf(archivo,"%d\t\t\t",this.pasajeros);
		fprintf(archivo,"%d\t\t\t",this.capacidad);
		fprintf(archivo,"%02d:%02d\t\t\t",h2,m2);
		fprintf(archivo,"%02d:%02d\t\t\t",h1,m1);

		fprintf(archivo,"\n");

}
