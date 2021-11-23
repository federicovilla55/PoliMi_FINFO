/* 2) Scrivere un sottoprogramma che riceve come parametri un array di interi a e la
 * sua dimensione dim.
 * Il sottoprogramma copia in un secondo array b i numeri pari contenuti in a;
 * si noti che b deve essere allocato dinamicamente delle dimensioni strettamente
 * necessarie per contenere i numeri pari.
 * Infine il sottoprogramma trasmette al chiamante b e la sua dimensione.
 * Gestire opportunamente gli eventuali errori di allocazione della memoria
 * trasmettendo una dimensione dell'array allocato pari a -1.
 * Scrivere un programma che chiede all'utente 10 valori interi da salvare in un array.
 * Il programma invoca il sottoprogramma sopra definito e ne visualizza il risultato.
 * Infine il programma libera la memoria allocata. Gestire opportunamente gli eventuali
 * errori di allocazione della memoria. */

#include<stdio.h>
#include<stdlib.h>
#define N 10
int* arrayPari(int a[], int dim, int *dim2);
int main(){
	int v1[N], *v2, i, d2;
	printf("Riempi un array di %d elementi: ", N);
	for(i=0; i<N; i++)
		scanf("%d", &v1[i]);
	v2 = arrayPari(v1, N, &d2);
	if(v2){
		printf("Array pari: ");
		for(i=0; i<d2; i++)
			printf("%d ", *(v2+i));
		printf("\n");
		free(v2);
		v2 = NULL;
	}else{
		printf("Errore allocazione...\n");
	}

	return 0;
}

int* arrayPari(int a[], int dim, int *dim2){
	int *b, i, j;
	*dim2 = 0;
	for(i=0; i<dim; i++){
		if(a[i] % 2 == 0)
			(*dim2)++;
	}
	b = malloc(sizeof(int) * (*dim2));
	
	if(b){
		j=0;
		for(i=0; i<dim; i++){
			if(a[i]%2 == 0){
				b[j] = a[i];
				j++;
			}
		}
	}else{
		printf("Errore allocazione...\n");
		*dim2 = -1;
	}
	return b;
}
