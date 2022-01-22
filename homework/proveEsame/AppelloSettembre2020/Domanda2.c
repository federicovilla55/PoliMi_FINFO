/*Scrivere un sottoprogramma verifica che ricevuta in ingresso una stringa che contiene una
password, restituisce 1 se sono verificate tutte le condizioni seguenti, 0 altrimenti:
• è presente almeno una cifra
• è presente almeno un carattere che non sia una cifra o un carattere dell’alfabeto
• è di almeno 8 caratteri
• non contiene tre caratteri uguali consecutivi
(1 pto) Scrivere un programma che acquisisce da riga di comando la password, chiama il
sottoprogramma verifica e visualizza se la password è valida (1) oppure no (0).*/
#include<stdio.h>

int isPassword(char s[]);

int main(int argv, char argc[]){

    printf("La password e' valida? %d\n", isPassword(argc[1]));

    return 0;
}


int isPassword(char s[]){
    int i, isCifra, isSpecial, ris;

    isCifra = 0;
    isSpecial = 0;
    ris = 1;

    for(i=0; s[i]!='\0' && ris; i++){
        if(s[i] >= '0' && s[i]<='9')
            isCifra = 1;
        else
            if(!(s[i] >= 'a' && s[i]<='z') && !(s[i] >= 'A' && s[i]<='Z'))
                isSpecial = 1;
        if(i>2)
            if(s[i] == s[i-1] && s[i] == s[i-2])
                ris=0;
    }
    return ((i>=8) && ris && isSpecial && isCifra);
}