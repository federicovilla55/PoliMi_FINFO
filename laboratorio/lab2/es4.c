/*Matrici massimo locali
 * Scrivere un programma in linguaggio C che legga in input una
 * matrice A quadrata N x N
 * il programma deve cercare tutti i massimi locali (ossia i valori
 * che sono il massimo delle celle adiacenti) e sostituirli con zero.
 * (oss: ne caso di riga/colonna 0, si consideri la posizione N-1, sia
 * dall’ alto lato)*/
#include<stdio.h>
#define N 4
int main(){
	int i, j, A[N][N];
	int ris;
	printf("Riempi la matrice %dX%d\n", N, N);
        for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			scanf("%d", &A[i][j]);		
		}
	}

	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			ris=0;
			if(i==0){
				ris = A[i][j]>A[i+1][j] && A[i][j]>A[N-1][j];	
			}else{
				if(i==(N-1)){
					ris = A[i][j]>A[i-1][j] && A[i][j]>A[0][j];	
				}else{
					ris = A[i][j]>A[i+1][j] && A[i][j]>A[i-1][j];
				}
			}
			if(j==0){
				ris = ris && A[i][j]>A[i][j+1] && A[i][j]>A[i][N-1];
			}else{
				if(j==N-1){
					ris = ris && A[i][j]>A[i][j-1] && A[i][j]>A[i][0];
				}else{
					ris = ris && A[i][j]>A[i][j+1] && A[i][j]>A[i][j-1];
				}
			}
			if(i==1){
				i=1;
			}
			if(ris){
				A[i][j]=0;
				j++;
			}
		}
	}
	printf("Ecco la matrice con 0 al posto dei massimi locali:\n");
	for(i=0; i<N; i++){
		for(j=0; j<N; j++)
			printf("%d ", A[i][j]);
		printf("\n");
	}
	return 0;
}
