/*(5 pti) Scrivere un sottoprogramma listapicchi che ricevuta in ingresso una lista ne restituisce una nuova costituita da tutti e soli gli elementi
della prima lista seguiti solo da elementi con un valore strettamente inferiore a quello dell’elemento stesso. L’ultimo elemento della lista viene
messo nella nuova lista creata.
Per esempio, se la lista in ingresso è
1 -> 5 -> 13 -> 11 -> 11 -> 4 -> -3 -> 1 -> -5
la lista restituita conterrà:
13 -> 11 -> 4 -> 1 -> -5
(1 pto) Definire un tipo di dato opportuno Ptr_nodo per la gestione di liste concatenate semplici per memorizzare un valore intero.
(2 pti) Scrivere una variante del sottoprogramma listapicchi che non inserisce nella lista dei picchi l’ultimo elemento della lista ricevuta in
ingresso*/

#include<stdio.h>
#include<stdlib.h>

typedef struct N{
    int val;
    struct N *next;
}nodo_t;
typedef nodo_t * Ptr_nodo;

void visualizza(Ptr_nodo l);
Ptr_nodo listaPicchi(Ptr_nodo l);
Ptr_nodo listaPicchiNoLast(Ptr_nodo l);
Ptr_nodo inserisciCoda(Ptr_nodo l, int n);

int main(){
    Ptr_nodo l;
    int i, v[9] = {1, 5, 13, 11, 11, 4, -3, 1, -5};
    l = NULL;
    for(i=0; i<9; i++)
        l = inserisciCoda(l, v[i]);
    
    l = listaPicchi(l);
    visualizza(l);
    l = listaPicchiNoLast(l);
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

Ptr_nodo listaPicchi(Ptr_nodo l){
    Ptr_nodo ris;
    ris = NULL;

    while(l->next){
        if(l->val > l->next->val)
            ris = inserisciCoda(ris, l->val);

        l = l->next;
    }
    ris = inserisciCoda(ris, l->val);

    return ris;
}

Ptr_nodo listaPicchiNoLast(Ptr_nodo l){
    Ptr_nodo ris;
    ris = NULL;

    while(l->next){
        if(l->val > l->next->val)
            ris = inserisciCoda(ris, l->val);

        l = l->next;
    }

    return ris;
}