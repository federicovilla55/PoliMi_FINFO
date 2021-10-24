/* Data una matrice NxN con N costante, leggere i
 * dati da input, ruotare di 90 gradi in senso
 * antiorario la matrice e stampare il risultato  */
#include<stdio.h>
#define N 3
int main(){
	int varRiempie=1;
	int mat[N][N], i , j, mid, temp;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			mat[i][j]=(++varRiempie)*(j+1)*(i+1);
		}
	}
	/*Stampa di prova della matrice*/
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			 printf("%d ", mat[i][j]);
		}
		printf("\n");
	}

	printf("\n\n");

	if(N%2==0)
		mid =N/2;
	else
		mid = (N/2) +1;

	for(i=0; i<N; i++){
		for(j=N-i; j<N; j++){
			temp = mat[i][j];
			mat[i][j] = mat[N-1-j][i];
			mat[N-1-j][i] = temp;
		}
	}

	for(i=0; i<N; i++){
		for(j=0; j<N; j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}
	return 0;
}
