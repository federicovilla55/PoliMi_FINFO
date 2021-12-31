#include <stdio.h> 
#define NC 3
#define NR 3
void vicino(int mat[][NC], int ris[NC], int nrig);
int main(void){
	int mat[NR][NC], ris[NC], i, j;

	for(i=0; i<NR; i++){
		for(j=0; j<NC; j++){
			scanf("%d", &mat[i][j]);
		}
	}

	vicino(mat, ris, i);

	for(i=0; i<NC; i++)
		printf("%d \n", ris[i]);

	return 0;
}

void vicino(int mat[][NC], int ris[NC], int nrig){
	int i, j, max, qmax;

	for(i=0; i<NC; i++){
		max = mat[0][i];
		qmax = 0;
		for(j=1; j<nrig; j++){
			if(mat[j][i] > max){
				qmax = max;
				max = mat[j][i];	
			}
			if(max > mat[j][i] && qmax < mat[j][i])
				qmax = mat[j][i];
		}
		ris[i] = qmax;
	}
}
