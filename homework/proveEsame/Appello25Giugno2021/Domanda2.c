/*Dato un array bidimensionale di valori interi piena solo di 0 e 1 (è senz’altro così), definisco segmento orizzontale una successione di 1 consecutivi
nella stessa riga. La lunghezza del segmento è il numero di 1 contenuti, l’inizio del segmento sono le coordinate i e j dell’elemento con j minimo
della sequenza di 1. Vogliamo calcolare la lunghezza e l’inizio del segmento di lunghezza massima e se ce ne fosse più di uno di pari lunghezza
massima, si prende il primo.
Scrivere un sottoprogramma che ricevuto in ingresso un array bidimensionale di interi, e qualsiasi altro parametro ritenuto strettamente necessario,
calcola e trasmette al chiamante la posizione di inizio del segmento e la sua lunghezza.
Il numero di colonne dell’array bidimensionale dichiarato dal chiamante è specificato mediante una direttiva define del simbolo NC.
Per esempio, dato l’array di seguito riportato, il sottoprogramma individuerebbe il segmento evidenziato, trasmettendo al chiamante i valori 1, 3 e
5, corrispondenti alle coordinate 1,3 primo elemento del segmento, e 5 la sua lunghezza.
1 0 1 1 1 0 1 1
0 0 0 1 1 1 1 1
1 1 1 0 0 0 1 1
1 1 1 1 1 0 0 0
1 1 1 0 0 1 1 1
1 0 0 0 0 1 1 1
1 0 1 1 0 1 1 0*/

#include<stdio.h>

#define NC 8
#define NL 7

void calcolaSegmento(int mat[][NC], int*len, int*inizioX, int*inizioY);

int main(){
    int i, j, mat[NL][NC];
    int lunghezza, x, y;

    printf("Riempi una matrice %dx%d: \n", NL, NC);
    for(i=0; i<NL; i++){
        for(j=0; j<NC; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    printf("FINE");
    calcolaSegmento(mat, &lunghezza, &x, &y);

    printf("Lunghezza segmento: %d, X: %d Y: %d\n", lunghezza, x, y);

    return 0;
}

void calcolaSegmento(int mat[][NC], int*len, int*inizioX, int*inizioY){
    int i, j, tmp, start;

    *len = 0;

    for(i=0; i<NL; i++){
        tmp = 0;
        start = 0;
        for(j=0; j<NC; j++){
            if(mat[i][j] == 1){
                if(tmp == 0)
                    start = j;
                tmp++;
            }else{
                tmp = 0;
            }
            if(tmp > *len){
                *inizioX = start;
                *inizioY = i;
                *len = tmp;
            }
        }
    }

}