/* Si definisca un sottoprogramma che, dato un array a[] non vuoto di numeri reali, restituisca l'indice del
valore dell'array che è più vicino, in valore assoluto, alla media aritmetica dei valori di a.
Ad esempio, se a[] = {4.0, 2.0, 3.0, 12.0}, allora il valore medio è 5.25; il sottoprogramma deve
restituire 0, in quanto a[0] è il valore dell'array più vicino, in valore assoluto, alla media.
Si garantisce che il valore più vicino sarà sempre univocamente definito.  */
#include<stdio.h>
#define DIM 4
int findIndex(float a[]);
float mediumValue(float a[]);
int main(){
	int i, indexMedium;
	float a[DIM];
	printf("Riempi un array di %d elementi: ", DIM);
	for(i=0; i<DIM; i++){
		scanf("%f", &a[i]);
	}
	indexMedium = findIndex(a);
	printf("L'indice dell'elemento piu' vicino alla media e': %d\n", indexMedium);
	return 0;
}

float mediumValue(float a[]){
	int i;
	float media;
	media = 0;
	for(i = 0; i<DIM; i++)
		media += a[i];
	media/=DIM;
	return media;
}

int findIndex(float a[]){
	int i, max;
	float media, min, tmp;
	media = mediumValue(a);
	max = 0;
	min = media - a[max];
	if(min<0)
		min = -min;
	for(i=1; i<DIM; i++){
		tmp=media - a[i];
		if(tmp<0)
			tmp=-tmp;
		if(tmp<min){
			max=i;
			min=tmp;
		}
	}
	return max;
}
