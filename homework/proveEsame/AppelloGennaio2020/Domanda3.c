/*Si scriva un sottoprogramma che riceve come parametro una stringa (che si garantisce non essere
vuota e formata da qualsiasi carattere ASCII), un intero k e qualsiasi altro parametro ritenuto
necessario, e restituisce una nuova stringa, derivata da quella passata come parametro conservando i
primi k caratteri. Se k è maggiore della lunghezza della stringa data, la parte rimanente viene completata
ripetendo l'ultimo carattere fino al raggiungimento del valore k.
Esempi :
"L'appetito vien mangiando" e k=10 → "L'appetito"
"0123456789ABCDEF" e k =20 → "0123456789ABCDEFFFFF" */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *newStringa(char s[], int k){
    char *ris = (char *) malloc(k+1);
    
    if(strlen(s) <= k){
        for(int i=0; i<strlen(s); i++){
            ris[i] = s[i];
        }
        for(int i = strlen(s); i<k; i++){
            ris[i] = s[strlen(s)-1];
        }
        ris[k] = '\0';
    }else{
        strncpy(ris, s, k);
        ris[k] = '\0';
    }
    return ris;
}

int main(){
    char s[20];
    int k;

    printf("Risultato: %s \n", newStringa("L'appetito vien mangiando", 10));
    printf("Risultato: %s \n", newStringa("0123456789ABCDEF", 20));
    return 0;
}   