/* Scrivere un sottoprogramma delfromlist che ricevuto in ingresso una lista per la gestione dei numeri
interi ed un intero x, elimini dalla lista tutti quegli elementi che compaiono almeno x volte (e la
restituisce). Se per esempio il sottoprogramma riceve in ingresso la lista di seguito riportata ed il valore
3:
3→3→1→2→4→3→5→3→5→4
il sottoprogramma restituisce la lista seguente
1→2→4→5→5→4 */

#include<stdio.h>
#include<stdlib.h>

typedef struct N{
	int val;
	struct N *next;
}nodo_t;

typedef nodo_t * Ptr_nodo;

void visualizza(Ptr_nodo l);
int contaNum(Ptr_nodo l, int num);
Ptr_nodo delFromList(Ptr_nodo l, int x);

int main(){
	Ptr_nodo head, tmp;
	int n;
	head = NULL;
	tmp = NULL;
	
	/* Inizializzazione della lista con dei valori interi positivi  */
	printf("Dimmi dei numeri positivi: ");
	scanf("%d", &n);

	while(n>0){
		tmp = malloc(sizeof(nodo_t));
		if(tmp){
			tmp->val = n;
			tmp->next = head;
			head = tmp;
		}

		scanf("%d", &n);
	}
	/* Fine inizializzazione...  */

	printf("Dopo quante ripetizioni vuoi eliminare un elemento? ");
	scanf("%d", &n);
	head = delFromList(head, n);
	visualizza(head);
	
	return 0;
}

Ptr_nodo delFromList(Ptr_nodo l, int x){
	Ptr_nodo curr, ris, tmp;
	curr=l;
	ris = NULL;
	tmp = NULL;
	while(curr){
		if(contaNum(l, curr->val)<x){
			tmp=malloc(sizeof(nodo_t));
			if(tmp){
				tmp->val = curr->val;
				tmp->next = ris;
				ris = tmp;
			}
		}
		curr=curr->next;
	}

	return ris;
}

void visualizza (Ptr_nodo l){
	printf("Lista: ");
	while(l){
		printf("%d ", l->val);
		l = l->next;
	}
}

int contaNum (Ptr_nodo l, int num){
	int numVolte;
	numVolte = 0;
	while(l){
		if(l->val == num)
			numVolte++;
		l = l->next;
	}
	return numVolte;
}
