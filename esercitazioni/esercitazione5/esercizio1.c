/* Scrivere un programma che data una parola in 
*  ingresso ne inverta i caratteri e la stampi 
*  a video */
#include<stdio.h>
#include<string.h>
#define LEN 100
int main(){
    char parola[LEN], invertita[LEN]; 
    /* Si può anche evitare di usare LEN+1 
    *  poiche' non abbiamo limiti di lunghezza */
    int lunghezza, i;
    printf("Inserisci una parola: ");
    scanf("%s", parola);
    lunghezza = strlen(parola);

    for (i = 0; i < lunghezza; i++){
        invertita[i] = parola[lunghezza -1 -i]; 
        /*Lo stesso lo si poteva fare in place (nella stessa variabile) + int temporanea
        * temp = invertita[lunghezza -1 -i];
        * invertita[lunghezza -1 -i] = parola[i]; 
        * invertita[i] = parola[lunghezza -1 -i]; 
        */
    }
    printf("La parola invertita: %s \n", invertita);
    return 0;
}