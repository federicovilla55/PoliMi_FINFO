/*Dato un array a[] di N elementi interi e un intero k>=1, diciamo che il valore a[i] è un k-massimo se è
strettamente maggiore dei k valori precedenti e dei k valori successivi dell'array.
Scrivere il sottoprogramma kmassimo che riceve in input un array a[] di interi, un intero k e qualsiasi
altro parametro ritenuto necessario e restituisca il più piccolo indice i tale che a[i] sia un k-massimo,
oppure -1 se non esiste alcun k-massimo.
Ad esempio, se a[] = {1, 2, 3, 2, 1} e k = 2, allora la funzione deve restituire 2, in quanto il valore di
a[2] è 3 ed è il primo k-massimo (in questo caso, il 2-massimo) dell'array, essendo strettamente
maggiore dei due valori precedenti {1, 2} e dei due valori successivi {2, 1}.*/

#include<stdio.h>
#define DIM 5

int kMassimo(int a[], int k, int dim);
int main(){
    int a[DIM], k, i;
    printf("Inserisci %d numeri e il k: ", DIM);
    for(i=0; i<DIM; i++)
        scanf("%d", &a[i]);
    scanf("%d", &k);

    printf("Indice del primo %d-massimo: %d \n", k, kMassimo(a, k, DIM));
    return 0;
}

int kMassimo(int a[], int k, int dim){
    int ris, i, j, tmp;

    ris = -1;

    for(i=k; i<(dim-k) && ris == -1; i++){
        tmp = 1;
        for(j=k; j>0 && tmp; j--){
            tmp = tmp && (a[i] > a[i+j]) && (a[i] > a[i-j]);
        }
        if(tmp)
            ris = i;
    }
    return i;
}