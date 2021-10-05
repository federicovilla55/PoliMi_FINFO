#include<stdio.h>
int main(){
	float a, b, ris;
	scanf("%f%f",&a, &b);
	if (a == 0 && b==0)
		printf("Equazione indeterminata\n");
	else if (a==0 && b!=0)
		printf("Equazione Impossibile\n");
	else{
		ris = -b/a;
		printf("La soluzione dell'equazione e': %f\n", ris);
	}
	return 0;
}
