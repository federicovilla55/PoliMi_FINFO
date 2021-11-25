#include<stdio.h>
#include<math.h>
#define MAX 5

typedef struct{
	float re;
	float im;
} complex;

int main(){
	complex valori[MAX];
	int i, max, min;
	/* Modulo numero complesso e': sqrt(x1*x1 + x2*x2) */

	printf("Dimmi %d numeri complessi: \n", MAX);

	for(i=0; i<MAX; i++){
		scanf("%f %f", &valori[i].re, &valori[i].im);
	}
	max=0;
	min=0;
	

	for(i=1; i<MAX; i++){
		if((valori[i].re*valori[i].re)+(valori[i].im*valori[i].im)>(valori[max].re*valori[max].re)+(valori[max].im*valori[max].im)){
				max = i;		
		}
		if(atan(valori[i].im/valori[i].re) > atan(valori[min].im/valori[min].re)){
			min = i;
		}
	}

	printf("Il valore complesso con modulo massimo e': %f %f\n", valori[max].re, valori[max].im);
       	printf("Il valore complesso con fase minore e': %f %f\n", valori[min].re, valori[min].im);
	return 0;	
}
