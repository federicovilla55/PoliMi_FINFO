#include<stdio.h>
#define DIM 20
int main(){
	int arr[DIM], i;
	for(i=0; i<DIM; i++){
		arr[i]=5*i; /*Non avendo particolari richieste sul riempimento dell'array, 
			      ci inserisco la tabellina del 5 che comprende i valori
			      da 5*0 a 5*19*/
	}
	for(i=DIM-1; i>=0; i--)
		printf("%d\n", arr[i]);
	return 0;
}
