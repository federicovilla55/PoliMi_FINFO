/*Si scriva un sottoprogramma rightshift che ricevuta in ingresso una stringa sorgente s e un numero
intero senz’altro positivo n, modifica la stringa in modo tale che la stringa finale sia quella iniziale, fatta
scorrere di n posizioni a destra (con gli ultimi n caratteri riportati all’inizio).
Per esempio se la stringa iniziale è Giuseppe ed n = 1, la stringa finale sarà eGiusepp, se n = 2, la
stringa finale sarà peGiusep.*/
#include<stdio.h>
#define LEN 30

void rightShift(char s[], int n);

int main(){
    int n;
    char parola[LEN+1];
    printf("Dimmi una parola e un numero: ");
    scanf("%s %d", parola, &n);
    rightShift(parola, n);
    printf("Risultato: %s \n", parola);
    return 0;
}

void rightShift(char s[], int n){
    int i, j, tmp, tmp2;

    tmp = s[0];
    tmp2 = s[1];

    for(i=0; i<n; i++){
        for(j=0; s[j]!='\0'; j++){
            if(s[j+1]!='\0'){
                tmp2=s[j+1];
                s[j+1]=tmp;
                tmp = tmp2;
            }else{
                s[0] = tmp;
                tmp2 = s[1];
            }
        }
    }
}