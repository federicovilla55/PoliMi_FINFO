/*Scrivere un programma che dato una matrice 5x5
 * visualizza il carattere che compare più spesso e quante
 * volte compare, poi mostra la matrice con * al posto
 * di quel carattere*/

#include<stdio.h>
#define N 5

int main(){
    char matr[N][N], maxc;
    int i, j, k, h, freq, maxf; 

    for(i=0; i<N; i++){
        for(j=0; j<N; j++)
        {
            scanf("%c", &matr[i][j]);
        }
    }

    maxc = matr[0][0];
    maxf = 0;

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            freq = 0;
            for(h=0; h<N; h++){
                for(k=0; k<N; k++){
                    if(matr[i][j]==matr[h][k]){
                        ++freq;
                    }
                }
            }
            if(freq>maxf){
                maxf=freq; 
                maxc=matr[i][j];
            }
        }
    }

    printf("Il carattere più frequente e': %c\n", maxc);

    for(i=0; i<N; i++){
        for(j=0; j<N; j++)
        {
            if(matr[i][j]==maxc){
                matr[i][j] = "*";
            }
            printf("%c ", matr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
