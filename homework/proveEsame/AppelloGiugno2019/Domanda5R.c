#include<stdio.h>
#include<stdlib.h>
typedef struct N{
	int dato;
	struct N *next;
} nodo_t;
typedef nodo_t *ptr_nodo;
int lunghezzaLista(ptr_nodo l);
void visualizza(ptr_nodo l);
ptr_nodo inserisciMezzo(ptr_nodo l, int k);

int main(){
	int n;
	ptr_nodo tmp, head;
	head = NULL;
	tmp = NULL;
	printf("Riempi una lista: ");
	scanf("%d ", &n);
	while(n>=0){
		tmp=malloc(sizeof(nodo_t));
		if(tmp){
			tmp->dato = n;
			tmp->next = head;
			head = tmp;
		}
		scanf("%d ", &n);
	}
	printf("Dimmi un valore: ");
	scanf("%d", &n);
	visualizza(head);
	head = inserisciMezzo(head, n);
	visualizza(head);
	
	return 0;
}

void visualizza(ptr_nodo l){
	while(l){
		printf("%d ", l->dato);
		l=l->next;
	}
	printf("\n");
}
int lunghezzaLista(ptr_nodo l){
	int i;
	i=0; 
	while(l){
		i++;
		l=l->next;
	}
	return i;
}
ptr_nodo inserisciMezzo(ptr_nodo l, int k){
	ptr_nodo tmp, curr;
	int i, mid;
	mid =  lunghezzaLista(l)/2;
	tmp=NULL;
	curr = l;
	i=0;
	while(curr){
		if(i==mid-1){
			tmp=malloc(sizeof(nodo_t));
			if(tmp){
				tmp->dato = k;
				tmp->next = curr->next;
				curr->next = tmp;
			}
		}
		i++;
		curr=curr->next;
	}
	
	return l;
}
