/* Esercizio 3  */

#include<stdio.h>
#define DIM 30

typedef struct{
	char nome[DIM + 1];
	char cognome[DIM + 1];
	char sesso;
	int anno;
} persone_t;

int main(){
	FILE *fp;
	int n, min, minIndex;
	min = 2021;
	persone_t p[DIM];

	fp = fopen("persone.txt", "r");
	
	if(fp != NULL){
		fscanf(fp, "%d", &n);
		for(i = 0; i < n; i++){
			if(fscanf(fp, "%s %s %c %d", p[i].nome, p[i].cognome, &p[i].sesso, &p[i].anno)>0){
				if(p[i].anno<min){
					minIndex = i;
				}
			}
		}
	}
	
	printf("Indice minore: %d\n", minIndex);

	return 0;
}
