/* Scrivere un programma che legga una frase da tastiera terminata da invio
 * e stampi il numero di volte che ciascuna lettera e' presente nella frase
 * il numero di consonanti presenti nella frase */
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define LEN 100
#define ALPHABETLEN 26
int main(){
    char str[LEN], letter;
    int i, j, consonanti, lunghezza, cont;
    consonanti=0;

    printf("Inserisci una frase: ");
    scanf("%[^\n]", str);
    lunghezza=strlen(str);
    for (i = 0; i < ALPHABETLEN; i++)
    {
        cont=0;
        letter = 'a' + i;
        for(j=0; j<lunghezza; j++){
            if(tolower(str[j])==letter){
                cont++;
                if(letter!='a' && letter!='e' && letter!='i' && letter!='o' && letter!='u')
                    consonanti++;
            }
        }
        printf("La lettera %c e' presente %d volte \n", letter, cont);
    }
    printf("In totale ci sono: %d consonanti\n", consonanti);
    return 0; 
}
