/*Scrivere un sottoprogramma delfromlist che ricevuta in ingresso una lista per la gestione dei numeri interi ed un intero x, elimini dalla
lista tutti quegli elementi che compaiono almeno x volte, e restituisca la lista. Se per esempio il sottoprogramma riceve in ingresso la lista di
seguito riportata ed il valore 3:
3 → 3 → 1 → 2 → 4 → 3 → 5 → 3 → 5 → 4
il sottoprogramma restituisce la lista seguente
1 → 2 → 4 → 5 → 5 → 4
(1 punto) Definire un tipo di dato opportuno per la lista.*/

#include<stdio.h>
#include<stdlib.h>

typedef struct N{
    int dato;
    struct N *next;
}nodo_t;
typedef nodo_t* Ptr_nodo;

int contaElementi(Ptr_nodo l, int n);
Ptr_nodo deleteFromList(Ptr_nodo l, int n);
Ptr_nodo delete(Ptr_nodo l, int n);
void visualizza(Ptr_nodo l);
Ptr_nodo inserisciCoda(Ptr_nodo l, int n);

int main(){
    int i, v[10] = {3, 3, 1, 2, 4, 3, 5, 3, 5, 4};
    Ptr_nodo l;

    l = NULL;

    for(i=0; i<10; i++)
        l = inserisciCoda(l, v[i]);

    visualizza(l);
    printf("Elementi 3: %d\n", contaElementi(l, 2));
    l = deleteFromList(l, 3);

    visualizza(l);


    return 0;
}

int contaElementi(Ptr_nodo l, int n){
    int ris;
    ris = 0;
    while(l){
        if(l->dato == n)
            ris++;
        l = l->next;
    }
    return ris;
}

Ptr_nodo deleteFromList(Ptr_nodo l, int n){
    Ptr_nodo tmp;
    tmp = l;
    while(tmp){
        if(contaElementi(l, tmp->dato) > n)
            l = delete(l, tmp->dato);
        tmp = tmp->next;
    }

    return l;
}

Ptr_nodo delete(Ptr_nodo l, int n){
    Ptr_nodo curr, prev, tmp;
    curr = l;
    prev = NULL;

    while(curr){
        if(curr->dato == n){
            tmp = curr;
            curr = curr->next;

            if(prev != NULL){
                prev ->next = curr;
            }else{
                l = curr;
            }

            free(tmp);

        }else{
            prev = curr;
            curr = curr->next;
        }
    }

    return l;
}

void visualizza(Ptr_nodo l){
    while(l){
        printf("%d -> ", l->dato);
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
        tail ->dato = n;
        if(!l){
            l = tail;
        }else{
            for(tmp = l; tmp->next; tmp = tmp->next);
            tmp->next = tail;
        }
    }


    return l;
}