#include<stdio.h>
#include<stdlib.h>

typedef struct N{
    int val;
    struct N *next;
}nodo_t;
typedef nodo_t * Ptr_nodo;

void visualizza(Ptr_nodo l);
Ptr_nodo inserisciCoda(Ptr_nodo l, int n);
int dimensioneLista(Ptr_nodo l);
Ptr_nodo newList(Ptr_nodo l);
Ptr_nodo updateList(Ptr_nodo l, int*molt);

int main(){
    Ptr_nodo l;
    int i, v[7] = {1, 5, 4, 7, 6, 3, 6};
    l = NULL;

    for(i=0; i<7; i++)
        l = inserisciCoda(l, v[i]);

    l = newList(l);

    visualizza(l);

    return 0;
}

Ptr_nodo newList(Ptr_nodo l){
    Ptr_nodo ris;
    int tmp;
    ris = NULL;
    while(l){
        l = updateList(l, &tmp);
        ris = inserisciCoda(ris, tmp);
    }

    return ris;
}

Ptr_nodo updateList(Ptr_nodo l, int*molt){
    Ptr_nodo tmp;
    
    *molt = l->val;
    if(l->next){
        l = l->next;
        for(tmp = l; tmp->next->next; tmp = tmp->next);
        *molt*=tmp->next->val;
        tmp->next = NULL;
    }else{
        *molt *= l->val;
        l = NULL;
    }
    return l;
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