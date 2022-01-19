/*Realizzare il sottoprogramma duplicati che riceve come parametro una lista L per la gestione dei
numeri interi e qualsiasi altro parametro ritenuto necessario; il sottoprogramma restituisce una NUOVA
lista contenente solamente i valori di L che sono duplicati, cioè di cui esistono due o più occorrenze.
Ad esempio, se il sottoprogramma riceve la lista L riportata di seguito:
1-> 3 ->30-> 29->1->29->1
restituirà la lista:
1->29
(Si possono usare le funzioni definite a lezione.)*/

#include<stdio.h>
#include<stdlib.h>

typedef struct N{
	int val;
	struct N *next;
}nodo_t;

typedef nodo_t *Ptr_nodo;
Ptr_nodo inserisci_in_coda(Ptr_nodo l, int v);
Ptr_nodo duplicati(Ptr_nodo l);
int conta(int n, Ptr_nodo l);
int isLista(int n, Ptr_nodo l);
void visualizza(Ptr_nodo l);

int main(){
    Ptr_nodo l;
    l = NULL;

    /*Inizializzazione secondo l'esempio*/
    l = inserisci_in_coda(l, 1);
    l = inserisci_in_coda(l, 3);
    l = inserisci_in_coda(l, 30);
    l = inserisci_in_coda(l, 29);
    l = inserisci_in_coda(l, 1);
    l = inserisci_in_coda(l, 29);
    l = inserisci_in_coda(l, 1);

    printf("Lista inizale: ");
    visualizza(l);

    l = duplicati(l);
    printf("Lista finale: ");
    visualizza(l);

    return 0;    
}

void visualizza(Ptr_nodo l){
    while(l){
        printf("-> %d ", l->val);
        l=l->next;
    }
    printf("\n");
}
Ptr_nodo inserisci_in_coda(Ptr_nodo l, int v){
	Ptr_nodo tmp, prec;
	tmp=malloc(sizeof(nodo_t));
	if(tmp){
		tmp->val=v;
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

int conta(int n, Ptr_nodo l){
    int ris; 
    ris = 0;
    while(l){
        if(l->val == n){
            ris++;
        }

        l = l->next;
    }

    return ris;
}

int isLista(int n, Ptr_nodo l){
    int ris;
    ris = 0;
    while(l && !ris){
        if(l->val == n){
            ris = 1;
        }
        l = l->next;
    }

    return ris;
}

Ptr_nodo duplicati(Ptr_nodo l){
    Ptr_nodo ris, tmp;
    ris = NULL;
    tmp = l;
    while(tmp->next){
        if(conta(tmp->val, l)>1 && !isLista(tmp->val, ris)){
            ris = inserisci_in_coda(ris, tmp->val);
        }

        tmp = tmp->next;
    }

    return ris;
}