#include <stdio.h>
#include <stdlib.h>
#define DIM 5

int eliminaNonPrimi(int a[], int dim);
int isPrime(int num);

int main(void){
	int i, arr[DIM];
	printf("Riempi un array di %d elementi: ", DIM);
	for(i=0; i<DIM; i++)
		scanf("%d", &arr[i]);

	printf("Numero di elementi primi nell'array: %d", eliminaNonPrimi(arr, DIM));
	
	return 0;
}

int isPrime(int num){
	int ris, i;
	ris = 1;
	for(i=2; i<num && ris; i++){
		if(num%i==0)
			ris = 0;
	}

	return ris;
}

int eliminaNonPrimi(int a[], int dim){
	int i, j;

	for(i=0; i<dim; i++){
		if(!isPrime(a[i])){
			for(j=i; j<dim-1; j++){
				a[j] = a[j+1];
			}
			dim--;
		}
	}

	for(i=0; i<dim; i++){
		printf("%d \n", a[i]);
	}

	return dim;
}
