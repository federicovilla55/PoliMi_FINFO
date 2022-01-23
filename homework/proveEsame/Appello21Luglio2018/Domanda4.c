/*Realizzare la funzione list_max() che accetta come parametro due liste L1 e L2 (e qualsiasi altro
parametro ritenuto necessario), che sono garantite avere la stessa lunghezza (potrebbero essere entrambe
vuote). La funzione deve restituire una NUOVA lista L3, senza modificare ne' L1 ne' L2, avente la
stessa lunghezza di una delle liste in input, e i cui elementi siamo il massimo degli elementi
corrispondenti di L1 ed L2.
Ad esempio, se L1 = (0, 1, 2, 3) e L2 = (10, -3, 4, -2), allora L3= (10, 1, 4, 3) (il primo elemento e' il
massimo tra i primi elementi di L1 ed L2; il secondo elemento e' il massimo tra i secondi elementi di L1
ed L2; e cosi' via).
Se lo si ritiene utile, e' possibile definire ulteriori funzioni.*/

#include<stdio.h>
#include<stdlib.h>

typedef struct nodo_{
    int dato;
    struct nodo_* next;
} nodo_t;
typedef nodo_t* Ptr_nodo;

Ptr_nodo inserisci_in_coda(Ptr_nodo l, int v);
void visualizza(Ptr_nodo l);
Ptr_nodo lista_max(Ptr_nodo l1, Ptr_nodo l2);

int main(){
    Ptr_nodo l1, l2;

    l1 = NULL;
    l2 = NULL;
    l1 = inserisci_in_coda(l1, 0);
    l1 = inserisci_in_coda(l1, 1);
    l1 = inserisci_in_coda(l1, 2);
    l1 = inserisci_in_coda(l1, 3);
    l2 = inserisci_in_coda(l2, 10);
    l2 = inserisci_in_coda(l2, -3);
    l2 = inserisci_in_coda(l2, 4);
    l2 = inserisci_in_coda(l2, -2);
    
    l1 = lista_max(l1, l2);

    visualizza(l1);

    return 0;
}

void visualizza(Ptr_nodo l){
    while(l){
        printf("-> %d ", l->dato);
        l=l->next;
    }
    printf("\n");
}

Ptr_nodo inserisci_in_coda(Ptr_nodo l, int v){
	Ptr_nodo tmp, prec;
	tmp=malloc(sizeof(nodo_t));
	if(tmp){
		tmp->dato=v;
		tmp->next=NULL;
		if(l==NULL)
			l=tmp;
		else{
			for(prec=l; prec->next!=NULL; prec=prec->next);

			prec->next=tmp;
		}
	}
    return l;
}

Ptr_nodo lista_max(Ptr_nodo l1, Ptr_nodo l2){
    Ptr_nodo l3;
    l3 = NULL;
    while(l1){
        if(l1->dato > l2->dato)
            l3 = inserisci_in_coda(l3, l1->dato);
        else
            l3 = inserisci_in_coda(l3, l2->dato);
        
        l1 = l1->next;
        l2 = l2->next;
    }

    return l3;
}