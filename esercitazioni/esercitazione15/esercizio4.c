/* malloc2d
 * Si scriva una funzione malloc2d, in grado di allocare una matrice 
 * rettangolare di numeri reali (tipo float), le cui dimensioni sono ricevute come 
 * parametri. La matrice viene inizializzata azzerando tutte le caselle */
#include<stdio.h>
#include<stdlib.h>

float *malloc2d(int m, int n);

int main(){
	int i, j, m, n;
	float *p;
	printf("Dimmi le dimensioni della matrice rettangolare: ");
	scanf("%d %d", &m, &n);

	p = malloc2d(m, n);

	printf("Ecco la matrice %dx%d allocata con malloc2d: \n", m, n);
	for(i=0; i<m; i++){
		for(j=0; j<n; j++)
			printf("%f ", *(p+j+(i*n)));
		printf("\n");
	}

	free(p);	
	p = NULL;
	return 0;
}

float *malloc2d(int m, int n){
	int i, j;
	float *p;

	p = malloc(sizeof(int) * (m*n));

	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
			*(p+j+(i*n)) = 0;


	return p;
}
