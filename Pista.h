#indef _PISTA_
#define _PISTA_
#include "DLL.h"
#include "Avion.h"
	#include <stdio.h>
	#include <stdlib.h>
	#include <stdbool.h>
	#include <assert.h>
	#include <stdbool.h>
	#include <string.h>
	
	typedef struct pista{
		DLL* track
		int capacidad
		int espacio_libre

	}Pista
	//crea pista
	Pista* Pista_New(	 int _capacidad)
	//aterriza el avion, si si pudo aterrizar true
	bool Pista_Landing(	 Pista this,Avion _avion)
	//despega un avion, sipudo, true
	bool Pista_Takeoff(	 Pista this,Avion _avion)
	//imprime los datos de la pista/la pista completa
	void Pista_Imprimir( Pista this)
	//elimina la pista
	void Pista_Delete(	 Pista this)

