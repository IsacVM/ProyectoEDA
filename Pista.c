#include "Pista.h"
	#include <stdio.h>
	#include <stdlib.h>
	#include <stdbool.h>
	#include <assert.h>
	#include <stdbool.h>
	#include <string.h>



	Pista* Pista_New(	 int _capacidad){
		n_pista=(pista*)malloc(sizeof(pista));
		n_pista->track=DLL_New();
		n_pista->capacidad=_capacidad;
		n_pista->espacio_libre=_capacidad;
		return n_pista;
	}
	//aterriza el avion, si si pudo aterrizar true
	bool Pista_Landing(	 Pista this,Avion _avion){
		bool check = false;
		DLL_InsertBack(this,avion);
		if (DLL_InsertBack(this,avion)){
			check=true;
			this->espacio_libre--;
		}
		return check;
	}
	//despega un avion, sipudo, true
	bool Pista_Takeoff(	 Pista this){

		bool check = false;
		Avion salida;
		DLL_RemoveFront(this,*salida);
		if (DLL_RemoveFront(this,*salida)){
			printf("salió el avión: %s \n",salida->nombre );
			check=true;
			this->espacio_libre++;
		}
		return check;

	}
	//imprime los datos de la pista/la pista completa

	/*
			char _nombre[20];
	int pasajeros;
	int capacidad;
	int estado;//1=ocupado,2=disponnible,3=dañado
	int hora_salida;//en segundos
	int hora_llegada;//en segundos

		Avion_Imprimir(Avion this){
			
			string salida=conversion_segundos(this->hora_salida);
			string llegada=conversion_segundos(this->hora_llegada);

			string status;
			switch(this->estado):
			case 1:
				status="ocupado";
			break;
			case 2:
				status="disponible";
			break;
			case 3:
				status="dañado";
			break;

			printf("/////%s",this->nombre);
			printf("\n capacidad : %d estado : %s\n llegada : %s \n salida : %s",this->capacidad,status,llegada,salida);
		}

	*/
	void Pista_Imprimir( Pista this){
		//no se como se tiene que integrar el apuntador al traverse que tenemos
		DLL_Traverse(this->track,*Avion_Imprimir());
	}

	void Pista_Delete(	 Pista this){

		DLL_Delete(this->track);
		free(this);
	}

