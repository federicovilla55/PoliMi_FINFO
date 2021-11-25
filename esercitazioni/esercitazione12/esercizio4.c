/* Scrivere un programma che mostri all’utente le quantità degli ingredienti di una ricetta.
 * Gli ingredienti e le relative quantità per una persona sono contenuti nel file “ingredienti.txt”. 
 * Il programma dovrà prima di tutto richiedere all’utente il numero di persone per cui cucinare.
 * Successivamente, dovrà ricevere in input il nome dell’ingrediente da ricercare e
 * mostrarne la relativa quantità. Il programma termina quando l’utente inserisce la stringa “stop”.
 * Es ingredienti.txt
 * farina 100
 * zucchero 50
 * lievito 3*/

#include<stdio.h>
#include<string.h>
#define DIM 30

typedef struct{
	char nome[DIM];
	int n;
} ingredienti_t;

int main(){
	FILE *fp;
	ingredienti_t ric[DIM];
	char s[DIM];
	int i, numP, quant, c;
	fp=fopen("ingredienti.txt", "r");
	if(fp){
		printf("Dimmi il numero di persone per cui cucinare: ");
		scanf("%d", &numP);
		c=0;
		while(fscanf(fp, "%s %d", ric[c].nome, &ric[c].n)>0){
			c++;
		}

		do{
			printf("Dimmi un ingrediente: ");
			scanf("%s", s);
			
			if(strcmp(s, "stop")){
				for(i=0; i<c; i++){
					if(!strcmp(s, ric[i].nome))
						printf("Ingrediente: %s, %d grammi\n", s, (ric[i].n*numP));
				}
			}

		}while(strcmp(s, "stop")!=0);

	}else{
		printf("Errore apertura File\n");
	}

	return 0;
}
