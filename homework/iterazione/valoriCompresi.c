#include<stdio.h>
int main(){
	int a, b, ris;
	ris = 0;
	scanf("%d %d", &a, &b);
	if (a>b){
		while(a>=b){
			ris+=a--;
		}
	}else{
		while(b>=a){
			ris+=b--;
		}
	}
	printf("Somma Valori Compresi: %d\n", ris);
	return 0;

}
