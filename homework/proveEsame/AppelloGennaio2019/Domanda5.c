#include<stdio.h>
#include<stdlib.h>

typedef struct N{
    int val;
    struct N *next;
}nodo_t;
typedef nodo_t * Ptr_nodo;

void print_list(Ptr_nodo n){
    while(n){
        printf("%d -> ", n->val);
        n=n->next;
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

Ptr_nodo sottolistad(Ptr_nodo l){
    int i;
    Ptr_nodo ris;
    i = 0;
    ris = NULL;
    while(l){
        if(i%2==1){
            ris = inserisci_in_coda(ris, l->val);
        }
        i++;
        l = l->next;
    }
    return ris;
}

int main(){
    Ptr_nodo lista1, lista2;
    lista1 = NULL;

    /* Inserisco nella lista di partenza i valori dell'esempio */
    lista1 = inserisci_in_coda(lista1, 13);
    lista1 = inserisci_in_coda(lista1, 9);
    lista1 = inserisci_in_coda(lista1, -1);
    lista1 = inserisci_in_coda(lista1, 21);
    lista1 = inserisci_in_coda(lista1, 33);
    lista1 = inserisci_in_coda(lista1, 75);
    lista1 = inserisci_in_coda(lista1, -91);
    printf("Ecco la lista iniziale: ");
    print_list(lista1);
    printf("\n");
    /* Fine inserimento */

    lista2 = sottolistad(lista1);
    printf("Ecco la lista finale: ");
    print_list(lista2);
    printf("\n");

    return 0;
}