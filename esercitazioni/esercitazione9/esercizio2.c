#include<stdio.h>
#define DIM 50
#define INFO 30
typedef struct{
	int codice;
	gestore_t dati;
	automobile_t car[50];
}concessionario_t;

typedef struct{
	int pIVA;
	char nome[INFO];
	char cognome[INFO];
}gestore_t;

typedef struct{
	char modello[INFO];
	char targa[7];
	int mese;
	int anno;
}automobile_t

int createReport(concessioanrio_t c[], int dim, int AA){
	int i, j;
	for(i=0; i<dim; i++){
		for(j=0; j<dim; j++){
			if(AA == c[i].car[k].anno)
				printf("Conc %d, codice %d, gestore %s\n Immatricolazioni %d, mese %d, Modello %s, Targa: %d", i, c[i].codice);
		}
	}
}
