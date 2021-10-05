#include<stdio.h>
#define PI 3.14
int main(){
	float r, area, perimetro;
	scanf("%f",&r);
	area=r*r*PI;
	perimetro=2*r*PI;
	printf("L'area del cerchio e': %f\nIl perimetro e': %f\n", area, perimetro);
	return 0;
}
