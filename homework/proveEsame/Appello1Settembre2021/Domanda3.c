/*Dato un array bidimensionale di valori interi positivi, ogni punto rappresenta la quota di un vulcano in una area. Quando un vulcano erutta, il cratere
si apre ed esce la lava per cui la sua quota cresce di 2, e la lava che fuoriesce fa crescere di 1 anche la quota delle otto posizioni attorno, se hanno
una quota inferiore a quella del vulcano prima dell’eruzione (la lava scende ...). I due array di seguito riportano la situazione prima e dopo l’eruzione
dell’elemento in grassetto.
3 0 6 1 5 1 5 6 8 1 3 0 6 2 6 1 5 6 8 1
0 0 5 6 0 5 4 0 5 6 0 0 6 8 1 5 4 0 5 6
1 0 8 1 2 6 4 6 5 6 1 0 8 2 3 6 4 6 5 6
5 1 8 6 0 0 0 0 0 0 5 1 8 6 0 0 0 0 0 0
3 1 3 0 4 1 2 1 5 6 3 1 3 0 4 1 2 1 5 6
5 1 5 1 3 1 1 0 7 1 5 1 5 1 3 1 1 0 7 1
5 1 5 1 0 0 5 6 2 3 5 1 5 1 0 0 5 6 2 3
3 1 8 1 0 0 0 0 0 0 3 1 8 1 0 0 0 0 0 0
prima dopo
Scrivere un sottoprogramma che ricevuto in ingresso un array bidimensionale di interi, le coordinate del vulcano che erutta, e qualsiasi altro parametro ritenuto strettamente necessario, modifica l’array iniziale aggiornandolo con la configurazione delle quote corrispondenti a dopo l’eruzione.
Il numero di colonne dell’array bidimensionale dichiarato dal chiamante è specificato mediante una direttiva define del simbolo NC.*/

#include<stdio.h>

#define NC 10
#define NL 8

void eruzione(int mat[][NC], int col, int lin, int dim);

int main(){
    int i, j;
    int mat[NL][NC];
    printf("Inserisci i valori di una matrice %dx%d: \n", NL, NC);
    for(i=0; i<NL; i++){
        for(j=0; j<NC; j++){
            scanf("%d", &mat[i][j]);
        }
    }

    eruzione(mat, 3, 1, NL);

    printf("Risultato: \n");
    for(i=0; i<NL; i++){
        for(j=0; j<NC; j++){
            printf(" %d ", mat[i][j]);
        }
        printf("\n");
    }
}

void eruzione(int mat[][NC], int col, int lin, int dim){
    int i, j;

    i = lin-1;
    if(i<0)
        i = lin;
    while(i<=lin+1){
        j = col-1;
        if(j<0)
            j = col;
        while(j<=col+1){
            if(mat[i][j] < mat[lin][col])
                mat[i][j]++;
            j++;
        }
        i++;
    }
    mat[lin][col] += 2;
}