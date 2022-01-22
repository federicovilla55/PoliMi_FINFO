/*Scrivere un sottoprogramma che riceve in ingresso un array di valori interi seq, un intero soglia e
qualsiasi altro parametro ritenuto strettamente necessario. Il sottoprogramma restituisce una lista che
contiene gli indici dei valori di seq tali per cui il loro valore è maggiore del quadrato del valore soglia.
Definire un tipo di dato opportuno per gli elementi della lista.
Gestire i casi limite in modo opportuno.
Ad esempio con
seq=[2 4 8 16] e soglia=2
il sottoprogramma restituirà la lista
2->3-|*/

#include<stdio.h>
#include<stdlib.h>

typedef struct N{
    int val;
    struct N* next;
}nodo_t;
typedef nodo_t* Ptr_nodo;

Ptr_nodo sopraSoglia(int seq[], int soglia, int dim);
Ptr_nodo inserisciCoda(Ptr_nodo l, int n);
void visualizza(Ptr_nodo l);

int main(){
    Ptr_nodo ris;
    int v[4] = {2, 4, 8, 16};
    
    ris = sopraSoglia(v, 2, 4);
    visualizza(ris);

    return 0;
}

Ptr_nodo sopraSoglia(int seq[], int soglia, int dim){
    int i;
    Ptr_nodo ris;
    ris = NULL;
    for(i=0; i<dim; i++){
        if((soglia * soglia) < seq[i])
            ris = inserisciCoda(ris, i);
    }
    return ris;
}

Ptr_nodo inserisciCoda(Ptr_nodo l, int n){
    Ptr_nodo tail, tmp;
    tail = NULL;
    tail = malloc(sizeof(nodo_t));

    if(tail){
        tail->val = n;
        tail->next = NULL;

        if(l == NULL)
            l = tail;
        else{
            for(tmp = l; tmp->next; tmp = tmp->next);
            tmp->next=tail;
        }
    }else{
        printf("Errore allocazione...\n");
    }
    return l;
}   

void visualizza(Ptr_nodo l){
    while(l){
        printf(" -> %d ", l->val);
        l = l->next;
    }
    printf("\n");
}