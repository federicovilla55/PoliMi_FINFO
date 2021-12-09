/* La programmazione complessa con svariate righe di codice presenta ogni parte separata 
 * in file diversi, in C per usare ad esempio funzioni da diversi file bisogna dapprima
 * creare un file *.h ad esempio "liste.h" che contiene i tipi e i prototipi delle funzioni,
 * poi con il file "liste.c" che contiene un riferimento all'header creato in precedenza:
 * (#include"liste.h") e in questo file inseriamo il contenuto delle funzioni i cui prototipi
 * sono presenti in liste.h. Lo stesso riferimento (#include"liste.h") deve essere fatto in
 * tutti i vari file in cui si usano le funzioni.
 * Per compilare ed eseguire si usa poi:
 * gcc -c es1.c
 * gcc -c liste.c
 * gcc es1.o liste.o
 * ./a.out */

#include "liste.h"
#include<stdio.h>
#include<stdlib.h>

/*Funzioni:
 * inserisci_in_testa(int v, Ptr_nodo n);
 * free_list(Ptr_nodo l);
 * lunghezza_lista(Ptr_nodo l);
*/

Ptr_nodo inserisci_in_testa(int v, Ptr_nodo n){
	Ptr_nodo r;
	r = malloc(sizeof(nodo_t));
	if(!r){
		return NULL;
	}

	r->val = v;
	r->next = n;
	return r;
}

void free_list(Ptr_nodo l){
    Ptr_nodo succ;
    while(l){
        succ = l->next;
        free(l);
        l = succ;
    }
}

int lunghezza_lista (Ptr_nodo l){
    int len;
    len=0;
    while(l){
        len++;
        l=l->next;
    }

    return len;
}