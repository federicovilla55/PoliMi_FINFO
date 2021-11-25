#include<stdio.h>
#include<string.h>
#define MAX_PERSONE 30
#define N 30
#define MAX_STRINGA 30

typedef struct{
	char cognome[N+1];
	char nome[N+1];
	char sesso[2];
	int anno;
} Persona;
Persona input_persona();
void popola_file(char *nome_file);
void leggi_file(char *nome_file, Persona p_arr[], int max);

int main(){
	
	Persona persone[MAX_PERSONE];
	char file_path[MAX_STRINGA];
	char mode[2];
	
	printf("Inserire il nome del file da utilizzare: ");
	scanf("%s", file_path);
	printf("Inserire una modalita' (w / r)): ");
	scanf("%s", mode);

	if(!strcmp(mode, "w")){
		printf("Popola\n");
		popola_file(file_path);
	} else if(!strcmp(mode, "r")){
		printf("Leggi\n");
		leggi_file(file_path, persone, MAX_PERSONE);
	}else{
		printf("Non hai inserito una modalita' valida");
	}
	return 0;	
}

Persona input_persona(){
	Persona p;
	printf("Dimmi nome, cognome, sesso e anno di una persona: \n");
	scanf("%s", p.nome);
	scanf("%s", p.cognome);
	scanf("%s", p.sesso);
	scanf("%d", &p.anno);
	
	return p;
}

void popola_file(char *nome_file){
	Persona tmp_p;
	FILE* f;
	int risp, i;
	i = 0;
	/* ris e' una variabile per indicare il numero di persone realmente inserite */
	risp = 1;
	f = fopen(nome_file, "wb");

	if(f){

		while(risp != 0 && i<MAX_PERSON && i<MAX_PERSONE){
			tmp_p = input_persona();
			fwrite(&tmp_p, sizeof(Persona), 1, f);
			printf("Continuare? (1 == si)");
			scanf("%d", &risp);
			i++;
		}
		fclose(fp);
	}else{
		printf("Errore");
		return;
	}
}

void leggi_file(char *nome_file, Persona p_arr[], int max){
	FILE *f;
	int n, i;

	f = fopen(nome_file, "rb");
	if(!f){
		printf("Errore apertura file\n");
		return; 
	}
	n = fread(p_arr, sizeof(Persona), max, f);
	fclose(fc);
	return;
}
