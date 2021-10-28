/*Matrici
 * Scrivere un programma che usi due matrici NxN, dette A e AT.
 * L’ utente inserisce i valori di A e il programma riempie AT in
 * modo
 * che sia la Trasposta di A (e la stampi).
 * https://it.wikipedia.org/wiki/Matrice_trasposta*/

#include<stdio.h>
#define N 3
#define M 4
int main(){
	int A[M][N], AT[N][M];
	int i, j;
	
	printf("Dimmi i valori di una matrice %dx%d:\n", M, N);
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			scanf("%d", &A[i][j]);
		}
	}

	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			AT[j][i]=A[i][j];		
		}
	}

	printf("\nEcco la matrice trasposta: \n");

	for(i=0; i<N; i++){
		for(j=0; j<M; j++)
			printf("%d ", AT[i][j]);
		printf("\n");
	}
	return 0;
}
