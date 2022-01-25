/*Scrivere un sottoprogramma che riceve in ingresso la testa di una lista dinamica per la gestione di numeri 
interi. Il sottoprogramma costruisce e restituisce una nuova lista di interi, in cui ciascun elemento i-esimo 
è il prodotto tra l’i-esimo elemento a partire dalla testa e l’i-esimo elemento a partire dalla coda della lista 
di partenza. Se la lista ha un numero dispari di elementi l’elemento centrale viene moltiplicato per se 
stesso (si veda l’esempio 1)
Esempio 1:
L:1-> 5 ->4 ->7 ->6 ->3 ->6-|
Il sottoprogramma restituirà la lista:
L2: 6->15->24->49-|
Esempio 2: 
L: 3->5->8->9-|
L2: 27->40-|
(Varianti: somma, sottrazione, media, quoziente, resto)
-------
Nello svolgimento dell’esercizio, si possono considerare come già disponibili sia la definizione del tipo 
di dato per la gestione di liste dinamiche di interi che i relativi sottoprogrammi */

#include<stdio.h>
#include<stdlib.h>

typedef struct N{
    int dato;
    struct N * next;
}nodo_t;
typedef nodo_t * Ptr_nodo;

void visualizza(Ptr_nodo l);
Ptr_nodo createNewList(Ptr_nodo l);
Ptr_nodo inserisciCoda(Ptr_nodo l, int n);

int main(){
    int i, v[7]={1, 5, 4, 7, 6, 3, 6};
    Ptr_nodo l;
    l = NULL;
    for(i=0; i<7; i++)
        l = inserisciCoda(l, v[i]);

    visualizza(l);
    l = createNewList(l);
    visualizza(l);

    return 0;
}

Ptr_nodo createNewList(Ptr_nodo l){
    Ptr_nodo ris, tmp;
    int val;
    ris = NULL;

    while(l->next){
        val = l->dato;
        for(tmp = l; tmp->next->next; tmp=tmp->next);
        val *= tmp->next->dato;
        free(tmp->next);
        tmp->next = NULL;
        tmp = l;
        l = l->next;
        free(tmp);
        ris = inserisciCoda(ris, val);
    }

    ris = inserisciCoda(ris, (l->dato*l->dato));
    return ris;
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
        if(l == NULL){
            l = tail;
        }else{
            for(tmp = l; tmp->next; tmp = tmp->next);
            tmp->next = tail;
        }
    }

    return l;
}