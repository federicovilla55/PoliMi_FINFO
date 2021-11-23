/* 1) Scrivere un sottoprogramma che riceve come parametri un array a1 di interi e la
 * sua dimensione dim.
 * Il sottoprogramma alloca dinamicamente un array della stessa dimensione dim, vi
 * copia il contenuto di a1 e lo restituisce al chiamante.
 * Gestire opportunamente gli eventuali errori di allocazione della memoria.
 * Scrivere un programma che dichiara un array da 10 elementi interi e lo popola con i
 * valori letti da tastiera.
 * Il programma invoca il sottoprogramma sopra definito e visualizza il suo risultato.
 * Infine il programma rilascia la memoria allocata dinamicamente. Gestire
 * opportunamente gli eventuali errori di allocazione della memoria. */
#include<stdio.h>
#include<stdlib.h>
#define N 10
int* copiaArr(int a1[], int dim);
int main(){
	int i, a1[N], *a2;
	printf("Riempi un array di %d elementi: ", N);
	for(i=0; i<N; i++)
		scanf("%d", &a1[i]);

	a2 = copiaArr(a1, N);
	if(a2){
		printf("Array risultante: ");
		for(i=0; i<N; i++)
			printf("%d ", *(a2+i));
		printf("\n");
		
		free(a2);
		a2=NULL;
	}else{
		printf("Errore allocazione array\n");
	}
	return 0;
}

int* copiaArr(int a1[], int dim){
	int i, *ris;
	ris = malloc(sizeof(int) * dim);
	if(ris){
		for(i=0; i<dim; i++){
			*(ris + i) = a1[i];
		}
	}else{
		printf("Errore allocazione\n");
	}

	return ris;
}
