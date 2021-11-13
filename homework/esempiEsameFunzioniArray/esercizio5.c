/* 5) Realizzare la funzione maxmin7 che accetta come parametro un array v[] di
 * lunghezza n>=7 e qualsiasi
 * altro parametro ritenuto necessario. La funzione deve restituire sia il massimo che
 * il minimo valore
 * della somma di 7 elementi contigui in v[]
 * Ad esempio, se v contiene 1, 2, -4, 1, 3, -5, 2, 10, -1, esistono tre possibili
 * somme di 7 elementi contigui in
 * v[], ossia
 * v[0] + v[1] + v[2] + v[3] + v[4] + v[5] + v[6] = 0
 * v[1] + v[2] + v[3] + v[4] + v[5] + v[6] + v[7] = 9
 * v[2] + v[3] + v[4] + v[5] + v[6] + v[7] + v[8] = 6
 * Quindi in questo caso la funzione deve restituire 9 e 0.
 * Se lo si ritiene utile, e' possibile definire ulteriori funzioni. */

#include<stdio.h>
#define DIM 9
void maxmin7(int v[], int *max, int *min);

int main(){

	int arr[DIM], i, max, min;

	printf("Riempi un array di %d elementi: ", DIM);
	for(i = 0; i<DIM; i++){
		scanf("%d", &arr[i]);
	}

	maxmin7(arr, &max, &min);
	
	printf("Il massimo e' %d e il minimo e' %d\n", max, min);

	return 0;
}

void maxmin7(int v[], int *max, int *min){
	int i, j, sum;

	for(i = 0; i<DIM-7; i++){
		sum = 0;
		for(j=i; j<i+7; j++){
			sum += v[j];
		}
		
		if(!i){
			*max = sum;
			*min = sum;
		}
		
		if(*max<sum)
			*max = sum;
		if(*min > sum)
			*min = sum;
		
	}
}
