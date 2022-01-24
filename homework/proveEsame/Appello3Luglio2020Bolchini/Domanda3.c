/*Quesito 3 [6 pti]
(5 pti) 1 Scrivere un sottoprogramma cifra che ricevuto in ingresso un valore intero restituisce la cifra che compare più frequentemente. Nel caso ci
siano più cifre che compaiono con più alta frequenza, si restituisce quella più grande.
Ad esempio, se il valore è 447721, il sottoprogramma restituisce 7.
(1 pto) 3 Riscrivere il sottoprogramma precedente adottando questo comportamento nel caso in cui ci siano più cifre con frequenza massima: restituire
quella pari più piccola; se non ci sono cifre pari, restituire la più grande dispari.*/

#include<stdio.h>

int cifra(int n);
int cifra2(int n);

int main(){
    printf("Risultato: %d \n", cifra(447721));
    return 0;
}

int cifra(int n){
    int i, ris, nCopia, tmp, max;

    ris = 0;
    max = 0;
    for(i=0; i<10; i++){
        nCopia = n;
        tmp = 0;
        while(nCopia > 0){
            if(i == (nCopia - (nCopia/10)*10))
                tmp++;
            nCopia /= 10;
        }
        if(tmp == max && ris < i)
            ris = i;
        if(tmp > max){
            max = tmp;
            ris = i;
        }
    }

    return ris;
}

int cifra2(int n){
    int i, ris, risPari, risDispari, nCopia, tmp, max;

    max = 0;
    ris = 0;
    for(i=0; i<10; i++){
        nCopia = n;
        tmp = 0;
        while(nCopia > 0){
            if(i == (nCopia - (nCopia/10)*10))
                tmp++;
            nCopia /= 10;
        }
        if(tmp == max){
            if(ris % 2 == 0){
                if(i%2==0 && ris > i)
                    ris = i;
            }else{
                if(i%2==0)
                    ris = i;
                else{
                    if(i > ris)
                        ris = i;
                }
            }

        }
        if(tmp > max){
            max = tmp;
            ris = i;
        }
    }

    return ris;
}