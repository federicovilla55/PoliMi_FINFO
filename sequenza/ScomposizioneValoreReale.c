#include<stdio.h>
int main(){
	float val, parteFraz;
	int parteInt;
	scanf("%f",&val);
	parteInt = val;
	parteFraz = val - parteInt;
	printf("Parte intera: %d, Parte frazionaria: %f\n", parteInt, parteFraz);
	return 0; 
}
