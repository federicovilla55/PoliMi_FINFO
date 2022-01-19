/*Scrivere un sottoprogramma che ricevuta in ingresso una lista L per la gestione dei numeri interi (che può
essere anche vuota) e due parametri interi k e val, restituisce una nuova lista L1 in cui vengono copiati i
valori di L e tra di loro vengono inclusi k elementi con valore val.
Ad esempio,
per L = 1->2-> -1-> 4-> -6 -|
e k=2 e val=0
la funzione deve restituire la nuova lista
L1 = 1->0->0->2->0-> 0-> -1-> 0-> 0-> 4-> 0->0-> -6->-0->0 -|
-------
Nello svolgimento dell’esercizio, si possono considerare come già disponibili sia la definizione del tipo
di dato per la gestione di liste dinamiche di interi che i relativi sottoprogrammi elencati di seguito:
typedef struct nodo_{
int dato;
struct nodo_* next;
} nodo_t;
typedef nodo_t* Ptr_nodo;
Ptr_nodo inserisciTesta(Ptr_nodo l, int n);
Ptr_nodo inserisciCoda(Ptr_nodo l, int n);
Ptr_nodo elimina(Ptr_nodo l, int pos);
Ptr_nodo distruggiLista(Ptr_nodo l);
void visualizza(Ptr_nodo l);*/

#include<stdio.h>
#include<stdlib.h>

typedef struct nodo_{
    int dato;
    struct nodo_* next;
} nodo_t;
typedef nodo_t* Ptr_nodo;

Ptr_nodo inserisci_in_coda(Ptr_nodo l, int v);
Ptr_nodo addMiddle(Ptr_nodo l, int k, int val);
void visualizza(Ptr_nodo l);

int main(){
    Ptr_nodo l;
    int k, val;
    l = NULL;
    printf("Inserisci i parametri k e val: ");
    scanf("%d %d", &k, &val);

    l=inserisci_in_coda(l, 1);
    l=inserisci_in_coda(l, 2);
    l=inserisci_in_coda(l, -1);
    l=inserisci_in_coda(l, 4);
    l=inserisci_in_coda(l, -6);
    
    visualizza(l);
    visualizza(addMiddle(l, k, val));

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


Ptr_nodo addMiddle(Ptr_nodo l, int k, int val){
    int i;
    Ptr_nodo l1;
    l1 = NULL;

    while(l){
        l1 = inserisci_in_coda(l1, l->dato);
        for(i=0; i<k; i++){
            l1 = inserisci_in_coda(l1, val);
        }
        l = l->next;
    }

    return l1;
}