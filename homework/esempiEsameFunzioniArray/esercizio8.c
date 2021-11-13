/* 8) Si definisca un sottoprogramma che, dato un array a[] non vuoto di numeri reali,
 * restituisca l'indice del
 * valore dell'array che è più vicino, in valore assoluto, alla media aritmetica dei
 * valori di a.
 * Ad esempio, se a[] = {4.0, 2.0, 3.0, 12.0}, allora il valore medio è 5.25; il
 * sottoprogramma deve
 * restituire 0, in quanto a[0] è il valore dell'array più vicino, in valore assoluto,
 * alla media.
 * Si garantisce che il valore più vicino sarà sempre univocamente definito.  */

#include<stdio.h>
#define DIM 4

int valoreVicinoMedia(float v[]);

int main(){
	float arr[DIM]; 
	int i, nearMedia;
	
	printf("Riempi un array di %d elementi: ", DIM);
	for(i=0; i<DIM; i++){
		scanf("%f", &arr[i]);
	}

	nearMedia = valoreVicinoMedia(arr);

	printf("Il valore più vicino alla media e' quello in posizione %d\n", nearMedia);

	return 0;
}

int valoreVicinoMedia(float v[]){
	int i, index;
	float media, minDiff, tmpDiff;
	media = 0;

	for(i=0; i<DIM; i++)
		media+=v[i];
	media = media/DIM;
	
	minDiff = media - v[0];
	if(minDiff < 0)
		minDiff = -minDiff;
	index = 0;

	for(i=1; i<DIM; i++){
		tmpDiff = media - v[i];
		if(tmpDiff < 0)
			tmpDiff = -tmpDiff;
		if(tmpDiff < minDiff){
			index = i;
			minDiff = tmpDiff;
		}
	}

	return index;
}
