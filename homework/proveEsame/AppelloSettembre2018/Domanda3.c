/*Realizzare la funzione maxmin7 che accetta come parametro un array v[] di lunghezza n>=7 e qualsiasi
altro parametro ritenuto necessario. La funzione deve restituire sia il massimo che il minimo valore
della somma di 7 elementi contigui in v[]
Ad esempio, se v = {1, 2, -4, 1, 3, -5, 2, 10, -1}, esistono tre possibili somme di 7 elementi contigui in
v[], ossia
v[0] + v[1] + v[2] + v[3] + v[4] + v[5] + v[6] = 0
v[1] + v[2] + v[3] + v[4] + v[5] + v[6] + v[7] = 9
v[2] + v[3] + v[4] + v[5] + v[6] + v[7] + v[8] = 6

Quindi in questo caso la funzione deve restituire 9 e 0.
Se lo si ritiene utile, e' possibile definire ulteriori funzioni.*/
#include<stdio.h>

#define N 9

void maxMin(int v[], int n, int*max, int*min);
int main(){
    int arr[N], i, max, min;

    printf("Riempi un array di %d elementi: ", N);
    for(i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }
    maxMin(arr, N, &max, &min);
    printf("La somma massima e': %d \t La somma minima e': %d \n", max, min);

}

void maxMin(int v[], int n, int*max, int*min){
    int i, j, tmp;
    tmp = 0;
    for(i=0; i<7; i++){
        tmp += v[i];
    }
    *max = tmp;
    *min = tmp;

    for(i=1; i<(n-7); i++){
        tmp = 0;
        for(j=0; j<7; j++)
            tmp += v[i+j];
        if(tmp < *min)
            *min = tmp;
        if(tmp > *max)
            *max = tmp;
    }

}