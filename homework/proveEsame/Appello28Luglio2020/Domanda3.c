/*Scrivere un sottoprogramma che riceve in ingresso un array bidimensionale di interi mat, un intero val
e qualsiasi parametro ritenuto strettamente necessario e trasmette al chiamate gli indici di riga e colonna
che identificano la posizione del primo elemento (scandendo l’array per righe) che, sommato a tutti i
suoi precedenti, dia come risultato un valore > val. Nel caso in cui tal elemento non esista, si
trasmettono i valori -1, -1. Esiste una direttiva #define NCOL 10.*/
#include<stdio.h>

#define NCOL 10

void sommaPrec(int mat[][NCOL], int val, int*col, int*lin, int nlin);

void sommaPrec(int mat[][NCOL], int val, int*col, int*lin, int nlin){
    int i, j, tmp;

    *col = -1;
    *lin = -1;
    tmp = 0;

    for(i=0; i<nlin && *lin==-1; i++){
        for(j=0, j<NCOL && *col==-1; j++){
            tmp += mat[i][j];
            if(tmp > val){
                *col = j;
                *lin = i;
            }
        }
    }
}