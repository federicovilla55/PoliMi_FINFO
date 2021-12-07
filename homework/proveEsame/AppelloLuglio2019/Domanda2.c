/*Scrivere un sottoprogramma che riceve in ingresso un array bidimensionale di interi mat, un intero val
e qualsiasi parametro ritenuto strettamente necessario e trasmette al chiamante gli indici di riga e
colonna che identificano la posizione del primo elemento (scandendo l’array per righe) che, sommato a
tutti i suoi precedenti, dia come risultato un valore > val. Nel caso in cui tal elemento non esista, si
trasmettono i valori -1, -1. Esiste una direttiva #define NCOL 10.*/

#include<stdio.h>

#define NCOL 10
#define NRIG 20

void sommaPrec(int mat[][NCOL], int val, int *rig, int *col);

int main(){
	int a[NRIG][NCOL];
	int i, j, val;

	/* Inizializzazione Matrice e Val */
	val = 5;
	for(i=0; i<NRIG; i++)
		for(j=0; j<NCOL; j++)
			a[i][j]=i+j+1;

	/* Fine inizializzazione */
	
	sommaPrec(a, val, &i, &j);
	
	printf("Gli indici minimi voluti sono: %d e %d\n", i, j);
	
	return 0;
}

void sommaPrec(int mat[][NCOL], int val, int *rig, int *col){
	int i, j, sum, ris;
	i=0; 
	j=0;
	sum = 0;
	ris = -1;
	for(i=0; i<*rig && ris==-1; i++){
		for(j=0; j<*col && ris==-1; j++){
			sum += mat[i][j];
			if(sum > val){
				*rig = i;
				*col = j;
				ris = 1;
			}
		}
	}
	if(ris==-1){
		*rig = -1;
		*col = -1;
	}
}
