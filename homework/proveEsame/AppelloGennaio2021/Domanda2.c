/*Si scriva un sottoprogramma che riceve come parametro il nome di un file e qualsiasi altro parametro
ritenuto necessario.
Il file di testo contiene (0 o più) righe. Le righe dispari contengono 2 valori reali separati da spazi che
indicano la base e l’altezza di un triangolo, le righe pari contengono 3 valori separati da spazi che
rappresentano base minore, base maggiore e altezza di un trapezio.
Si supponga che la numerazione delle righe inizi con 1.
Il sottoprogramma restituisce
- qual è la riga del file corrispondente alla figura geometrica di area maggiore
- il valore di quest’area. Se si trovano figure di aree uguali, si consideri la prima di queste.
in caso di errore il sottoprogramma restituisce i valori -1 e -1
Scrivere un programma che acquisisce da riga di comando il nome del file, chiama il sottoprogramma
aree e visualizza il risultato ottenuto.*/

#include<stdio.h>

#define DIM 30

void aree(char s[], int *riga, float*max);

int main(){
    char nomeFile[DIM];
    int riga;
    float max;

    printf("Dimmi il nome del file: ");
    scanf("%s", nomeFile);
    aree(nomeFile, &riga, &max);

    printf("Alla riga %d c'e' un'area pari a: %f \n", riga, max);

    return 0;
}

void aree(char s[], int *riga, float *max){
    FILE *fp;
    int i, a, b, c;
    float area;
    fp = fopen(s, "r");
    *riga = 0;
    *max = 0;

    if(fp){
        i=0;
        while(fscanf(fp, "%d %d", &a, &b) > 0){
            i++;
            area = (float) (a*b)/2;
            if(area > *max){
                *riga = i;
                *max = area;
            }

            if(!feof(fp)){
                fscanf(fp, "%d %d %d", &a, &b, &c);
                i++;
                area = (float) (a+b)*c / 2;
                if(area > *max){
                    *riga = i;
                    *max = area;
                }
            }
        }
        fclose(fp);
    }else{
        printf("Errore apertura file...\n");
        *riga = -1;
        *max = -1;

    }
}