/* 2) Scrivere un sottoprogramma che riceve in ingresso un array a di numeri interi
 * positivi e qualsiasi altro
 * parametro ritenuto strettamente necessario. Il sottoprogramma elimina dall'array
 * tutti i numeri non
 * primi compattando l’array, stampa i video l’array così ottenuto e restituisce al
 * chiamate il numero di
 * elementi alla fine presenti nell'array.
 * (Ricordo che eliminare un elemento i-esimo in un array significa spostare gli
 * elementi dall’ i+1-esimo
 * fino all’elemento N-1-esimo per coprire il vuoto lasciato dall’elemento eliminato)  */

#include<stdio.h>
#define DIM 10
int riduciArray(int arr[]);

int main(){
	int a1[DIM], i, numEl;
	
	for(i=0; i<DIM; i++){
		printf("Dimmi un elemento dell'array: ");
		scanf("%d", &a1[i]);
	}
	
	numEl=riduciArray(a1);
	
	printf("Il numero di elementi presenti nell'array sono: %d", numEl);

	return 0;
}


int riduciArray(int arr[]){
	int i, dim, j, isPrimo;
	dim = DIM;
	for(i=0; i<DIM; i++){
		isPrimo=1;
		for(j=2; j<=arr[i]/2 && isPrimo; j++){
			if(arr[i]%j==0){
				isPrimo=0;
			}
		}
		if(isPrimo){
			for(j=i+1; j<DIM-1; j++){
				arr[j-1]=arr[j];
			}
			dim--;
		}
	}
	return dim;
}
