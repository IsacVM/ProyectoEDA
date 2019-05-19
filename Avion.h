#ifndef _AVION_H_
#define _AVION_H_

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <time.h>


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

/**Esta función resetea los valores pasajeros, hora_llegada,
 *  hora_salida a 0 y estado a 1(disponible)
*/
void Avion_Reset(ItemPtr this);
/**Esta función asigna valores al compo pasajeros, hora_llegada,
 *  hora_salida y estado de un avión
*/
void Avion_Llenar(ItemPtr this,int _hora_llegada, int _hora_salida);
/**Esta función libera la memoria utilizada por el avion
*/
void Avion_Delete(ItemPtr this);


#endif