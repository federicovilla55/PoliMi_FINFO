/* Scrivere un sottoprogramma che ricevuta in ingresso una lista per la gestione dei numeri interi modifica la stessa togliendo tutti gli elementi che
contengono un numero il cui valore assoluto è un numero primo.
(1 pto) Definire un tipo di dato opportuno per gli elementi della lista.
Si considerino già disponibili e non da sviluppare i sottoprogrammi relativi alle liste*/

#include<stdio.h>
#include<stdlib.h>

typedef struct N{
    int val;
    struct N*next;
}nodo_t;
typedef nodo_t* Ptr_nodo;

int isPrime(int n){
    int i, ris;
    ris = 1;

    for(i=2; i<=n/2 && ris; i++){
        if(n % i == 0)
            ris = 0;
    }

    return ris;
}

Ptr_nodo delete(Ptr_nodo l, int n){
    Ptr_nodo curr, tmp, prec;
    int i;

    i = 0;
    curr = l;
    prec = NULL;

    while(curr){
        if(curr->val == n){
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

Ptr_nodo deletePrime(Ptr_nodo l){
    Ptr_nodo tmp;
    tmp = l;

    while(tmp){
        if(isPrime(tmp->val)){
            l = delete(l, tmp->val);
        }
        tmp = tmp->next;
    }

    return l;
}