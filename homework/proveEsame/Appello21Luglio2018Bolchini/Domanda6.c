/*Scrivere un sottoprogramma in C selectitems che ricevuta in ingresso una lista per la gestione di valori interi e due interi min e max crea una
nuova lista contente tutti e soli i valori presenti nella lista di ingresso strettamente non compresi tra min e max, ordinati in modo decrescente, e la
restituisce al chiamante. La lista di partenza non deve essere modificata. Si considerino come dati i sottoprogrammi i cui prototipi sono riportati nel
seguito. Scrivere la dichiarazione del tipo della lista.*/

#include<stdio.h>
#include<stdlib.h>

typedef struct N{
    int dato;
    struct N * next;
}nodo_t;
typedef nodo_t * Ptr_nodo;

Ptr_nodo selectItems(Ptr_nodo l, int min, int max);
Ptr_nodo listaCrescente(Ptr_nodo l, int n);
void visualizza(Ptr_nodo l);

int main(){
    int i, v[5] = {1, 2, 7, 9, 5};
    Ptr_nodo l;
    l = NULL;

    for(i=0; i<5; i++)
        l = listaCrescente(l, v[i]);


    l = selectItems(l, 2, 5);
    
    visualizza(l);

    return 0;
}

Ptr_nodo selectItems(Ptr_nodo l, int min, int max){
    Ptr_nodo ris;
    ris = NULL;
    while(l){
        if(!(l->dato >= min && l->dato <= max))
            ris = listaCrescente(ris, l->dato);
        l = l->next;
    }
    return ris;
}

void visualizza(Ptr_nodo l){
    while(l){
        printf(" -> %d ", l->dato);
        l = l->next;
    }
    printf("\n");
}

Ptr_nodo listaCrescente(Ptr_nodo l, int n){
    Ptr_nodo tmp, element;
    element = NULL;
    element = malloc(sizeof(nodo_t));

    if(element){
        element->dato = n;
        if(l == NULL){
            element->next = NULL;
            l = element;
        }else{
            if(l->next == NULL){
                if(l->dato > element->dato){
                    tmp = l;
                    l = element;
                    l->next = tmp;
                }else{
                    element->next = NULL;
                    l->next = element;
                }
            }else{
                for(tmp = l; tmp->next && tmp->next->dato < n; tmp = tmp->next);
                element->next = tmp->next;
                tmp->next = element;
            
            }
        }
    }

    return l;
}