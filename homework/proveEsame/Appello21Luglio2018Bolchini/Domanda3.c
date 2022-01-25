/*Scrivere un sottoprogramma rot che ricevuta in ingresso una stringa voc ed un numero intero senz’altro positivo n, la modifica in modo
tale che la stringa finale sia quella iniziale, fatta scorrere a destra di n posizioni, con gli ultimi n caratteri riportati in testa. Se per esempio la
stringa iniziale è Esempio ed n è 1, la stringa finale sarà oEsempi. Data la stringa iniziale Fondamenti e il valore 4, la stringa finale è
entiFondam.
(1 punto) Scrivere il programma che acquisisce da riga di comando la stringa s e l’intero n e dopo aver utilizzato il sottoprogramma rot visualizza la
stringa risultante.*/

#include<stdio.h>

void rot(char voc[], int n);

int main(int argc, char *argv[]){
    int n;
    if(argc == 3){
        printf("--%d--", argv[2][0]-'0');
        rot(argv[1], n);
        printf("Risultato: %s \n", argv[1]);
    }

    return 0;
}

void rot(char voc[], int n){
    int i, j;
    char tmp, tmp2;
    for(i=0; i<n; i++){
        tmp = voc[0];
        tmp2 = voc[1];
        for(j=0; voc[j]!='\0'; j++){
            if(voc[j+1] == '\0'){
                tmp2 = voc[0];
                voc[0] = tmp;
                tmp = tmp2;
            }else{
                tmp2 = voc[j+1];
                voc[j+1] = tmp;
                tmp = tmp2;
            }
        }
    }
}