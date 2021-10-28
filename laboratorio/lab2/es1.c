/*Matrici: scrivere un programma che legga in input dei numeri float e riempia una matrice 4x4
 * il programma deve stamapre gli elementi sulla diagonale principale*/

#include<stdio.h>
#define DIM 4
int main(){
	int i, j;
	int mat[DIM][DIM];

	printf("Dimmi il contenuto di una matrice %dx%d: \n", DIM, DIM);
	for (i=0; i<DIM; i++){
		for(j=0; j<DIM; j++){
			scanf("%d", &mat[i][j]);
		}
	}

	printf("Gli elementi sulla diagonale principale sono: ");
	for(i=0; i<DIM; i++){
		for(j=0; j<DIM; j++){
			if(j==i)
				printf("%d ", mat[i][j]);
		}
	}

	return 0;
}
