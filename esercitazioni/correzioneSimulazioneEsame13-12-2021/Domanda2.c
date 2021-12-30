#include <stdio.h>  

#define M 4
#define N 3

int r0(int [][N], int [][N], int, int);

int main(){
	int i, j, nr;
	int mat[M][N], nuova[M][N];

	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			scanf("%d", &mat[i][j]);
		}
	}

	nr = r0(mat, nuova, M, N);

	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			printf("%d ", nuova[i][j]);
		}
		printf("\n");
	}

	return 0;
}

int r0(int mat[][N], int new[][N], int dimr, int dimc){
	int i, j, k, cont;
	cont = 0;

	for(i=dimr-1; i>=0; i--){
		for(j=0; j<dimc; j++){
			new[dimr-i-1][j] = mat[i][j];
		}
	}
	j=0; 
	for(i=0; i<dimr; i++){
		if(new[i][j] == 0){
			cont++;
			for(k=0; k<dimc; k++){
				new[i][k] = 0;
			}
		}
	}

	return count;
}

/* Errori frequenti:
 * - sbagliare a restutire la matrice;
 * - mancanza dell'inizializzazione della nuova matrice
 * - sbagliare la lettura/scrittura della matrice
 * - sbagliare la matrice 
 * - fare 4 cicli annidati per invertire la matrice
 */
