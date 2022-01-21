/*Si consideri una lista per la gestione di valori interi e si definisca un tipo opportuno list_t. Si
scrivano due sottoprogrammi kcon e knocon che, ricevuta in ingresso una lista del tipo
definito ed un intero k come specificato di seguito:
• kcon: restituisce 1 se la lista contiene almeno due occorrenze consecutive di k, 0 altrimenti, e
• knocon: restituisce 1 se la lista contiene almeno due occorrenze non consecutive di k , 0
altrimenti.
Un punto extra per ogni programma realizzato in modo ricorsivo. */

#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
    int val;
    struct nodo* next;
} lista_t;

lista_t *inserisciCoda(lista_t *l, int n);
int kcon(lista_t *ptr, int k);
int knocon(lista_t *ptr, int k);
void visualizza(lista_t *ptr);
int kconrec(lista_t *ptr, int k);
int knoconrec(lista_t *ptr, int k);

int main(){
    int v[10]={1, 3, 5, 6, 4, 4, 7, 8, 9, 1}, i;
    lista_t *root;
    root = NULL;

    for(i=0; i<10; i++)
        root = inserisciCoda(root, v[i]);

    visualizza(root);
    printf("\tkcon: %d \n", kcon(root, 4));
    printf("\tknocon: %d \n", knocon(root, 4));
    printf("\tkcon ricorsivo: %d \n", kconrec(root, 4));
    printf("\tknocon ricorsivo: %d \n", knoconrec(root, 4));    
    
    /*Risultato atteso:        
        kcon: 1 
        knocon: 0 
        kcon ricorsivo: 1 
        knocon ricorsivo: 0
    */

    return 0;
}

lista_t *inserisciCoda(lista_t *l, int n){
    lista_t *tail, *tmp;
    tail = NULL;
    tail = (lista_t *) malloc(sizeof(lista_t));

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

void visualizza(lista_t *ptr){
    while(ptr){
        printf(" -> %d ", ptr->val);
        ptr = ptr->next;
    }
    printf("\n");
}

int kcon(lista_t *ptr, int k){
    int ris;
    ris = 0;

    while(!ris && ptr->next){
        if(ptr->val == ptr->next->val && ptr->val == k)
            ris=1;
        ptr = ptr->next;
    }

    return ris;
}

int knocon(lista_t *ptr, int k){
    int ris;
    ris = 0;
    while(ris < 2 && ptr->next){
        if(ptr->val==k && ptr->val != ptr->next->val)
            ris++;
        ptr = ptr->next;
    }
    ris = ris > 1;

    return ris;
}

int kconrec(lista_t *ptr, int k){
    if(ptr->next == NULL)
        return 0;
    else
        return (ptr->val == ptr->next->val && ptr->val == k) || kconrec(ptr->next, k);
}

int knoconrec(lista_t *ptr, int k){
        int ris;
        if(ptr==NULL)
            return 0;
        ris = knocon(ptr->next, k);
        if(ptr->val == k){
            ris++;
        }

        return ris;
    }
