#include<stdio.h>
#include<stdlib.h>
typedef struct N{
	int dato;
	struct N *next;
}nodo_t;
typedef nodo_t* ptr_nodo;



int lunghezzaLista(ptr_nodo l){
	int i;
	i=0;
	while(l){
		l=l->next;
		i++;
	}

	return i;
}

void visualizza(ptr_nodo l){
	while(l){
		printf("%d ", l->dato);
		l=l->next;
	}
}

ptr_nodo riferimentoLista(ptr_nodo l, int k){
	while(lunghezzaLista(l) != k){
		l=l->next;
	}
	return l;
}

int main(){
	ptr_nodo head, ris, tmp;
	int k, i;
	head=NULL;
	tmp=NULL;
	printf("Dimmi il k-esismo elemento della lista che vuoi vedere: ");
	scanf("%d", &k);

	for(i=6; i>0; i--){
		tmp=malloc(sizeof(nodo_t));
		if(tmp){
			tmp->dato=i+1;
			tmp->next=head; 
			head = tmp;
		}
	}
	ris=riferimentoLista(head, k);
	printf("Ecco il contenuto del riferimento al %d-esimo elemento: ", k);
	visualizza(ris);
	return 0;
}
