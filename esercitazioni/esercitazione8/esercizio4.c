/*Massimo Numero Perfetto*/

#include<stdio.h>
#define N 10
int numeroPerfetto(int);

int main(){
	
	int i, max, nums[N];
	max = 0;
	
	for (i=0; i<N; i++){
		scanf("%d", &nums[i]);
		if (numeroPerfetto(n) && max<nums[i])
			max=nums[i];
	}
	if(!max){
		printf("Il massimo numero perfetto e': %d", max);
	}else{
		printf("Non esiste un numero perfetto");
	}
	
	return 0;
}

int numeroPerfetto(int n){
	int somma, i;
	somma=0;
	
	for(i=1; i<=n/2; i++){
		if(!n%i){
			somma+=i;
		}
	}
	
	return (somma==n);
}