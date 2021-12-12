#include <stdio.h> 
#include <stdlib.h> 

typedef struct N{
	int dato;
	struct N *next;
}nodo_t;

typedef nodo_t* Ptr_nodo;

Ptr_nodo inserisciTesta(int n, Ptr_nodo head);
void visualizza(Ptr_nodo l);
Ptr_nodo listaRipetuta(Ptr_nodo l, int k);

int main(){
	int n;
	Ptr_nodo head;
	head=NULL;
	printf("Riempi una lista: ");
	scanf("%d", &n);

	while(n>0){
		head = inserisciTesta(n, head);
		scanf("%d", &n);
	}

	visualizza(head);

	head = listaRipetuta(head, 2);

	visualizza(head);

	return 0;
}

Ptr_nodo inserisciTesta(int n, Ptr_nodo head){
	Ptr_nodo tmp;
	tmp = NULL;
	tmp = malloc(sizeof(nodo_t));

	if(tmp){
		tmp->dato = n;
		tmp -> next = head;
		head = tmp;
	}else
		printf("Errore allocazione...");

	return head;
}

void visualizza(Ptr_nodo l){
	printf("Lista: ");
	while(l){
		printf("%d ", l->dato);
		l=l->next;
	}
	printf("\n");
}

Ptr_nodo listaRipetuta(Ptr_nodo l, int k){
	int i;
	Ptr_nodo head;

	while(l){
		for(i=0; i<k; i++)
			head = inserisciTesta(l->dato, head);
		l=l->next;
	}

	return head;
}
