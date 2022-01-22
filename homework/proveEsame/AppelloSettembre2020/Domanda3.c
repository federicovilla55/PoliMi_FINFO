/*Scrivere un sottoprogramma che riceve in ingresso un array a di numeri interi positivi e qualsiasi altro
parametro ritenuto strettamente necessario. Il sottoprogramma elimina dall'array tutti i numeri non
primi compattando l’array, stampa i video l’array così ottenuto e restituisce al chiamate il numero di
elementi alla fine presenti nell'array.
(Ricordo che eliminare un elemento i-esimo in un array significa spostare gli elementi dall’ i+1-esimo
fino all’elemento N-1-esimo per coprire il vuoto lasciato dall’elemento eliminato)*/

#include<stdio.h>

int deleteNotPrime(int a[], int dim);
int isPrime(int n);

int main(){
    int a[8]={1, 2, 3, 4, 5, 6, 8, 12}, i, dim;

    dim = deleteNotPrime(a, 8);

    printf("Risultato finale: ");
    for(i=0; i<dim; i++){
        printf("%d ", a[i]);
    }

    return 0;
}

int deleteNotPrime(int a[], int dim){
    int i, j, dimF, del;
    dimF = 0;
    del = 0;
    for(i=0; i<dim; i++){
        if(!isPrime(a[i])){
            del++;
            for(j=i; j< (dim-1-del); j++)
                a[j] = a[j+1];
        }else{
            dimF++;
        }
    }

    return dimF+1;
}

int isPrime(int n){
    int i, ris;
    ris = 1;
    for(i=2; i<n/2+1 && ris; i++){
        if(n % i == 0)
            ris = 0;
    }

    return ris;
}