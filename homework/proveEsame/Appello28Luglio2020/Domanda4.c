/*Domanda 4 (.../7 punti)
Scrivere un sottoprogramma che riceve come parametro il nome di un file di testo (che può contenere
qualsiasi tipo di carattere ASCII), ed un numero intero n. Il sottoprogramma apre il file, legge i primi n
caratteri distinti (il numero di caratteri distinti presente nel file potrebbe essere minore di n), li stampa a
video e restituisce il numero di caratteri trovati.
NOTA: utilizzare la struttura dati più adatta e motivare la vostra scelta.
Ingresso: testo.txt 13
Contenuto del file: Il 15 Agosto vado al mare, il 16 torno a casa.
Stampa: Il 15Agostvad
Restituisce: 13
Ingresso: testo.txt 20
Contenuto file: domani mattina mi sveglio presto
Stampa: domani tsveglpr
Restituisce:15*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isText(char s[], char ch, int dim);
int chrDiff(char s[], int dim);

int main(){
    chrDiff("testo.txt", 13);

    return 0;
}

int isText(char s[], char ch, int dim){
    int i, ris;
    ris = 0;
    for(i=0; i<dim && !ris; i++){
        if(s[i] == ch)
            ris = 1;
    }

    return ris;
}

int chrDiff(char s[], int dim){
    int i, num;
    char tmp;
    char *s2;
    FILE *fp;
    s2 = (char *) malloc(dim + 1);
    strcpy(s2, "");
    fp = fopen(s, "r");

    if(fp){
        num = 0;
        for(i=0; i<dim; i++){
            if(!feof(fp)){
                fscanf(fp, "%c", &tmp);
                if(!isText(s2, tmp, i)){
                    s2[num]=tmp;
                    num++;
                    s2[num]='\0';
                    printf("%c", tmp);
                }else{
                    i--;
                }
            }
        }

        fclose(fp);
    }else{
        printf("Errore apertura file...\n");
    }
    return num;
}