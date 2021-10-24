/*Inserito un numero dire se tale numero e' primo */
#include<stdio.h>
int main(){
	int n, i, primo;
	do{ 
		scanf("%d", &n);
	}while(n<=0);
	primo=1;
	for(i=2; i<n/2 && primo; i++){
		if(n%i==0)
			primo=0;
	}
	if(primo)
		printf("Numero primo");
	else
		printf("Numero non primo, divisibile per %d", i);
	return 0;
}
