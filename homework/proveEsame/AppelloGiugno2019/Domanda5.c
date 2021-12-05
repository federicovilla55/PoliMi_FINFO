/* Domanda 5- (…/6 punti)
Si definisca un sottoprogramma che riceve come parametri una lista per la gestione dei numeri interi
L, un intero k e qualsiasi altro parametro ritenuto necessario. Si garantisce che la lista L ha un numero
pari di nodi (potrebbe anche essere vuota). Il sottoprogramma deve modificare L inserendo un nuovo
nodo in posizione centrale contenente il valore k, e restituire la lista così modificata.
Ad esempio, se il sottoprogramma riceve la lista riportata nel seguito e il valore 99:
1 -->2 --> 3 --> 4 --> 5 --> 6
allora il sottoprogramma restituirà la lista
1--> 2 -->3 --> 99--> 4--> 5--> 6.
Come caso particolare, se L è vuota, il sottoprogramma deve restituire una nuova lista contenente un
singolo nodo con il valore indicato. */
#include<stdio.h>
#include<stdlib.h>
typedef struct N{
	int dato;
	struct N *next;
} nodo_t;

typedef nodo_t* ptr_nodo;

ptr_nodo addMiddle(ptr_nodo testa, int k);
void visualizza(ptr_nodo l);
int main(){
	int i, n;
	ptr_nodo tmp, testa;
	testa = NULL;
	tmp = NULL;
	/*Inizializzo la lista con un numero pari di valori: */
	for(i=0; i<6; i++){
		tmp = malloc(sizeof(nodo_t));
		if(tmp){
			tmp->dato = i+1;
			tmp->next = testa;
			testa = tmp;
		}
	}
	
	visualizza(testa);
	printf("\n");

	n = 33;
	
	testa = addMiddle(testa, n);
	
	/*visualizza(testa);*/

	return 0;
}

void visualizza(ptr_nodo l){
	while(l){
		printf("%d ", l->dato);
		l = l->next;
	}
}

ptr_nodo addMiddle(ptr_nodo testa, int k){
	ptr_nodo l1, tmp;
	int i, j;

	j = 0;

	l1 = NULL;
	tmp=NULL;
	
	j=6;
	
	for(i=0; i<j; i++){
		tmp = malloc(sizeof(nodo_t));
		if(i==j/2){
			tmp->dato = k;
			tmp -> next = l1;
			l1 = tmp;
			tmp= malloc(sizeof(nodo_t));
		}
		tmp->dato = testa->dato;
		tmp->next = l1;
		l1 = tmp;
		testa = testa->next;
	}
	visualizza(l1);
	return l1;
}
