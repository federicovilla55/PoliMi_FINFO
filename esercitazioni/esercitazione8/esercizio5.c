/*Numero di Amstrong*/

#include<stdio.h>
int numeroAmstrong(int);

int main(){
	
	int i, max, nums[N];
	max = 0;
	
	for (i=0; i<N; i++){
		scanf("%d", &nums[i]);
		if (numeroAmstrong(n) && max<nums[i])
			max=nums[i];
	}
	if(!max){
		printf("Il massimo numero di Amstrong e': %d", max);
	}else{
		printf("Non esiste un numero di Amstrong");
	}
	
	return 0;
}

int numeroAmstrong(int n){
	int tmp, tmp2, cifre, somma, i;
	cifre=1;
	somma = 0;
	tmp = n;
	while(tmp>0){
		tmp/=10;
		cifre++;
	}
	
	while(n>0){
		tmp = n - (n/10)*10;
		for(i=0; i<cifre; i++){
			tmp2*=tmp;
		}
		somma+=tmp2;
	}
	
	return (somma==n);
}