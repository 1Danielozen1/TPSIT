#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LUNG 1024
#define MAX 16600

typedef char Stringa[LUNG];
typedef struct gioco {
    int rank;
    char* nome;
    char* plat;
    int anno;
    char* Genre;
    char* Publ;
    float na;
    float eu;
    float jp;
    float other;
    float global;
} Gioco;
//Rank,Name,Platform,Year,Genre,Publisher,NA_Sales,EU_Sales,JP_Sales,Other_Sales,Global_Sales
int main() {
    Gioco *d= (Gioco*)malloc(MAX*sizeof(Gioco));
    FILE *fp = fopen("vgsales.csv", "r");
    int a = 1;
    Stringa riga;
    int cont;
    if(fp == NULL) {
        printf("Il file non esiste.\n");
    } else {
        fgets(riga,LUNG,fp); //tolgo la prima riga (intestazione)
        while(!feof(fp)) {
            fgets(riga,LUNG,fp);
            (*d).rank = atoi(strtok(riga,","));
            (*d).nome = strtok(NULL,",");
            (*d).plat = strtok(NULL,",");
            (*d).anno = atoi(strtok(NULL,","));
            (*d).Genre = strtok(NULL,",");
            (*d).Publ = strtok(NULL,",");
            (*d).na = atof(strtok(NULL,","));
            (*d).eu = atof(strtok(NULL,","));
            (*d).jp = atof(strtok(NULL,","));
            (*d).other = atof(strtok(NULL,","));
            (*d).global = atof(strtok(NULL,","));
            printf("\n %d %s %s %d %s %s %.2f %.2f %.2f %.2f %.2f",(*d).rank, (*d).nome,(*d).plat,(*d).anno,(*d).Genre,(*d).Publ,(*d).na,(*d).eu,(*d).jp,(*d).other,(*d).global);
			*d++;
			a++;
        }
    }
	printf("\nSpazio = %d\nRighe = %d\n",MAX*sizeof(Gioco),a);
	free(d);
    fclose(fp);
    system("PAUSE");
    return 0;
}


/* g[a].rank = atoi(strtok(riga,","));
             g[a].nome = strtok(NULL,",");
             g[a].plat = strtok(NULL,",");
             g[a].anno = atoi(strtok(NULL,","));
             g[a].Genre = strtok(NULL,",");
             g[a].Publ = strtok(NULL,",");
             g[a].na = atof(strtok(NULL,","));
             g[a].eu = atof(strtok(NULL,","));
             g[a].jp = atof(strtok(NULL,","));
             g[a].other = atof(strtok(NULL,","));
             g[a].global = atof(strtok(NULL,","));
             printf("\n %d %s %s %d %s %s %.2f %.2f %.2f %.2f %.2f",g[a].rank, g[a].nome,g[a].plat,g[a].anno,g[a].Genre,g[a].Publ,g[a].na,g[a].eu,g[a].jp,g[a].other,g[a].global);
             a++;*/