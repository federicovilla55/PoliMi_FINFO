/*Quesito 4 [9 pti]
Si vuole realizzare le funzionalità base di un correttore ortografico che, mediante l’ausilio di un dizionario di parole salvato in un file ditesto, identifica
eventuali errori di battitura che hanno causato l’aggiunta di lettere errate all’interno di una parola o il loro mancato inserimento. Esempio: l’utente
al posto di ciao digita cxiauo o cia.
(4 pti) Scrivere un sottoprogramma istypo che riceve due stringhe in ingresso, digitata (dig) e un vocabolo corretto (voc), e le confronta, restituendo 1 se tutti i caratteri di voc compaiono in dig nella stessa sequenza, eventualmente con ulteriori caratteri, 0 altrimenti. A titolo di
esempio si considerino le seguenti casistiche:
• digitata = cciaoo, vocabolo = ciao: restituisce 1
• digitata = caio, vocabolo = ciao: restituisce 0
• digitata = acciaio, vocabolo = ciao: restituisce 1
• digitata = cia, vocabolo = ciao: restituisce 0
Appello del 25/06/2021 Fondamenti di Informatica - A.A. 2020-2021 Pagina 2 di 3
(5 pti) Scrivere un programma che acquisisce da riga di comando due stringhe. La prima stringa contiene un vocabolo scritto in modo errato, la seconda
il nome delfile contenente il dizionario da consultare(i vocaboli contenuti sono di al più 35 caratteri). Il programma si avvale del sottoprogramma
istypo per visualizzare la lista dei vocaboli che forse l’utente avrebbe voluto scrivere invece di quello contenente l’errore. Il programma
visualizza anche il numero di vocaboli trovati. Per esempio, se si esegue il programma con il vocabolo cciao e dizionario.txt ciò che
viene visualizzato è quanto segue:
./suggerisci acciaccio dizionario.txt
a  \n acca \n accia \n acciacco \n ... alternative*/

#include<stdio.h>
#define DIM 20
int isTypo(char dig[], char voc[]);

int main(int argc, char *argv[]){
    FILE *fp;
    char giusta[DIM+1];

    if(argc == 3){
        fp = fopen(argv[2], "r");
        if(fp){
            while(fscanf(fp, "%s", giusta) > 0){
                if(isTypo(argv[1], giusta))
                    printf("Forse volevi digitare: %s ?\n", giusta);
            }
            fclose(fp); 
        }else{
            printf("Errore apertura file...\n");
        }

    }else{
        printf("Argomenti insufficienti...\n");
    }

    return 0;
}

int isTypo(char dig[], char voc[]){
    int i, ris, j, tmp;

    ris = 1;
    for(i=0; voc[i]!='\0' && ris; i++){
        ris = 0;
        for(j=i; dig[j]!='\0' && !ris; j++){
            if(dig[j] == voc[i])
                ris = 1;
        }
    }

    return ris;
}