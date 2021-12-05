/* Domanda 3- (…/6 punti)
Dato un array a[] di n elementi e un intero k>=1, diciamo che a[i] è un k-minimo se è strettamente
minore dei k valori precedenti e dei k valori successivi dell'array.
Si noti che una condizione necessaria (ma non sufficiente) per l'esistenza di un k-minimo è che si abbia
n>=2*k + 1; in caso contrario nessun elemento dell'array avrebbe k elementi precedenti e k elementi
successivi, e quindi non si potrebbe avere alcun k-minimo.
Scrivere la funzione kminimo che riceve in input un array a[], un intero k e qualsiasi altro parametro
ritenuto necessario e restituisca il più piccolo indice i tale che a[i] sia un k-minimo, oppure -1 se non
esiste alcun k-minimo.
Ad esempio, se a[] = {0, 1, 0, 0, -1, 1, 13, 2} e k = 2, allora la funzione deve restituire 4, in quanto
a[4] == -1 è il primo k-minimo (in questo caso, il 2-minimo) dell'array, essendo strettamente minore dei
due valori precedenti {0, 0} e dei due valori successivi {1, 13}.  */

#include<stdio.h>
#define DIM 8

int kMinimo(int a[], int k);

int main(){
	int a[DIM], k, i;

	printf("Riempi un array di %d elementi: ", DIM);
	for(i=0; i<DIM; i++)
		scanf("%d", &a[i]);
	printf("Dimmi un numero: ");
	scanf("%d", &k);

	i = kMinimo(a, k);

	printf("Il più piccolo indice %d-minimo e': %d\n", k, i); 

	return 0;
}

int kMinimo(int a[], int k){
	int min, i, j, notMin;
	min = -1;

	for(i=2; i<(DIM-k); i++){
		notMin=0;
		for(j=1; j<=k; j++){
			if(!(a[i] < a[i+j] && a[i]<a[i-j])){
				notMin=1;
			}
		}

		
		if(!notMin){
			min=i;
		}
	}

	return min;
}
