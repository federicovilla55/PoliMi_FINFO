/*Si vuole realizzare un programma per la gestione di un catalogo di pubblicazioni scientifiche.
a) Definire le strutture dati per memorizzare le pubblicazioni scientifiche, al massimo 100, di un dato
anno. Ciascuna pubblicazione è caratterizzata da un titolo (una stringa di al massimo 100 caratteri), un
anno di pubblicazione, una tipologia (una stringa di al massimo 50 caratteri) ed un insieme di autori (al
massimo 10). Ciascun autore è caratterizzato da nome, cognome, università di affiliazione ed indirizzo
email (ciascuna una stringa di al massimo 50 caratteri).
b) Realizzare un sottoprogramma che riceve come parametri una variabile contenente le pubblicazioni
di un dato anno e il nome di una università; il sottoprogramma restituisce il numero di pubblicazioni di
quell’anno in cui almeno un autore ha come affiliazione il nome dell’università passato come
parametro.*/

#include<stdio.h>
#include<string.h>

typedef struct{
    char nome[51];
    char uni[51];
    char cognome[51];
    char mail[51];
}autori_t;

typedef struct{
    char titolo[100];
    int anno;
    char tipologia[51];
    autori_t a[10];
}pubblicazione_t;

typedef struct{
    pubblicazione_t pub[100];
}pubblicazioni_t;

int pubblicazioni(pubblicazioni_t p, char nomeUni[], int dim){  /* Il parametro DIM contiene il numero di pubblicazioni in p*/
    int ris, i, j, found;
    ris = 0;
    for(i=0; i<dim; i++){
        for(j=0; j<10 && !found; j++){
            if(strcmp(p.pub[i].a[j].uni, nomeUni) == 0){
                found = 1;
                ris++;
            }
        }
    }

    return ris;
}
