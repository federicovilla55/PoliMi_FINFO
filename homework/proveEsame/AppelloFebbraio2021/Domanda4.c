/*(a) Si scriva un sottoprogramma per un correttore automatico di testo, in grado di rimuovere gli errori
di battitura che abbiano generato parole con tre o più consonanti uguali adiacenti eliminando
tutte le occorrenze della consonante tranne due. Il sottoprogramma riceve come parametri il riferimento 
ad un file di testo ASCII (c’è un vocabolo per riga, ogni vocabolo è al più di 15 caratteri e con lettere 
minuscole) già aperto e il riferimento a un file di testo ASCII su cui scrivere.
Il sottoprogramma copia il contenuto del primo file nel secondo, correggendo automaticamente gli 
errori descritti sopra e restituisce il numero massimo di lettere eliminate in una parola. Si possono usare 
le funzioni di libreria e se lo si ritiene utile si possono definire funzioni aggiuntive.
Esempio:
File di input:
gatttto
mammmmmma
ciaooooo
File di output:
gatto
mamma
ciaooooo
il numero massimo di lettere eliminate è 4.
(b) Scrivere un programma che acquisisce da riga di comando il nome dei due file, effettua le 
inizializzazioni e operazioni necessarie, chiama il sottoprogramma sopra definito e visualizza il risultato 
ottenuto*/

#include<stdio.h>

int correggiFile(FILE *in, FILE *out);

int main(){

    FILE *in;
    FILE *out;
    in = fopen("input.txt", "r");
    out = fopen("out.txt", "w");

    printf("Numero massimo di lettere eliminate: %d \n", correggiFile(in, out));

    return 0;
}

int correggiFile(FILE *in, FILE *out){
    int i, j, maxCorr, incorrect, tmp;
    char word[16];
    
    maxCorr = 0;

    if(in && out){
        while(fscanf(in, "%s", word) > 0){
            tmp = 0;
            do{
                incorrect = 0;
                for(i=0; word[i+2]!='\0'; i++){
                    if(word[i] == word[i+2] && word[i] == word[i+1] && !(word[i] == 'a' || word[i] == 'e' ||
                    word[i] == 'i' || word[i] == 'o' || word[i] == 'u')){
                        incorrect = 1;
                        j = i;
                    }
                }
                if(incorrect){
                    while(word[j]==word[j+1] && word[j]==word[j+2]){
                        for(i=j+2; word[i]!='\0'; i++){
                            word[i] = word[i+1];
                        }
                        tmp++;
                    }
                }

                if(tmp > maxCorr)
                    maxCorr = tmp;

            }while(incorrect);
            fprintf(out, "%s\n", word);
        }
    }
    return maxCorr;
}