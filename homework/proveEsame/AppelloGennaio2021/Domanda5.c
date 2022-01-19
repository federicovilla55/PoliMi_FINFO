/*Domanda 5- (.../6 punti)
Si vuole realizzare un programma per la gestione informatizzata del menu di una pizzeria.
Ogni pizza è definita da un codice numerico, da un nome di non più di 30 caratteri, da una lista di non
più di 10 ingredienti e da un costo. Ogni ingrediente a sua volta è definito da un codice numerico e da
un nome di non più di 50 caratteri. Si definiscano le strutture dati necessarie per rappresentare una pizza
e si scriva un sottoprogramma che riceve come parametri un array di pizze, la sua dimensione, un
valore intero n (e qualsiasi altro parametro ritenuto necessario). Il sottoprogramma visualizza il nome di
tutte le pizze che contengono meno di n ingredienti.
Scrivere inoltre un main dove viene dichiarato un array da 60 pizze ed viene invocato il
sottoprogramma definito in precedenza.*/
#include<stdio.h>
#define N 60

typedef struct{
    int codice;
    char nome[50+1];
}ingrediente_t;
typedef struct{
    int codice;
    char nome[30+1];
    ingrediente_t ingredienti[10];
    int costo;
}pizza_t;

void vediPizza(pizza_t p[], int dim, int n);

int main(){
    pizza_t p[N];
    int i, j;

    for(i=0; i<N; i++){
        printf("Pizza %d: \n", i+1);
        printf("\t Inserire il Codice: ");
        scanf("%d", &p[i].codice);
        printf("\t Inserire il Nome: ");
        scanf("%s", p[i].nome);
        printf("\t Inserire il Costo: ");
        scanf("%d", &p[i].costo);
        for(j=0; j<10; j++){
            printf("\t\t Inserisci il codice dell'ingrediente %d: ", i+1);
            scanf("%d", &p[i].ingredienti[j].codice);
            printf("\t\t Inserisci il nome:");
            scanf("%s", p[i].ingredienti[j].nome);
        }
    }

    vediPizza(p, N, 4);

    return 0;
}

void vediPizza(pizza_t p[], int dim, int n){
    int i, j;
    for(i=0; i<dim; i++){
        for(j=0; j<10 && p[i].ingredienti[j].codice; j++);

        if(j<n){
            printf("Pizza %s \n", p[i].nome);
        }

    }
}