/*Scrivere un programma C che apre un file di testo “testo.txt” contenente parole ciascuna di al massimo
15 caratteri. Il programma chiede all'utente una sequenza controlla di al massimo 26 caratteri distinti tra
loro. Il programma stampa a video, per ogni carattere in controlla, il numero di volte che è presente nel
file, utilizzando nella stampa righe distinte.
Ad esempio, se il file “testo.txt” contiene il testo:
Il mio viaggio a Roma di Dicembre e' stato molto bello
e la sequenze controlla è: azcm
il programma stampa
a:4
z:0
c:1
m:4*/

#include<stdio.h>
#include<string.h>

#define DIM 16
#define DIM2 27

int main(){
    FILE *fp;
    char s[DIM2], s2[DIM];
    int i, mark[128]; 
    fp = fopen("testo.txt", "r");

    memset(mark, 0, 128*sizeof(int));

    while(fscanf(fp, "%s", s) > 0){
        for(i=0; i<strlen(s); i++){
            mark[s[i]]++;
        }
    }

    printf("Parola: ");
    scanf("%s", s2);

    for(i=0; i<strlen(s2); i++){
        printf("%c : %d \n", s2[i], mark[s2[i]]);
    }
    
    return 0;
}