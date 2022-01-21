/*Si codifichi una funzione replace che riceve come parametri due stringhe str e sost ed un carattere ch
(e qualsiasi altro parametro ritenuto necessario), e alloca dinamicamente e restituisce una nuova stringa
derivata da str sostituendo tutte le occorrenze di ch con la stringa sost. La nuova stringa dovrà occupare
la minima quantità di memoria sufficiente allo scopo.
Esempi:
str : “CULLA” ch : ‘U’ sost : “ARTE” restituisce “CARTELLA”
str : “PIPE” ch : ‘P’ sost : “CAR” restituisce “CARICARE”*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *replace(char str[], char sost[], char ch);

int main(){
    
    printf("Replace: %s \n", replace("CULLA", "ARTE", 'U'));

    return 0;
}

char *replace(char str[], char sost[], char ch){
    int i, j, tmp;
    char *ris;
    tmp = 0;

    for(i=0; str[i]!='\0'; i++){
        if(str[i] == ch)
            tmp++;
    }

    ris = (char *) malloc(strlen(str) + (strlen(sost)*tmp) + 1);

    j=0;
    for(i=0; str[i]!='\0'; i++){
        if(str[i] == ch){
            for(tmp = 0; sost[tmp]!='\0'; tmp++){
                ris[i+j] = sost[tmp];
                printf("sost: %c \t ris: %c \n", sost[tmp], ris[i+j]);
                j++;
            }
        }else{
            ris[i+j] = str[i];
            printf("ris: %c \n", ris[i+j]);
        }
    }
    ris[i+j]='\0';

    return ris;
}