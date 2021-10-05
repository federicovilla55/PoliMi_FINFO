#include<stdio.h>
int main(){
	float tempC, tempF;
	scanf("%f", &tempC);
	tempF = (tempC * 1.8) + 32;
	printf("La temperatura in gradi Fahrenheit e' %f\n", tempF);
	return 0;
}
