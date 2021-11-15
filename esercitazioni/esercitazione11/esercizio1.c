/* Esercizio Tower of Hanoi */

#include<stdio.h>

void hanoi(int src, int destinazione, int tmp, int n);

int main(){

	int n;	
	printf("Dimmi il numero di dischi: ");
	scanf("%d", &n);
	hanoi(1, 3, 2, n);

	return 0;
}

void hanoi(int src, int destinazione, int tmp, int n){
	if(n == 1){
		printf("Sposta il disco dal perno %d al perno %d\n", src, destinazione);
	}else{
		hanoi(src, tmp, destinazione, n-1);
		printf("Sposta il disco dal perno %d al perno %d. \n", src, destinazione);
		hanoi(tmp, destinazione, src, n-1);
	}
}
