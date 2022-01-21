/*Definire una struttura dati intervallo che definisce definisce l'intervallo chiuso [a, b] (in
 un intervallo chiuso gli estremi sono inclusi, con a e b numeri reali.
Dato un array s [n] contenente n>=0 intervalli chiusi, ciascuno del tipo intervallo definito sopra, la
funzione intervallo_min che riceve come parametri l’array s, un valore reale x e qualsiasi altro
parametro ritenuto necessario e restituisce l'indice dell'intervallo in s di ampiezza minima contenente il
valore x; se non esiste alcun intervallo che contiene x, la funzione deve restituire -1. Si garantisce che
l'intervallo di ampiezza minima contenente x, se esiste, sia sempre unico.
(Suggerimento: anche se non strettamente necessario, potrebbe risultare utile definire e utilizzare
funzioni ausiliarie)
Ad esempio, per
s [] = { {0, 1}, x=0 la funzione restituirà 0
{2, 4}, x= 12 la funzione restituirà -1
{2, 5}, x= 4 la funzione restituirà 1
 {3, 10},
{0, 4},
{4, 8},
{5, 8}}*/

#include<stdio.h>
#define DIM 5

typedef struct{
    int a, b;
}intervallo;

int intervallo_max(intervallo s[], int x, int dim);

int main(){
    intervallo p[DIM];
    int i, x;
    printf("Riempi %d intervalli: ", DIM);
    for(i=0; i<DIM; i++)
        scanf("%d %d", &p[i].a, &p[i].b);
    printf("Dimmi il valore di X: ");
    scanf("%d", &x);
    printf("L'intervallo di ampiezza minima contenente %d e': %d \n", x, intervallo_max(p, x, DIM));
    return 0;
}

int intervallo_max(intervallo s[], int x, int dim){
    int i, ris, min;
    min = s[0].b - s[0].a;
    ris = -1;

    for(i=0; i<dim; i++){
        if(x <= s[i].b && x >= s[i].a){
            if(min >= (s[i].b - s[i].a)){
                ris = i;
                min = s[i].b - s[i].a;
            }
        }
    }

    return ris;
}