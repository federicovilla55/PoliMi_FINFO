/* Scrivere un programma che chiede all'utente 10 valori interi da salvare in un array. In
 * seguito, il programma apre in scrittura un file binario "ciao.bin" e vi scrive il contenuto
 * dell'array.  */
#include<stdio.h>
#define DIM 10
int main(){
	int v[DIM], i;
	FILE *fp;
	fp = fopen("ciao.bin", "wb");

	if(fp){
		for(i=0; i<DIM; i++){
			printf("Dimmi un valore: ");
			scanf("%d", &v[i]);
		}

		fwrite(v, sizeof(int), DIM, fp);
		fclose(fp);

	}else{
		printf("Errore apertura file\n");
	}

	return 0;
}
