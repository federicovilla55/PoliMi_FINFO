/* Scrivere un programma apre in lettura un file di testo "ciao.bin". Il programma legge
 * la sequenza di valori interi salvati nel file (la cui lunghezza non è nota a priori) e la
 * visualizza.  */

#include<stdio.h>

int main(){
	FILE *fp;
	int n;
	fp = fopen("ciao.bin", "rb");
	
	if(fp){
		while(fread(&n, sizeof(int), 1, fp)>0){
			printf("Numero: %d\n", n);
		}


		fclose(fp);
	}

	return 0;
}
