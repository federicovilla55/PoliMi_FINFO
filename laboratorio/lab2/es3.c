/*Matrici
 * Scrivere un programma in linguaggio C che legga in input due
 * matrici 4x4, dette A e B
 * il programma deve stampare tutti gli indici riga/colonna che
 * dove
 * le celle di A hanno lo stesso valore delle celle di B nelle posizioni
 * corrispondenti*/
#include<stdio.h>
#define DIM 4
int main(){
	int i, j , A[DIM][DIM], B[DIM][DIM];
	printf("Dimmi i valori della prima matrice:\n");
	for(i=0; i<DIM; i++){
		for(j=0; j<DIM; j++){
			scanf("%d", &A[i][j]);
		}
	}
	printf("Dimmi i valori della seconda matrice:\n");
        for(i=0; i<DIM; i++){
		for(j=0; j<DIM; j++){
			scanf("%d", &B[i][j]);
		}
	}

	printf("\nGli elementi con lo stesso valore e posizione si trovano in:\");
        for(i=0; i<DIM; i++){
 		for(j=0; j<DIM; j++){
 			if(A[i][j] == B[i][j])
				printf("(%d, %d)\n", i, j);
		}
	}
	return 0;
}
