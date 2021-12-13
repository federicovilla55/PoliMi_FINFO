#include <stdio.h> 

#define M 4
#define N 3

int creaMatrice(int mat[M][N], int new[M][N]);

int main(){
	int i, j, numRighe;

	int mat[M][N], new[M][N];
	printf("Riempi la matrice di partenza %dx%d: \n", M, N);
	for(i=0; i<M; i++)
		for(j=0; j<N; j++)
			scanf("%d", &mat[i][j]);

	numRighe = creaMatrice(mat, new);
	
	printf("Ecco il risultato: \n");	
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			printf("%d ", new[i][j]);
		}
		printf("\n");
	}

	return 0;
}

int creaMatrice(int mat[M][N], int new[M][N]){
	int i, j, numAzzeramenti;
	numAzzeramenti=0;
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			if(mat[i][0]==0)
				new[M-i-1][j]=0;
			else
				new[M-i-1][j] = mat[i][j];
		}
		if(mat[i][0]==0)
			numAzzeramenti++;
	}

	return numAzzeramenti;

}
