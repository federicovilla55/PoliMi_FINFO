#include<stdio.h>

void print_uanrio(int n);
void abaco_rec(int n);

int main(){
	int n;

	do{
		printf("Inserire un numero, 0 per terminare: ");
		scanf("%d", &n);

		if(n!=0){
			abaco_rec(n);
		}
	}while(n != 0);
	
	return 0;
}

void abaco_rec(int n){
	if(n <= 0){
		return;
	}else{
		abaco_rec(n/10);
		print_unario(n%10);
		return;

		/*Invertendo le due funzioni l'abaco viene stampato al contrario*/
	}
}

void print_unario(int n){
	if(n == 0){
		printf("\n");
	}else{
		printf("o");
		print_uanrio(n-1);
	}

	return;
}
