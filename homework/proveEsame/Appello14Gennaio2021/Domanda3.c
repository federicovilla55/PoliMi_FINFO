/*Scrivere un sottoprogramma che ricevuta in ingresso una lista per la gestione dei numeri interi la compatta, facendo in modo che alla fine la lista
non contenga valori replicati o nulli. Il programma chiamante dovrà ovviamente accedere al termine dell’esecuzione del sottoprogramma, alla
lista compattata.
Se la lista iniziale è la seguente

1 → 3 → 5 → −2 → 3 → −1 → 0 → 2 → 4 → 1

al termine dell’esecuzione dovrà essere:

1 → 3 → 5 → −2 → −1 → 2 → 4

(1 pto) Definire un tipo di dato opportuno per gli elementi della lista.
(1 pto) Completare con la chiamata al sottoprogramma*/

#include<stdio.h>
#include<stdlib.h>

typedef struct N{
    int val;
    struct N *next;
}nodo_t;
typedef nodo_t * Ptr_nodo;

void visualizza(Ptr_nodo l);
Ptr_nodo inserisciCoda(Ptr_nodo l, int n);
int isLista(Ptr_nodo l, int n, int dim);
Ptr_nodo NoDuplicati(Ptr_nodo l);

int main(){
    int i, v[10] = {1, 3, 5, -2, 3, -1, 0, 2, 4, 1};
    Ptr_nodo l;
    l = NULL;

    for(i=0; i<10; i++){
        l = inserisciCoda(l, v[i]);
    }
    l = NoDuplicati(l);
    visualizza(l);


    return 0;
}

void visualizza(Ptr_nodo l){
    while(l){
        printf("%d -> ", l->val);
        l=l->next;
    }

    printf("\n");
}

Ptr_nodo inserisciCoda(Ptr_nodo l, int n){
    Ptr_nodo tmp, tail;
    tail = NULL;
    tmp = NULL;
    tail = malloc(sizeof(nodo_t));
    if(tail){
        tail->next = NULL;
        tail ->val = n;
        if(!l){
            l = tail;
        }else{
            for(tmp = l; tmp->next; tmp = tmp->next);
            tmp->next = tail;
        }
    }


    return l;
}

int isLista(Ptr_nodo l, int n, int dim){
    int i, found;
    found = 0;
    for(i=0; i<dim && !found; i++){
        if(l->val == n)
            found = 1;
        l = l->next;
    }
    return found;
}


Ptr_nodo NoDuplicati(Ptr_nodo l){
    Ptr_nodo curr, tmp, prec;
    int i;

    i = 0;
    curr = l;
    prec = NULL;

    while(curr){
        if(isLista(l, curr->val, i)){
            tmp = curr;
            curr = curr->next;
            if(prec != NULL){
                prec->next = curr;
            }else{
                l = curr;
            }
            free(tmp);
        }else{
            prec = curr;
            curr = curr->next;
            i++;
        }
    }
    return l;
}