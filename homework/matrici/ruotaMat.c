/* Data una matrice NxN con N costante, leggere i
 * dati da input, ruotare di 90 gradi in senso
 * antiorario la matrice e stampare il risultato  */
#include<stdio.h>
#define N 3
int main(){
        int varRiempie=1, nmat[N][N];
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
        
	for(i=0; i<N; i++){
                for(j=0; j<N; j++){
                	temp = mat[i][j];
                        mat[i][j]=nmat[N-1-j][i];
                        nmat[N-j-1][i]=temp;
                }
                printf("\n");
        }

        for(i=0; i<N; i++){
                for(j=0; j<N; j++)
                        printf("%d ", nmat[i][j]);
                printf("\n");
        }
        return 0;
}
