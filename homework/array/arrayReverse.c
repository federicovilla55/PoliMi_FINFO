#include<stdio.h>
#define DIM 20
int main(){
	int arr[DIM], i, tmp;
	for(i=0; i<DIM; i++){
		arr[i]=5*i; /*Non avendo particolari richieste sul riempimento dell'array,
		              ci inserisco la tabellina del 5 che comprende i valori
		              da 5*0 a 5*19*/
	}
	
	for(i=0; i<(DIM/2); i++){
		tmp=arr[DIM-1-i];
		arr[DIM-1-i]=arr[i];
		arr[i]=tmp;
	}
	printf("\nDopo aver inizializzato un array con i multipli di 5 da 0 a 19 (valori scelti\nper riempire un array), si provveda ad invertirlo e a stamparlo: \n");
	for(i=0; i<DIM; i++)
		printf("\t%d\n", arr[i]);

	return 0;
}
