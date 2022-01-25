/*Scrivere la definizione di tipo per elementi di una lista per la gestione di date di nascita, in cui ogni data è rappresentata mediante tre interi, giorno,
mese ed anno.*/

typedef struct{
    int giorno, mese, anno;
}data_nascita_t;

typedef struct N{
    data_nascita_t data;
    struct N* next;    
}nodo_t;
