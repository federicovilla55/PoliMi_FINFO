#include<stdio.h>
int main(){
	int ris, b50, b20, b10, b5;
	scanf("%d%d%d%d", &b50, &b20, &b10, &b5);
	ris= b50*50 + b20*20 + b10*10 + b5*5;
	printf("La somma complessiva dei soldi nel portafoglio e': %d\n", ris);
	return 0;
}
