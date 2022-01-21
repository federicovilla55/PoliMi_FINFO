/*Scrivere un programma in linguaggio C, completo di opportune dichiarazioni, che legge da un file
input una sequenza di valori interi di lunghezza indefinita e, per ogni valore letto, memorizza in un file
output la coppia data dal valore stesso e dal numero di ripetizioni.
Esempio: supponendo che input contenga i seguenti valori
10 6 2 6 2 10 10
il programma dovrà scrivere nel file output:
10 3
6 2
2 2 */

#include<stdio.h>
#include<stdlib.h>

typedef struct N{
    int val;
    int conta;
    struct N *next;
}nodo_t;

typedef nodo_t * Ptr_nodo;

int isLista(Ptr_nodo l, int n);
Ptr_nodo inserisciCoda(Ptr_nodo l, int n, int conta);

int main(){
    Ptr_nodo l, temp, tail;
    int n;
    FILE *fp;
    FILE *out;
    l = NULL;
    fp = fopen("numeri.txt", "r");
    out = fopen("Risultati.txt", "w");

    if(fp && out){
        while(fscanf(fp, "%d", &n) > 0){
            if(isLista(l, n)){
                for(temp = l; temp->val!=n; temp=temp->next);
                temp->conta++;
            }else{
                l = inserisciCoda(l, n, 1);
            }
        }
        fclose(fp);

        while(l){
            printf("%d %d \n", l->val, l->conta);
            fprintf(out, "%d %d \n", l->val, l->conta);
            l = l->next;
        }
    }
    fclose(out);
}

Ptr_nodo inserisciCoda(Ptr_nodo l, int n, int conta){
    Ptr_nodo tail, tmp;
    tail = NULL;
    tail = malloc(sizeof(nodo_t));

    if(tail){
        tail->val = n;
        tail->conta = conta;
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

int isLista(Ptr_nodo l, int n){
    int found;
    found = 0;
    printf("Inizio Lista...\n");
    while(l && !found){
        if(l->val == n)
            found = 1;
        l = l->next;
    }
    printf("Lista...\n");
    return found;
}