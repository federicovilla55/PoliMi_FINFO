/*Scrivere un sottoprogramma che ricevuto in ingresso un valore intero calcola e restituisce al chiamante il numero di cifre che compongono il numero
e sono divisori del numero stesso. Per esempio, se in ingresso il sottoprogramma riceve il valore 12, il sottoprogramma restituisce 2 (1 è divisore di
12, 2 è divisore di 12). Se il sottoprogramma riceve il valore 1012, il sottoprogramma restituisce 3 (1 e 2 sono divisori di 1012 e l’1 compare due volte,
0 non lo è).*/

#include<stdio.h>

int cifreDivisori(int n);

int main(){
    printf("Il numero di cifre divisori di %d e': %d \n", 1012, cifreDivisiori(1012));
}

int cifreDivisiori(int n){
    int i, ris, tmp;
    ris = 0;
    tmp = n;
    while(tmp > 0){
        i = tmp - (tmp/10)*10;
        if(i!=0 && n%i==0)
            ris++;
        tmp/=10;
    }

    return ris;

}