#include<stdio.h>
#include<string.h>
#define N 30
typedef struct persona{
	char cognome[N+1];
	char nome[N+1];
	char sesso[2];
	int anno;
}Persona;

void stampaPersona(Persona *p);
int main(){
	char cognome[N+1];
	FILE *fp;
	int cont;
	Persona p;

	printf("Inserire cognome da cercare: ");
	scanf("%s", cognome);

	fp=fopen("persone.dat", "rb");
	
	if(fp){
		cont = 0;
		while(fread(&p, sizeof(Persona), 1, fp)>0){
			if(p.cognome == cognome){
				cont++;
				stampaPersona(&p);
			}
		}
		printf("Trovate %d persone con cognome %s\n", cont, cognome);
		fclose(fp);
	}else{
		printf("Errore\n");
	}

	return 0;
}

void stampaPersona(Persona *p){
	printf("%s - %s - %s - %d\n", p->nome, p->cognome, (*p).sesso, p->anno);
}
