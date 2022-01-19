/*Scrivere un sottoprogramma che ricevuta in ingresso una matrice di valori interi di dimensione NxN calcola e
restituisce l’indice della colonna in cui la massima differenza (in valore assoluto) ottenuta tra due suoi elementi,
sia massima e l’indice in cui tale differenza sia minima. Nel caso ci sia più di una colonna con uguale differenza
massima, restituire l'indice della prima colonna trovata. Analogamente per la minima differenza.
Ad esempio, se il sottoprogramma riceve la matrice:
2 5 10 15 18
11 7 7 20 15
5 5 7 11 22
6 1 3 16 19
7 1 2 10 18
Il sottoprogramma restituirà l’indice 3 (tale colonna ha come massima differenza 10 tra 20 e 10) e l’indice 1 (diff
minima 0 tra 1 e 1).*/

#include<stdio.h>
#define N 5

void differenzaMatrice(int mat[][N], int *min, int *max, int dim);

int main(){
    int mat[N][N], i, j;
    int max, min;

    printf("Riempi una matrice %dx%d: \n", N, N);
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            scanf("%d", &mat[i][j]);
        }
    }

    differenzaMatrice(mat, &min, &max, N);

    printf("Minimo: %d \t Massimo: %d \n", min, max);

    return 0;
}

void differenzaMatrice(int mat[][N], int *min, int *max, int dim){
    int i, j, tmp, massimo, minimo;
    *max = 0;
    *min = 0;
    massimo = mat[0][0] - mat[0][1];
    if(massimo < 0)
        massimo = -massimo;
    minimo = massimo;

    for(i=0; i<dim; i++){
        for(j=0; j<dim-1; j++){
            tmp = mat[i][j] - mat[i][j-1];

            if(tmp < 0)
                tmp = -tmp;

            if(tmp > massimo){
                *max = i;
                massimo = tmp;
            }
            if(tmp < minimo){
                *min = i;
                minimo = tmp;
            }
        }
    }

}