/*Scrivere un sottoprogramma ometti che riceve in ingresso il nome di un file ASCII sorgente src, il nome di un file destinazione dst, e un vocabolo voc (stringa di al più 30 caratteri): il sottoprogramma crea il file destinazione ricopiando il contenuto del file sorgente tranne il vocabolo
voc. Il file sorgente contiene esclusivamente vocaboli, separati da uno spazio, e null’altro (niente segni di interpunzione). Il sottoprogramma
restituisce al chiamante il numero di volte che ha trovato e omesso di copiare il vocabolo voc. Nel caso si abbiano problemi nell?accesso ai
file, si visualizzi il messaggio ERRORE e si restituisca -1.
Per esempio, se il file sorgente ha il seguente contenuto:
effettuo un altro test oltre al TEST di prima per vedere cosa succede
nel caso abbia scritto tEst in modo diverso e voglia comunque omettere il vocabolo dal
testo finale
e se il vocabolo da non copiare è test, il file destinazione dovrà contenere il seguente testo:
effettuo un altro oltre al TEST di prima per vedere cosa succede
nel caso abbia scritto tEst in modo diverso e voglia comunque omettere il vocabolo dal
testo finale*/

#include<stdio.h>
#include<string.h>

int ometti(char src[], char dst[], char voc[]);

int main(){
    printf("Numero di elementi omessi: %d\n", ometti("Testo.txt", "Risultato.txt", "test"));
    return 0;
}

int ometti(char src[], char dst[], char voc[]){
    FILE *in, *out;
    char s[31];
    int num;
    in = fopen(src, "r");
    out = fopen(dst, "w");
    num = 0;

    if(in && out){
        while(fscanf(in, "%s", s) > 0){
            if(strcmp(s, voc) != 0){
                fprintf(out, "%s ", s);
            }else{
                num++;
            }
        }


        fclose(in);
        fclose(out);
    }else{
        printf("Errore...\n");
        num = -1;
    }

    return num;
}