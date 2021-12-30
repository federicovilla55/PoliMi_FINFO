#include <stdio.h> 

#define DIM 6

int sommaCornice(int mat[][DIM], int span);
int corniceMax(int mat[][DIM], int dim);

int main(){
	int j, i, mat[DIM][DIM];
	printf("Riempi una matrice %dx%d:\n", DIM, DIM);
	for(i=0; i<DIM; i++)
		for(j=0; j<DIM; j++)
			scanf("%d", &mat[i][j]);

	printf("Somma cornice esterna: %d\n", sommaCornice(mat, 0));
	printf("Cornice con somma massima: %d \n", corniceMax(mat, DIM));
	return 0;
}

int sommaCornice(int mat[][DIM], int span){
	int ris, i;
	ris = 0;
	for(i=span; i<DIM-span; i++){
		ris += (mat[span][i] + mat[DIM-1-span][i]);
		if(i > span && i< (DIM-(span+1)))
			ris += (mat[i][span] + mat[i][DIM-1-span]);
		printf("ris: %d \n", ris);
	}

	return ris;
}

int corniceMax(int mat[][DIM], int dim){
	int max, i, n, tmp;

	if(dim%2)
		n= dim/2;
	else
		n= (dim/2) - 1;

	tmp = 0;
	max = sommaCornice(mat, 0);

	for(i=0; i<n; i++){
		if(max <=sommaCornice(mat, i))
			tmp = i;
	}

	return tmp;
}
