/*Scrivere un sottoprogramma che riceve come parametro una stringa che rappresenta un numero intero
positivo in base 8 (cioè composta soltanto dai caratteri dallo ‘0’ al ‘7’). Il sottoprogramma calcola e
restituisce il valore intero rappresentate lo stesso numero in base 10. Nel caso la stringa contenga un
carattere non valido, il sottoprogramma restituisce il valore -1.
Esempio 1: Se il sottoprogramma riceve in ingresso la stringa “24” restituisce il valore 20 (infatti 2 x 81
+ 4 x 80 = 20).
Esempio 2: Se il sottoprogramma riceve in ingresso la stringa “95” restituisce il valore -1 (infatti ‘9’
non è un carattere tra ‘0’ e ‘7’). Stessa cosa se il sottoprogramma riceve in ingresso la stringa “h5”*/

#include<stdio.h>

int base8to10(char s[]);

int main(){
    printf("Risultato: %d \n", base8to10("145711"));
    return 0;
}

int base8to10(char s[]){
    int i, esp, ris;
    ris = 0;
    esp = 1;
    for(i=0; s[i]!='\0'; i++)
        esp*=8;
    
    for(i=0; s[i]!='\0' && ris!=-1; i++){
        esp /= 8;
        if(s[i]>='0' && s[i]<='7')
            ris+=(s[i]-'0')*esp;
        else
            ris=-1;
    }
    return ris;
}