/*(6pti) Scrivere un sottoprogramma vicino che riceve in ingresso un array bidimensionali mat di valori
interi e qualsiasi altro parametro ritenuto strettamente necessario e trasmette al chiamante un array ris di
elementi interi. Ogni elemento di ris contiene, per ogni colonna j dell’array mat, il valore più vicino al
valore massimo della colonna j. Esiste una direttiva #define NC.
(1pto) Scrivere un main che contiene le dichiarazioni necessarie e la chiamata del sottoprogramma
vicino.
Esempio:
Se mat è: 0 3 5
1 4 7
2 1 1

Il vettore ris conterrà i valori: 1 3 5*/

#include<stdio.h>
#define NC 3
#define NL 3

void vicino(int mat[][NC], int ris[], int nlin);

int main(){
    int mat[NL][NC], ris[NC], i, j;

    printf("Inserisci i valori di una matrice %dx%d: \n", NL, NC);
    for(i=0; i<NL; i++){
        for(j=0; j<NC; j++){
            scanf("%d", &mat[i][j]);
        }
    }

    vicino(mat, ris, NL);

    printf("Ecco il risultato: ");
    for(i=0; i<NC; i++)
        printf("%d ", ris[i]);

    return 0;
}

void vicino(int mat[][NC], int ris[], int nlin){
    int i, j, max, qmax;

    for(j=0; j<NC; j++){
        if(mat[0][j] > mat[1][j]){
            max = mat[0][j];
            qmax = mat[1][j];
        }else{
            max = mat[1][j];
            qmax = mat[0][j];
        }
        for(i=2; i<nlin; i++){
            if(mat[i][j] > max){
                qmax = max;
                max = mat[i][j];
            }
            if(mat[i][j] < max && mat[i][j] > qmax)
                qmax = mat[i][j];
        }
        ris[j] = qmax;
    }
}