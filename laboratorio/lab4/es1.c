#include<stdio.h>

#define N_OGGETTI 100
#define N_SCATOLE 3
#define MAX_STR 100
#define PESO_CONTAINER 100

typedef struct{
 	char descrizione[MAX_STR+1];
 	float peso_per_unita;
 	int quanti;
 	int codice;
} t_oggetto;

typedef struct{
 	t_oggetto oggetti[N_OGGETTI];
 	int n_oggetti;
 	char descrizione[MAX_STR+1];
 	int codice;
} t_scatola;

int analizzaScatole(t_scatola sc[], int dim, float peso);

int main(){
	int numScatole, i, j;
	t_scatola a[N_SCATOLE];
	for(i=0; i<N_SCATOLE; i++){
		printf("Dimmi il numero di oggetti contenuti: ");
		scanf("%d", &a[i].n_oggetti);
		printf("Dimmi la descrizione della scatola: ");
		scanf("%s", a[i].descrizione);
		printf("Dimmi il codice: ");
		scanf("%d", &a[i].codice);

		for(j=0; j<a[i].n_oggetti; j++){
			printf("\tDimmi la descrizione dell'oggetto: ");
			scanf("%s", a[i].oggetti[j].descrizione);
			printf("\tDimmi il peso: ");
			scanf("%f", &a[i].oggetti[j].peso_per_unita);
			printf("\tDimmi la quantita: ");
			scanf("%d", &a[i].oggetti[j].quanti);
			printf("\tDimmi il codice dell'oggetto: ");
			scanf("%d", &a[i].oggetti[j].codice);
			printf("\n");
		}
		printf("\n\n");

	}
	numScatole = analizzaScatole(a, N_SCATOLE, PESO_CONTAINER);
	printf("Il numero di scatole contenute in un container di capienza %d e': %d ", PESO_CONTAINER, numScatole);
	return 0;
}

int analizzaScatole(t_scatola sc[], int dim, float peso){
	int i, j, nScatole;
	float pesoScatola;
	nScatole = 0;

	for(i=0; i<dim; i++){
		pesoScatola=0;
		for(j=0; j<sc[i].n_oggetti; j++)
			pesoScatola+=sc[i].oggetti[j].peso_per_unita * sc[i].oggetti[j].quanti;

		if(pesoScatola<peso){
			peso-=pesoScatola;
			nScatole++;
		}

	}
	
	return nScatole;
}
