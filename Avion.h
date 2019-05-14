#ifndef _AVION_H_
#define _AVION_H_

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>


typedef struct
{
	char _nombre[20];
	int pasajeros;
	int capacidad;
	int estado;//1=ocupado,2=disponnible,3=dañado
	int hora_salida;//en segundos
	int hora_llegada;//en segundos

}Avion;

typedef Avion Item;
typedef Item* ItemPtr;
//data para la lista DLL


void Avion_Reset(ItemPtr this);
void Avion_Llenar(ItemPtr this);
void Avion_Delete(ItemPtr this);



//void Avion_sacarFrente(DLL* this, ItemPtr salir);
//ItemPtr Avion_New(char* _nombre,char* _pasajeros, char* capacidad, char* estado,char* h_ll, char* h_s);
/*void Avion_Print( ItemPtr this );
void 	 Avion_eliminar(   AvionPtr this );
void 	 Aviones_Imprimir();*/
/*void     Avion_llenar(     AvionPtr this, Item _data );
char     Avion_extraer(      AvionPtr this );
char     Avion_Peek(     AvionPtr this );//Devuelve todo los datos del avion
bool     Avion_IsEmpty(  AvionPtr this );
void     Avion_vaciar( AvionPtr this);
size_t   Avion_Len(      AvionPtr this );
size_t   Avion_Capacity( AvionPtr this );
bool     Avion_IsFull(   AvionPtr this );
bool     Avion_chocar ( AvionPtr this);*/

#endif