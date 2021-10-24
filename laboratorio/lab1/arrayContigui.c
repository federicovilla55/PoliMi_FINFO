/* Scrivere un programma ceh legga da input due array di 10 elementi e B di 5 elementi
 * il programma stampi: "CONTIENE" se A contiene la sequenza contigua di B.  */
#include<stdio.h>
#define DIMA 10
#define DIMB 5
int main(){
	int a[DIMA], b[DIMB], i, j, contiene;
	for(i=0; i<DIMA; i++)
		scanf("%d", &a[i]);
	for(i=0; i<DIMB; i++)
		scanf("%d", &b[i]);
	for(i=0; i<DIMA && contiene!=5; i++){
		contiene=0;
		for(j=0; j<DIMB &&a[j+i]==b[j]; j++){
				contiene++;
		}
	}
	if(contiene==5)
		printf("CONTIENE\n");
	else
		printf("NON CONTIENE\n");
	return 0;
}
