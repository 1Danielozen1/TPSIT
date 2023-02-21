#include  <stdio.h>
#include  <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define MAX_EL 5
#define MIN 1
#define MAX 10

typedef struct pila {
    int nome;
	int valore;
    struct pila *next;
} Pila;

typedef struct coda{
    int nome;
    int valore;
    struct coda *next;
}Coda;

//CODA
void enqueue(Coda** head, Coda** tail, Coda* element){
    if(is_empty(*head))
        *head = element;
    else
        (*tail)->next = element;
    
    *tail = element;
    element->next = NULL;
}

Coda* dequeue(Coda** head, Coda** tail){
    Coda* ret = *head;

    if(is_empty(*head))
        return NULL;
    else
        *head = ret->next;
    
    if(*head == NULL)
        *tail = NULL;
    
    return ret;
}

int is_empty_cod(struct coda *head){
    if (head==NULL) return 1;
    else return 0;
}

//PILA
int is_empty(struct pila *head){
    if (head==NULL) return 1;
    else return 0;
}


struct pila * pop(struct pila **head){
    struct pila * ret=*head;
    if(is_empty(*head)){
        return NULL;
    }else{
        *head = ret->next;
    }
    return ret;
}

void push(struct pila **head, struct pila *element){
    if(is_empty(*head)){
        *head=element;
        element->next=NULL;
    }else{
        element->next=*head;
        *head=element;
    }
}

//Numero casuale
int Casuale(){
    int casuale;

    casuale = rand()%MAX+MIN;
    
    return casuale;
}
//Main
int main(){
	srand(time(NULL)); 
	Pila *pil = NULL; //pila
	//coda
	Coda* head = NULL;     
    Coda* tail = NULL; 
	
	Coda* numero;
	int b = 0;

	for(int a = 0; a<MAX_EL; a++){
		//carico pila
		struct pila *new_val = (struct pila*) malloc(sizeof(struct pila));
		new_val->nome = a;
		new_val->valore = Casuale();
		printf("Pila: %d = %d\n", new_val->nome+1, new_val->valore);
		new_val->next = NULL;
		push(&pil,new_val);
		//carico coda
		numero = (Coda*)malloc(sizeof(Coda));
		numero->nome = a;
        numero->valore = Casuale();
		printf("Coda: %d = %d\n", numero->nome+1, numero->valore);
        numero->next = NULL;
		enqueue(&head, &tail, numero);
	}
	printf("\n\n");
	//controllo
	while(!is_empty(pil) || !is_empty_cod(head)){
		if(pil->valore > head->valore){
			printf("%d) %d vs %d:\nVincitore: %d\n",b+1,pil->valore,head->valore,pil->valore);
			pil->valore -= head->valore;
			free(dequeue(&head, &tail));
			/*		val_pil = pop(&pil);
		val_cod = dequeue(&head, &tail);*/
		}else if(head->valore > pil->valore){
			printf("%d) %d vs %d:\nVincitore: %d\n",b+1,pil->valore,head->valore,head->valore);
			head->valore -= pil->valore;
			free(pop(&pil));
		}else if(head->valore == pil->valore){
			printf("%d) Non ci sono vincitori.\n",b+1);
			free(pop(&pil));
			free(dequeue(&head, &tail));
		}
		b++;
	}
	
}