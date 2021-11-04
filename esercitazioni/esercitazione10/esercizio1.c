/*Matrice 3x3
Scrivere un programma che:
• richieda all'utente di riempire una matrice 3 x 3 di interi tramite la funzione riempi_matrice
• la stampi tramite la funzione stampa_matrice
• sostituisca nella matrice ogni numero dispari con il suo cubo tramite la funzione dispari_cubi
• calcoli e restituisca la media di tutti gli elementi della matrice tramite la funzione calcola_media*/

#include <stdio.h>
#define N 3

void riempi_matrice(int m[][N]);
void stampa_matrice(int m[][N]);
void dispari_cubi(int m[][N]);
float calcola_media(int m[][N]);

int main(){
    int m[N][N];
    float media;

    riempi_matrice(m);
    stampa_matrice(m);

    dispari_cubi(m);
    stampa_matrice(m);

    media = calcola_media(m);
    printf("La media e': %f\n", media);
    
    return 0;
}

void riempi_matrice(int m[][N]){
    int i, j;
    printf("Dimmi i valori da inserire nella matrice %dX%d:\n", N, N);
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            printf("Elemento (%d, %d): ", i, j);
            scanf("%d", &m[i][j]);
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

void dispari_cubi(int m[][N]){
    int i, j;

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if(m[i][j]%2==1){
                m[i][j]*= m[i][j]*m[i][j];
            }
        }
    }
}

float calcola_media(int m[][N]){
    int i, j;
    float somma;
    somma = 0.0F; /*Lo sto inizializzando a 0 specificando che e' un float*/

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            somma+=m[i][j];
        }
    }

    return (somma/N*N);

}