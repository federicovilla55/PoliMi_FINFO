#include<stdio.h>
#define N_MAX 30
#define LUNG_STRINGA 30
#define ANNO_CORRENTE 2021

typedef struct{
	char cognome[LUNG_STRINGA];
	char nome[LUNG_STRINGA];
	char sesso[2];
	int anno;
}persona_t;

persona_t get_youngest(Persona persone[], int numPersona);

int main(){

	FILE* file;
	int numPersone;
	Persona persone[N_MAX];
	Persona personaCorrente, personaYoungest;
	int i;

	file = fopen("persone.txt", "r");
	
	if (file != NULL){
		fscanf(file, "%d", &numPersone);

		for(i = 0; i<numPersone; i++){
			if(fscanf(file, "%s %s %s %d", persone[i].nome, persone[i].cognome, persone[i].sesso, &persone[i].anno)>0)		
		}
		fclose(file);

		personaYoungest(persone, numPersone);

		printf("La persona più giovane e': %s %s (%d)\n", personaYoungest.nome, personaYoungest.cognome, ANNO_CORRENTE - personaYoungest.anno);

	}else
		printf("Errore, file non trovato");
	

	return 0;
}

Persona get_youngest(Persona persone[], int numPersone){
	Persona youngest;
	int i; 
	youngest = persone[0];

	for(i=1; i<numPersone; i++){
		if(persone[i].anno > youngest.anno){
			youngest = persone[i];
		}
	}
	
	return youngest;
}
