/*Cifrario di Cesare
In crittografia il cifrario di Cesare è uno dei più antichi algoritmi crittografici di cui si abbia traccia storica. È
un cifrario a sostituzione monoalfabetica in cui ogni lettera del testo in chiaro è sostituita nel testo cifrato
dalla lettera che si trova un determinato numero di posizioni dopo nell'alfabeto. Il numero di posizioni scelto
per effettuare tutte le sostituzioni è detto chiave del cifrario.
Si scriva un sottoprogramma cifra che, dato un array c di char e un intero k, modifichi ogni carattere di c (che
si assume essere una lettera alfabetica minuscola) applicando una cifratura di Cesare con chiave k.
ES. c = ['L', 'U', 'C', 'A’] k = 3 ['O', 'X', 'F', 'D']
Successivamente, implementare anche la funzione decifra.
Utilizzare l’aritmetica dei puntatori per la funzione cifra e l’ accesso ad array tramite indici per la funzione
decifra.*/

#include<stdio.h>
#define NUM_LETTERE 26
#define DIMS 20

void cifra_idx(char c[], int k);
void decifra(char c[], int k);


int main(){
    int k;
    char msg[DIMS+1];

    printf("Inserire messaggio: ");
    scanf("%s", msg);
    printf("Inserire chiave: ");
    scanf("%d", &k);
    cifra_idx(msg, k);
    printf("Messaggio cifrato: %s\n", msg);
    decifra(msg, k);
    printf("Decifrato: %s\n", msg);

    return 0;
}

void cifra_idx(char c[], int k){
    int i, pos_lettera;
    for(i=0; c[i]!='\0'; i++){
        pos_lettera = c[i] - 'a';
        c[i]= 'a' + (pos_lettera + k) % NUM_LETTERE;
    }
}

void cifra(char *c, int k){
    int i, pos_lettera;
    for(i=0; *(c + i) != '\0'; i++){
        pos_lettera = *(c+i) - 'a';
        *(c+i) = 'a' + (pos_lettera + k) % NUM_LETTERE;
    }
}

void cifra(char *c, int k){
    int pos_lettera;
    while (*c != '\0'){
        pos_lettera = *(c) - 'a';
        *(c) = 'a' + (pos_lettera + k) % NUM_LETTERE;
        *c ++;
    }
}

void decifra(char c[], int k){
    int i, pos_lettera;
    for(i=0; c[i]!='\0'; i++){
        pos_lettera = c[i] - 'a';
        c[i]= 'a' + (pos_lettera - k) % NUM_LETTERE;
    }
}