#include<stdio.h>
#define DIM 5
int main(){
	int arr[DIM], i, max, qmax;
	for (i=0; i<DIM; i++){
		do{
			scanf("%d", &arr[i]);
		}while(arr[i]<=0);
	}
	max = 0;
	qmax = 0;
	for(i=0; i<DIM; i++){
		if(arr[i]>max){
			if(max>qmax)
				qmax=max;
			max=arr[i];
		}else{
			if (arr[i]>qmax)
				qmax=arr[i];
		}
	}
	printf("Massimo: %d e Quasi Massimo: %d\n", max, qmax);
	return 0;
}
