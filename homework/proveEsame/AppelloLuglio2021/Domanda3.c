/*Si scriva un sottoprogramma che prenda come parametro il nome di un file e restituisca, nel modo che si
ritiene più opportuno, i seguenti valori:
1. il numero totale di caratteri presenti nel file (inclusi spazi bianchi e ritorno a capo);
2. il numero di parole totali presenti nel file, dove per parola si intende qualsiasi sequenza non nulla
di caratteri separata da spazi bianchi o ritorno a capo;
3. il numero di righe totali del file;
Si assuma che nel file di testo non ci siano mai spazi bianchi prima del carattere di ritorno a capo, e che
anche l’ultima riga sia sempre terminata dal carattere di ritorno a capo. E' invece possibile la presenza di
righe vuote (che devono essere contate).
Ad esempio se nel file c'è il testo seguente
Il Corriere della sera
La Repubblica
Il Messaggero
Sono 3 quotidiani
Il sottoprogramma deve restituire i valori 72,11, 7. Ci sono infatti 72 caratteri, 11 parole e 7 righe.*/

#include<stdio.h>
#define FILENAME "testo.txt"

void analizzaFile(char nomeFile[], int *numChar, int*numWord, int*numLine);

int main(){
    int caratteri, parole, righe;
    analizzaFile(FILENAME, &caratteri, &parole, &righe);
    printf("Risultato analisi file: %d %d %d \n", caratteri, parole, righe);
    return 0;
}

void analizzaFile(char nomeFile[], int *numChar, int*numWord, int*numLine){
    FILE *fp;
    char tmp;
    int isWord, i;
    *numChar = 0;
    *numLine = 0;
    *numWord = 0;
    isWord = 0;
    fp = fopen(nomeFile, "r");
    if(fp){
        while(fscanf(fp, "%c", &tmp)>0){
            (*numChar)++;
            if(isWord == 0 && ((tmp>='a' && tmp<='z') || (tmp>='A' && tmp<='Z') || (tmp>='0' && tmp<='9'))){
                isWord = 1;
                (*numWord)++;
            }
            if(isWord == 1 && !((tmp>='a' && tmp<='z') || (tmp>='A' && tmp<='Z') || (tmp>='0' && tmp<='9'))){
                isWord = 0;
            }
            if(tmp == '\n')
                (*numLine)++;
        }

        fclose(fp);
    }else{
        printf("Errore apertura file...\n");
    }
}