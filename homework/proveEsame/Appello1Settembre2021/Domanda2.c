/*Scrivere un sottoprogramma char2ascii che ricevuto in ingresso un carattere crea e restituisce una stringa contenente il byte con la codifica
ASCII binaria del carattere stesso. Per esempio, se il sottoprogramma riceve in ingresso il carattere ’h’ il sottoprogramma crea e restituisce la
stringa "01101000".
Nota: per risolvere l’esercizio non è necessario conoscere il codice ASCII a memoria ...
Scrivere un programma che ricevuta in ingresso una stringa (al più 20 caratteri) visualizza la sequenza binaria corrispondente al codice ASCII
dei caratteri che la costituiscono, avvalendosi del sottoprogramma char2ascii. Per esempio, se il programma riceve in ingresso la stringa
"test" il programma visualizza la sequenza 01110100011001010111001101110100. Fare un uso corretto della memoria. */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *char2ascii(char c);

int main(){
    char s[21];
    int i;
    printf("Inserisci una stringa: \t");
    scanf("%s", s);
    for(i=0; s[i]!='\0'; i++){
        printf("%c in binario: %s \n", s[i], char2ascii(s[i]));
    }
    return 0;
}

char *char2ascii(char c){
    char *ris;
    int i, tmp;
    i = 7;
    ris = malloc(9);
    tmp = (int) c;
    while(tmp > 0){
        if(tmp%2 == 0)
            ris[i] = '0';
        else
            ris[i] = '1';
        tmp /= 2;
        i--;
    }
    ris[0]='0';
    ris[8]='\0';

    return ris;
}