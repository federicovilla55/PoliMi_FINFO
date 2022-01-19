/*Scrivere un programma C completo di opportune dichiarazioni, che apre un file di testo “testo.txt”
contenente parole ciascuna di al massimo 15 caratteri. Il programma trova tutte le parole più lunghe di 4
caratteri e ripetute due volte di seguito nel testo e le stampa a video.
Ad esempio, se il file “testo.txt” contiene il testo:
bisogna studiare passo passo e adagio adagio per ottenere un voto
alto alto
Il programma visualizzerà il testo:
passo adagio*/

#include<stdio.h>
#include<string.h>

#define LEN 15

int main(){
    FILE *fp;
    int i;
    char s[LEN+1], s2[LEN+1];
    fp = fopen("testo.txt", "r");
    if(fp){
        if(fscanf(fp, "%s", s) > 0);

        while(!feof(fp)){
            fscanf(fp, "%s", s2);
            if(strcmp(s, s2)==0 && strlen(s)>4)
                printf("%s \t", s);
            
            strcpy(s, s2);

        }
        fclose(fp);
    }else{
        printf("Errore...\n");
    }

    return 0;
}