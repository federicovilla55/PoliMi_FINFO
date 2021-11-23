#include<stdio.h>
#include<string.h>

#define MAX_LEN 30

/* Con la funzione rewind(FILE *stream); e' possibile tornare all'inizio di un file */
int ricercaQuantita(char ingrediente[], FILE *fp);
int main(){
	FILE *fp;
	int n_persone, quantita;
	char temp[MAX_LEN];

	fp = fopen("ingredienti.txt", "r");

	if(fp){
		printf("Per quante persone vuoi cucinare?\n");
		scanf("%d", &n_persone);

		printf("Dimmi un ingrediente: ");
		scanf("%s", temp);

		while(strcmp(temp, "stop") != 0){
			quantita = n_persone * ricercaQuantita(temp, fp);
			if(quantita > 0)
				printf("%d ", quantita);
			else
				printf("Ingrediente non trovato\n");

			printf("Dimmi un ingrediente: ");
			scanf("%s", temp);
			
			rewind(fp);
		
		}
		fclose(fp);
	}else{
		printf("Errore apertura file\n");
	}

	return 0;
}

int ricercaQuantita(char ingrediente[], FILE *fp){
	char temp[MAX_LEN + 1];
	int quantita, trovato, quantita_giusta;
	trovato = 0;

	fscanf(fp, "%s %d", temp, &quantita);
	while(!feof(fp) && !trovato){
		if(strcmp(temp, ingrediente) == 0){
			trovato = 1;
			quantita_giusta = quantita;
		}
		fscanf(fp, "%s %d", temp, &quantita);
	}
	if(trovato)
		return quantita_giusta;
	else
		return 0;
}
