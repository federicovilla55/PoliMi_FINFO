/* Scrivere un programma che apre in scrittura un file binario "ciao.bin". Il programma
 * chiede all'utente quanti valori vuole acquisire da tastiera, e poi procede con
 * l'acquisizione da tastiera della serie di numeri ed il loro salvataggio nel file.  */
#include<stdio.h>
int main(){
	FILE *fp;
	int n, num;
	fp=fopen("ciao.bin", "wb");

	if(fp){
		printf("Dimmi quanti valori vuoi inserire: ");
		scanf("%d", &n);
		for(;n>0; n--){
			printf("Dimmi un valore: ");
			scanf("%d", &num);
			fwrite(&num, sizeof(int), 1, fp);
		}
		fclose(fp);
	}

	return 0;
}
