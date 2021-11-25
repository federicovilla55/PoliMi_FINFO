#include<stdio.h>
#include<math.h>

typedef struct{
	float im;
	float re;
} complesso_t;

int main(){
	complesso_t z[2], somma;
	float f1, f2;
	printf("Dimmi due numeri complessi: ");
	scanf("%f %f %f %f", &z[0].re, &z[0].im, &z[1].re, &z[1].im);

	somma.im = z[0].im + z[1].im;
	somma.re = z[0].re + z[1].re;

	printf("Il numero complesso somma: %f %f\n", somma.re, somma.im);

	f1 = atan(z[0].im/z[0].re);
	f2 = atan(z[1].im/z[1].re);

	if(f1 == f2)
		printf("I due numeri complessi sono uguali in fase\n");

}
