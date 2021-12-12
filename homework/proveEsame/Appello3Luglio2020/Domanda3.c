#include <stdio.h>  
#include <stdlib.h>  

#define FILE_NAME "input.txt"

int isPrime(int n);

int main(void){
	int i, n, prime, maxPrime;
	FILE*fp;
	
	fp = fopen(FILE_NAME, "r");

	if(fp){
		maxPrime=0;
		prime=0;
		while(fscanf(fp, "%d", &n)>0){
			if(isPrime(n)){
				prime++;
			}else
				prime=0;
			if(prime>maxPrime){
				maxPrime=prime;
			}
		}
		
		printf("Numero massimo di numeri primi consecutivi: %d\n", maxPrime);
		fclose(fp);
			
	}else{
		printf("Errore apertura file...");
	}

	return 0;
}

int isPrime(int n){
	int i, ris;
	ris=1;

	for(i=2; i<n/2 && ris; i++){
		if(n%i==0){
			ris=0;
		}
	}


	return ris;
}
