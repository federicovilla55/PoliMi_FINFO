/*Scrivere un sottoprogramma che ricevuta in ingresso una matrice di valori interi e qualsiasi altro parametro ritenuto strettamente necessario, calcola
e restituisce l’indice della colonna in cui la massima differenza ottenuta tra due suoi elementi, sia massima. Si ipotizzi che il numero di colonne della
matrice sia definito tramite una direttiva define con il simbolo NCOL.*/

#include<stdio.h>

#define NCOL 4
#define NLIN 4

int diffMax(int mat[][NCOL], int dim){
    int i, j, tmp, max, ris;
    ris = 0;
    max = mat[0][0]-mat[0][1];
    if(max < 0)
        max = -max;
    
    for(j=0; j<NCOL; j++){
        for(i = 0; i<dim-1; i++){
            tmp = mat[i][j] - mat[i+1][j];
            if(tmp < 0)
                tmp = -tmp;
            if(tmp > max){
                ris = j;
                max = tmp;
            }
        }
    }
    return ris;
}