/* Scrivere un programma apre in lettura un file di testo "ciao.bin" che contiene 10
 * valori interi. Il programma legge i valori e verifica che siano stati letti tutti
 * correttamente. In caso affermativo li visualizza altrimenti segnala l'errore.  */
#include<stdio.h>
#define DIM 10
int main(){
	int v[DIM], i;
	FILE *fp;
	fp = fopen("ciao.bin", "rb");
	
	if(fp){
		fread(v, sizeof(int), DIM, fp);

		for(i=0; i<DIM; i++){
			printf("Numero: %d\n", v[i]);
		}

		fclose(fp);
	}

	return 0;
}
