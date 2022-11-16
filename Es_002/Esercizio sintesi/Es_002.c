#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/*
- creare un file .csv con COGNOME,NOME, NASCITA (annomesegiorno assegno INT)
- scorrere il file con la funzione FGETS e STRTOK
- stampare in ordine DECRESCENTE (dal più grande al più piccolo) utilizzando i puntatori e allocazione dinamica (MALLOC)
*/


#define MAX 100
#define LUNG 1024

typedef struct persone{
	char* cognome;
	char* nome;
	int annomesegiorno;
}Pers;

int contarighe(){
	FILE *fp = fopen("date.csv", "r");
	int b = 0;
	char *rig = (char*)malloc(LUNG*sizeof(char));
	if(fp == NULL){
		 printf("Il file non esiste.\n");
		 b = -1;
	 }else{
		 while(!feof(fp)) {
			 fgets(rig,LUNG,fp);
			 b++;
		 }
		 fclose(fp);
	 }
	 return b;
}


void bubbleSort(Pers *d, int n){
	Pers *sca = (Pers*)malloc(n*sizeof(Pers));
	int k, sup;
		for (sup = n-1; sup > 0; sup--){
			for (k = 0; k < sup ; k++){ 
				if ((d+k)->annomesegiorno > (d+(k+1))->annomesegiorno){
				//printf("\nok");
				*sca= *(d+k);
				*(d+k) = *(d+(k+1));
				*(d+(k+1)) = *sca;
			}else{
				//printf("\nnah");
			}
		}
	}
	free(sca);
}

void caricaStrut(Pers *d){
	FILE *fp = fopen("date.csv", "r");
	char* riga = (char*)malloc(LUNG*sizeof(char)); //creo la riga
	if(fp == NULL){
		printf("Il file non esiste.\n");
	}else{
		Pers *a = d;
		printf("Struttura non ordinata:");
		while(fgets(riga,LUNG,fp)) {
			
		    a->cognome = strdup(strtok(riga,","));
			a->nome = strdup(strtok(NULL,","));
            a->annomesegiorno = atoi(strtok(NULL,","));
			printf("\n %s %s %d",a->cognome,a->nome,a->annomesegiorno);
			a++;

        }
		printf("\n\n");
	}
	free(riga);
	fclose(fp);
}

int main(){
	int r=0;
	r = contarighe(); //conta le righe del file
	//printf("%d",r);
	if(r != -1){
		Pers *d = (Pers*)malloc(r*sizeof(Pers)); //creo il vettore di struttura
		caricaStrut(d);	//Carico la struttura
		bubbleSort(d,r); //bubbleSort
		//printf("\n%d",r);
		//*(d = 0);
		printf("Struttura ordinata:");
		for(int b = 0; b < r; b++){
			//printf("\nwhat");
			printf("\n %s %s %d",(*d).cognome,(*d).nome,(*d).annomesegiorno);
			*d++;
		}
		free(d);
	}else{}
	return 0;
}

