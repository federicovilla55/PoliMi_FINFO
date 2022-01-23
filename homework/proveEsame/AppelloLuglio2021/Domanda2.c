/*a. Scrivere un sottoprogramma che riceve in ingresso un array bidimensionale M x N di interi Mat,
e qualsiasi altro parametro ritenuto strettamente necessario, e trasmette al chiamante un array
bidimensionale di dimensioni M X N New i cui elementi sono ottenuti in questo modo: le righe di New
sono riportate in ordine inverso rispetto alle righe di Mat e ogni volta che una riga di Mat inizia con
zero, in New tutti i valori della riga vengono posti a 0.
Il sottoprogramma restituisce inoltre il numero di righe azzerate.
Nel contesto di utilizzo del sottoprogramma esistono le direttive #define M e #define N.
Ad esempio
Mat New
1 2 3 2 1 5
0 4 5 7 8 9
7 8 9 0 0 0
2 1 5 1 2 3
e il programma restituisce il valore 1.
b. Scrivere un programma completo con le opportune dichiarazioni che chiede all’utente i dati per
popolare la matrice Mat. Il programma invoca il sottoprogramma sopra definito e stampa a video il
contenuto della matrice New.*/

#include<stdio.h>
#define M 4
#define N 3

int newMat(int mat[][N], int new[][N]);

int main(){
    int i, j;
    int mat[M][N], new[M][N];

    printf("Inserisci i valori di una matrice %dx%d:\n", M, N);
    for(i=0; i<M; i++)
        for(j=0; j<N; j++)
            scanf("%d", &mat[i][j]);

    printf("Numero di righe azzerate: %d \n", newMat(mat, new));

    printf("Matrice finale:\n");
    for(i=0; i<M; i++){
        for(j=0; j<N; j++)
            printf(" %d ", new[i][j]);
        printf("\n");
    }

    return 0;
}

int newMat(int mat[][N], int new[][N]){
    int ris, i, j; 
    ris = 0;

    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            if(mat[i][0] == 0)
                new[M-i-1][j] = 0;
            else
                new[M-i-1][j] = mat[i][j];
        }
        if(mat[i][0] == 0)
            ris++;
    }

    return ris;
}