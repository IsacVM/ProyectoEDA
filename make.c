#include <stdlib.h>
int main(){

	system("clear");
	system("clear");
	system("gcc -Wall -std=c99 -o play.out main.c Aviones.c Pistas.c StackHorarios.c DLL.c SLL.c -pthread");

	system("./play.out");
}