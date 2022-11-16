#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
ALLOCAZIONE DINAMICA
*/


int main(){
	int a[10]; //allocazione statica
	int *b,n = 100;
	//per fare l'allocazione dinaminca usiamo il comando malloc
	b = (int*)malloc(n*sizeof(int) /*dobbiamo dire quanta memoria deve occupare l'array*/);
	//è una funzione che ha come parametro l'area di memoria voluta e ritorna un puntatore a void.
	//Dobbiamo sempre usare un casting per dichiararla.
	//MEMORY LEAK  USARE free() SERVE PER LIBERARE LA RAM
	free(b);
	return 0;
}
