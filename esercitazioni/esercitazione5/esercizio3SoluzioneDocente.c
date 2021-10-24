#include<stdio.h>
#include<string.h>
#define maxDIM 100
#define NUMLETTERE 26
int main(){
    char frase[maxDIM];
    int lungStringa, vocali, consonanti, i, posizioneAlfabeto;
    int contatori[NUMLETTERE+1];
    printf("Inserisci la frase: ");
    scanf("%[^\n]", frase);
    lungStringa=strlen(frase);

    for(i = 0; i< NUMLETTERE; i++){
        contatori[i] = 0;
    }
    for(i=0; i<lungStringa; i++){
        if(frase[i]>='a' && frase[i]<='z'){
            posizioneAlfabeto=frase[i]-'a';
            contatori[posizioneAlfabeto]++;
        }
        else if(frase[i]>='A' && frase[i]<='Z'){
            posizioneAlfabeto=frase[i]-'A';
            contatori[posizioneAlfabeto]++;
        }
    }
    for(i=0; i<NUMLETTERE; i++){
        printf("La lettera %c e' presente %d volte\n", 'a'+i, contatori[i]);
    }

    vocali = contatori['a'-'a'] + contatori['e'-'a'] + contatori['i'-'a'] + contatori['o'-'a'] + contatori['u'-'a'];
    consonanti = 0;
    for(i=0; i<NUMLETTERE; i++){
        consonanti+=contatori[i];
    }
    consonanti-=vocali;

    printf("Il numero di vocali e': %d\nIl numero di consonanti e': %d\n\n", vocali, consonanti);
    return 0;
}