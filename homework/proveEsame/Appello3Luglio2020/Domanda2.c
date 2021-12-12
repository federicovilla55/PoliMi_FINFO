#include <stdio.h>  
#define DIM 3

void numeroNarcisistico(int a[], int b[], int dim);

int main(){
	
	int a[DIM], b[DIM], i;

	printf("Riempi un array di %d elementi: ", DIM);
	for(i=0; i<DIM; i++)
		scanf("%d", &a[i]);
	
	numeroNarcisistico(a, b, DIM);

	for(i=0; i<DIM; i++){
		if(b[i]==1)
			printf("%d e' un numero narcisistico\n", a[i]);
	}

	return 0;
}

void numeroNarcisistico(int a[], int b[], int dim){
	int i, j, tmp, cifra, c;
	
	for(i=0; i<DIM; i++){
		c=0;
		cifra=a[i];
		while(cifra>0){
			j =  cifra - ((cifra/10)*10);
			c += j*j*j*j;
			cifra/=10;
		}
		if(c==a[i])
			b[i]=1;
		else
			b[i]=0;

	}

}

/* Due esempi di numeri narcisistici sono 1634 e 0. */
