#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>

typedef struct
{
	char _nombre[20];
	char pasajeros[20];
	char capacidad[20];
	char estado[20];
	char hora_salida[20];
	char hora_llegada[20];

}Avion;

typedef Avion Item;
typedef Item* ItemPtr;










//void Avion_Print( ItemPtr this );
/*AvionPtr Avion_New(ItemC* _nombre,ItemC* _pasajeros, ItemC* capacidad, ItemC* estado,ItemC* h_ll, ItemC* h_s);
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