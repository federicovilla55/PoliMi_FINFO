#include<stdio.h>
#define NAME_DIM 30

int main(){
	FILE *fp;
	char nome[NAME_DIM];
	int num, n;

	printf("Dimmi il nome del file da aprire: ");
	scanf("%s", nome);
	fp = fopen(nome, "w");

	if(fp){
		printf("Dimmi quanti valori vuoi acquisire da tastiera: ");
		scanf("%d", &n);

		for(; n>0; n--){
			printf("Dimmi un valore: ");
			scanf("%d", &num);
			fprintf(fp, "%d ", num);
		}

		fclose(fp);
	}
	return 0;
}
