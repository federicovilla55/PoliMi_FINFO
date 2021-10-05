#include<stdio.h>
int main(){
	float val, ris;
	scanf("%f",&val);
	ris = val;
	scanf("%f",&val);
	ris += val;
	ris /= 2;
	printf("La media dei due valori e' %f\n", ris);
	return 0;
}
