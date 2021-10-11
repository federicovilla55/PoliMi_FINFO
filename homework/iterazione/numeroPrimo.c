#include<stdio.h>
int main(){
	int i, n, primo;
	primo = 1;
	do{
		scanf("%d",&n);
	}while(n<1);
	for(i=2; i<n && primo; i++){
		if(n%i==0){
			primo = 0;
			printf("Il numero NON e' primo\n");
		}
	}
	if (primo == 1)
		printf("Il numero e' primo\n");
	return 0;
}
