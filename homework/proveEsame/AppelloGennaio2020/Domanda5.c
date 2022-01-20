/*Scrivere un sottoprogramma che, dato in input una lista per la gestione dei numeri interi e un intero k,
restituisce un riferimento al k-esimo elemento della lista a partire dalla fine.
Ad esempio, se k = 1 il sottoprogramma deve restituire un riferimento all'ultimo elemento; se k = 2 al
penultimo, e così via*/

#include<stdio.h>
#include<stdlib.h>

typedef struct N{
    int dato;
    struct N *next;
} nodo_t;

void stampaLista(nodo_t *ptr){
    if(ptr == NULL){
        return;
    }
    printf(" %d ", ptr->dato);
    stampaLista(ptr->next);
}
int contaLista(nodo_t *ptr){
    if(ptr == NULL)
        return 0;
    return (1+contaLista(ptr->next));
}
void insert(nodo_t *ptr, int n){
    nodo_t *ptr2;
    if(ptr->next != NULL){
        insert(ptr->next, n);
    }else{
        ptr2 = (nodo_t*) malloc(sizeof(nodo_t));
        ptr2->dato = n;
        ptr2->next = NULL;
        ptr -> next = ptr2;
    }
}
void stampaElementoK(nodo_t *ptr, int k, int pos){
    if(pos == k){
        printf("%d", ptr->dato);
        return;
    }

    return (stampaElementoK(ptr->next, k, pos+1));
}
int main(){
    nodo_t * root;
    int i, k, v[8]={1, 2, 3, 4, 5, 6, 7, 8};
    root = NULL;
    root = (nodo_t*) malloc(sizeof(nodo_t));
    
    root->dato = v[0];
    root->next = NULL;

    for(i=1; i<8; i++){
        insert(root, v[i]);
    }
    /*stampaLista(root);*/
    /*printf("Numero elementi: %d \n", contaLista(root));*/
    k = contaLista(root) - 2;
    
    stampaElementoK(root, k, 0);

    return 0;    
}

