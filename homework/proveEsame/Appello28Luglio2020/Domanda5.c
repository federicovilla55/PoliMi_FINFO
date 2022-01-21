/*Domanda 5- (.../6 punti)
Scrivere un sottoprogramma che riceve come parametri le teste di due liste dinamiche concatenate di
interi dette valori ed indici. Il sottoprogramma costruisce e restituisce una nuova lista ris (senza
modificare le due date) riordinando gli elementi contenuti in valori come segue:
* ris avrà un numero di elementi pari a quello di indici
* l’elemento i-esimo di ris è ottenuto utilizzando il valore dell'elemento i-esimo nella lista indici come
"indice" all'interno della lista valori per leggerne il valore (l'indicizzazione di valori parte da 0)
* nel caso in cui un numero contenuto in indici sia maggiore o uguale alla lunghezza della lista valori,
in ris va inserito il valore 0
Esempio 1:
date le liste in ingresso:
valori -> 4 -> 5 -> 7 -> 2
indici -> 1 -> 0 -> 8 -> 3
Il sottoprogramma restituirà:
ris -> 5 -> 4 -> 0 -> 2
Infatti in base al contenuto di indici, verrà preso prima l'elemento in posizione 1 di valori (cioè 5), poi
l'elemento in posizione 0 di valori (cioè 4), poi l'elemento in posizione 8 (che non esiste quindi verrà
inserito il valore 0), ed infine l'elemento in posizione 3 (cioè 2).
Esempio 2:
date le liste in ingresso:
valori -> 4 -> 5 -> 7 -> 2
indici -> 3 -> 2 -> 1 -> 0
Il sottoprogramma restituirà:
ris -> 2 -> 7 -> 5 -> 4
Infatti in base al contenuto di indici, verrà preso prima l'elemento in posizione 3 di valori (cioè 2), poi
l'elemento in posizione 2 di valori (cioè 7), poi l'elemento in posizione 1 di valori (cioè 5) ed infine
l'elemento in posizione 0 (cioè 4).*/

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
int contaElementi(Ptr_nodo l);
Ptr_nodo newList(Ptr_nodo valori, Ptr_nodo indici);

int main(){
    Ptr_nodo l1, l2;
    int i;
    int v1[4] = {4, 5, 7, 2};
    int v2[4] = {1, 0, 8, 3};
    l1 = NULL;
    l2 = NULL;
    for(i=0; i<4; i++){
        l1 = inserisciCoda(l1, v1[i]);
        l2 = inserisciCoda(l2, v2[i]);
    }

    l1 = newList(l1, l2);

    visualizza(l1);

    return 0;
}

int contaElementi(Ptr_nodo l){
    int ris;
    ris=0;
    while(l){
        l=l->next;
        ris++;
    }

    return ris;
}
void visualizza(Ptr_nodo l){
    while(l){
        printf(" -> %d ", l->val);
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
Ptr_nodo newList(Ptr_nodo valori, Ptr_nodo indici){
    Ptr_nodo ris, tmp1, tmp2;
    int i, len, found;
    ris = NULL;
    len = contaElementi(indici);

    for(i=0; i<len; i++){
        tmp1 = indici; 
        tmp2 = valori;
        found = 0;
        while(tmp1 && !found){
            if(tmp1->val == i){
                found = 1;
            }else{
                tmp1 = tmp1->next;
                tmp2 = tmp2->next;
            }
        }
        if(found)
            ris = inserisciCoda(ris, tmp2->val);
        else
            ris = inserisciCoda(ris, 0);
    }

    return ris;
}