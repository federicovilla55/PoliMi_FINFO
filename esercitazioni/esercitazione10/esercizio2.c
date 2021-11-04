/*Matrice diagonale superiore
Scrivere un programma che:
- generi una matrice NxN (con N = 3) inserendo in ogni cella dei numeri progressivi ad incremento casuale
di un valore compreso tra 1 e MAX_INCR (funzione genera_matrice)
- stampi la matrice
- trasformi la matrice in una matrice triangolare superiore avente come elementi le somme degli elementi
simmetrici rispetto alla diagonale principale.*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 3
#define MAX_INCR 4

void genera_matrice(int m[][N]);
void stampa_matrice(int m[][N]);
void trasforma_matrice(int m[][N]);

int main(){
    int m[N][N];

    genera_matrice(m);
    stampa_matrice(m);

    printf("\n");

    trasforma_matrice(m);
    stampa_matrice(m);

    return 0;
}

void genera_matrice(int m[][N]){
    int i, j, prec;
    srand(time(NULL));
    prec = 0;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            m[i][j] = prec + (rand() % MAX_INCR + 1);
            prec = m[i][j];
        }
    }
}

void stampa_matrice(int m[][N]){
    int i, j;
    printf("Ecco la matrice: \n");
    for (i=0; i<N; i++){
        for(j=0; j<N; j++){
            printf("\t%d", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void trasforma_matrice(int m[][N]){
    int i, j;
    for(i=0; i<N; i++){
        for(j=i+1; j<N; j++){
            m[i][j]+=m[j][i];
            m[j][i]=0;
        }
    }
}