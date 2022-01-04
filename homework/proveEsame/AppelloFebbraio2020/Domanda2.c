#include<stdio.h>
#define NR 8
#define NC 4

int elementiDominanti(int mat[][NR]);
int isDominante(int mat[][NR], int lin, int col);

int main(){
    int info[NC][NR];
    int i, j;
    printf("Riempi una matrice %dx%d: \n", NC, NR);
    for(i=0; i<NC; i++){
        for(j=0; j<NR; j++){
            scanf("%d", &info[i][j]);
        }
    }

    printf("Numero di elementi dominanti: %d \n", elementiDominanti(info));
}

int isDominante(int mat[][NR], int lin, int col){
    int i, j, ris;
    ris = 1;

    for(i = lin+1; i<NC && ris; i++){
        for(j=col+1; j<NR && ris; j++){
            if(!(mat[lin][col] > mat[i][j]))
                ris = 0;
        }
    }
    return ris;
}

int elementiDominanti(int mat[][NR]){
    int ris, i, j;
    ris = 0;
    for(i=0; i<NC-1; i++){
        for(j=0; j<NR-1; j++){
            if(isDominante(mat, i, j))
                ris++;
        }
    }

    return ris;
}