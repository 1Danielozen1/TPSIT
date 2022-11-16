/*crea  una  lista e la  stampa*/
#include <stdio.h>
#include <stdlib.h>

typedef struct  node {
    int  valore;
    struct  node* next;
}Node;


void stampaLista(Node *lista, Node *l){
	l=lista;
	printf("numeri  inseriti:\n");
	while (l!=NULL){
        printf("%d - %p \n",l->valore, l->next);
        l=l->next;
    }
}

void printList(Node *l){
	printf("%d - %p \n",l->valore, l->next);
	if(l->next != NULL){
		printList(l->next);
	}
}

int N_Nodes(Node *l){
	if(l != NULL){
		return N_Nodes(l->next)+1;
	}else{}
	return 0;
}

int contaLista(Node *lista, Node *l){
	l=lista;
	int k = 0;
	while (l!=NULL){
		l=l->next;
		k++;
    }
	return k;
}

int  main(){
	int cont = 0;
    int n;
    Node* lista;
    Node* l;
    lista=NULL;
    
    do{
        printf("Inserisci  un  naturale o  -1 per  terminare\n");
        scanf("%d",&n);
        if (n>=0) {
            if (lista==NULL) /*  prima  iterazione  */ {
                lista = (Node*)malloc(sizeof(Node));
                l = lista;
            }else /*  iterazioni  successive  */ {
                l->next = (Node*)malloc(sizeof(Node));
                l = l->next;
            }
            l->valore = n;
            l->next = NULL;
        }
    } while (n>=0);
    
	stampaLista(lista,l);
	cont = contaLista(lista,l);
	printf("\n%d",cont);
	//free(l);
	//free(lista);
    return  0;
}