/*Scrivere un istogramma in C che chiede all'utente 5 valori interi non negativi 
 * e ne disegna l'istogramma a barre verticali */
#include<stdio.h>
#define DIM 5
int main(){
	int arr[DIM], max, i, j;
	max=0;
	for(i=0; i<DIM; i++)
	{
		do{
			scanf("%d", &arr[i]);
		}while(arr[i]<0);
		if(arr[i]>max)
			max=arr[i];
	}
	for(i=0; i<max; i++){
		for(j=0; j<DIM; j++){
			if(arr[j]==max-i){
				printf(" * ");
				arr[j]--;
			}else{
				printf("   ");
			}
		}
		printf("\n");
	}
	return 0;
	/*
	 * #define N 5
	 * int h[N];
	 * int i;
	 * for(i=0; i<N; i++)
	 * 	scanf("%d", &h[i]);
	 * 
	 * */
}
