/*Scrivere un programma che chiede all’utente il nome di tre file di testo (ognuno di al più 80 caratteri, comprensivi di percorso ed estensione): i primi
due file sono i file sorgente, il terzo quello destinazione ed un intero. Il programma crea il terzo file concatenando i contenuti dei due file in ingresso:
se l’intero fornito vale 0, il programma concatena il secondo file al primo, se l’intero fornito vale 1, il programma concatena il primo al secondo. Nel
caso in cui l’intero valga un valore diverso da 0 e da 1, il programma non fa nulla.*/
#include<stdio.h>

int main(){
    char nome1[81], nome2[81], nome3[81];
    FILE *f1, *f2, *f3;
    char tmp;
    int n;
    printf("Dimmi il nome di un file: ");
    scanf("%s", nome1);
    printf("Dimmi il nome di un file: ");
    scanf("%s", nome2);
    printf("Dimmi il nome di un file: ");
    scanf("%s", nome3);

    f1 = fopen(nome1, "r");
    f2 = fopen(nome2, "r");
    f3 = fopen(nome3, "w");

    if(f1 && f2 && f3){
        printf("Dimmi un numeri intero: ");
        scanf("%d", &n);
        if(n == 0){
            while(fscanf(f1, "%c", &tmp) > 0)
                fprintf(f3, "%c", tmp);
            while(fscanf(f2, "%c", &tmp) > 0)
                fprintf(f3, "%c", tmp);
        }
        if(n == 1){
            while(fscanf(f2, "%c", &tmp) > 0)
                fprintf(f3, "%c", tmp);
            while(fscanf(f1, "%c", &tmp) > 0)
                fprintf(f3, "%c", tmp);
        }
        fclose(f1);
        fclose(f2);
        fclose(f3);
    }else{
        printf("Errore apertura file...\n");
    }

}