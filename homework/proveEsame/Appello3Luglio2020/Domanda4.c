#include <stdio.h>  
#include <stdlib.h>  

#define CAPACITY 100
#define MAX_LEN 50

typedef struct{
	int codice;
	char titolo[MAX_LEN+1];
	char autore[MAX_LEN+1];
	int prezzo;
}scultura_t;

typedef struct{
	scultura_t s[CAPACITY];
}negozio_t;

scultura_t* scultureCostose(negozio_t n[], int p, int dim);

int main(){

	/* Inizializzare le varie variabili... */	

	return 0;
}


scultura_t* scultureCostose(negozio_t n[], int p, int dim){
	scultura_t *expensive;
	int i, j, pos, len;

	expensive=NULL;
	len=0;

	for(i=0; i<dim; i++){
		for(j=0; j<CAPACITY; j++){
			if(n[i].s[j].prezzo>p){
				len++;
			}
		}
	}

	expensive = malloc(sizeof(scultura_t) * len);
	pos = 0;

	if(expensive){
		for(i=0; i<dim; i++)
			for(j=0; j<CAPACITY; j++){
				if(n[i].s[j].prezzo > p){
					*(expensive+pos) = n[i].s[j];
					pos++;
				}
			}
	}else{
		printf("Errore malloc\n");
	}

	return expensive;
}
