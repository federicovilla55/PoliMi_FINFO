/* C implementation of an iterative algorithm fot the 
 * Fibonacci sequence*/

#include<stdio.h>

int main(){
	int i, n, ris, a[2];

	a[0]=1;
	a[1]=1;
	/*The array a is for storing the n-1 and n-2 values*/
	
	printf("Dimmi il numero di mese che vuoi analizzare: ");
	scanf("%d", &n);

	for(i=1; i<n; i++){
		ris=a[0];
		a[0]=a[0]+a[1];
		a[1]=ris;	
	}

	printf("Il numero di coppie a fine del mese %d e': %d\n", n, a[1]);
	
	return 0;

}
