/*Realizzare la funzione list_min() che accetta come parametro due liste L1 e L2 (e qualsiasi altro
parametro ritenuto necessario), che sono garantite avere la stessa lunghezza (potrebbero essere entrambe
vuote). La funzione deve restituire una NUOVA lista L3, senza modificare ne' L1 ne' L2, avente la
stessa lunghezza di una delle liste in input, e i cui elementi siamo il minimo degli elementi
corrispondenti di L1 ed L2.
Ad esempio, se L1 = (0, 1, 2, 3) e L2 = (10, -3, 4, -2), allora L3= (0, -3, 2, -2) (il primo elemento e' il
minimo tra i primi elementi di L1 ed L2; il secondo elemento e' il minimo tra i secondi elementi di L1
ed L2; e cosi' via).
Se lo si ritiene utile, e' possibile definire ulteriori funzioni.*/

#include<stdio.h>
#include<stdlib.h>

typedef struct N{
    int val;
    struct N *next;
} nodo_t;
typedef nodo_t* Ptr_nodo;

Ptr_nodo inserisciCoda(Ptr_nodo l, int n);
Ptr_nodo lista_min(Ptr_nodo l1, Ptr_nodo l2);
void visualizza(Ptr_nodo l);

int main(){
    Ptr_nodo l1, l2;
    l1 = NULL;
    l2 = NULL;
    l1 = inserisciCoda(l1, 0);
    l1 = inserisciCoda(l1, 1);
    l1 = inserisciCoda(l1, 2);
    l1 = inserisciCoda(l1, 3);
    l2 = inserisciCoda(l2, 10);
    l2 = inserisciCoda(l2, -3);
    l2 = inserisciCoda(l2, 4);
    l2 = inserisciCoda(l2, -2);

    l1 = lista_min(l1, l2);

    visualizza(l1);

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

Ptr_nodo lista_min(Ptr_nodo l1, Ptr_nodo l2){
    Ptr_nodo l3;
    int n;

    l3 = NULL;
    while(l1){
        if(l1->val < l2->val)
            n = l1->val;
        else
            n = l2 ->val;
        
        l3 = inserisciCoda(l3, n);

        l1 = l1->next;
        l2 = l2->next;
    }

    return l3;
}  