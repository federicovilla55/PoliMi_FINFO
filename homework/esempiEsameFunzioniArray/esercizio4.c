/* 4) Dato un array a[] di N elementi interi e un intero k>=1, diciamo che il valore
 * a[i] è un k-massimo se è
 * strettamente maggiore dei k valori precedenti e dei k valori successivi dell'array.
 * Scrivere il sottoprogramma kmassimo che riceve in input un array a[] di interi, un
 * intero k e qualsiasi
 * altro parametro ritenuto necessario e restituisca il più piccolo indice i tale che
 * a[i] sia un k-massimo,
 * oppure -1 se non esiste alcun k-massimo.
 * Ad esempio, se a[] = {1, 2, 3, 2, 1} e k = 2, allora la funzione deve restituire 2,
 * in quanto il valore di
 * a[2] è 3 ed è il primo k-massimo (in questo caso, il 2-massimo) dell'array, essendo
 * strettamente
 * maggiore dei due valori precedenti {1, 2} e dei due valori successivi {2, 1}. */

#include<stdio.h>
#define DIM 5

int kMassimo(int a[], int k);

int main(){
	int i, arr[DIM], k, minKMassimo;
	
	printf("Dimmi un array di %d numeri interi e un numero intero k: ", DIM);
	for(i=0; i<DIM; i++)
		scanf("%d", &arr[i]);
	scanf("%d", &k);

	minKMassimo = kMassimo(arr, k);
	if (minKMassimo == -1)
		printf("Non esiste alcun %d-massimo\n", k);
	else	
		printf("Il primo %d-massimo e' l'elemento in posizione %d\n", k, minKMassimo);

	return 0;
}

int kMassimo(int a[], int k){
	int i, index, maggPrec, maggSucc;
	index = -1;

	for(i=k; i<DIM-k; i++){

		maggPrec = a[i] > a[i-1] && a[i] > a[i-2];
		maggSucc = a[i] > a[i+1] && a[i] > a[i+2];
		
		if(maggPrec && maggSucc){
			index = i;
			i= DIM - k;
		}
	}

	return index;
}
