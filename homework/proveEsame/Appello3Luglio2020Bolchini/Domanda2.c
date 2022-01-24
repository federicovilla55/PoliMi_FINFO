/*Quesito 2 [6 pti]
Scrivere un sottoprogramma chericeve in ingresso una stringa contente un paragrafo ditesto scritto in italiano. Il sottoprogramma modifica la stringa
eliminando da essa tutti i segni di interpunzione, ossia quei caratteri che differiscono dai caratteri ’a’-’z’, ’A’-’Z’, ’0’-’9’ e spazio. Il
sottoprogramma restituisce il numero di caratteri eliminati.
È garantito che nel testo iniziale ci siano tutti e soli caratteri ’a’-’z’, ’A’-’Z’, ’0’-’9’, spazi e segni di interpunzione.*/
#include<stdio.h>
#include<string.h>

int eliminaNonCaratteri(char s[]);

int main(){
    char s[100];
    strcpy(s, "S0m$e! W#3i7&d T3xt@");

    printf("Numero caratteri eliminati: %d \t Stringa finale: %s\n", eliminaNonCaratteri(s), s);

    return 0;
}

int eliminaNonCaratteri(char s[]){
    int i, j, numModifiche;

    numModifiche = 0;

    for(i=0; s[i]!='\0'; i++){
        if(!((s[i]>='0' && s[i]<='9') || (s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))){
            numModifiche++;
            for(j=i; s[j]!='\0'; j++){
                s[j] = s[j+1];
            }
        }
    }

    return numModifiche;
}