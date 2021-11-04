#include<stdio.h>
#define N_CONCESSIONARI 10
#define MAX_STR 30
#define MAX_TRG 7
#define MAX_AUTO_CONCE 50

typedef struct{
	char modello[MAX_STR + 1], targa[MAX_TRG + 1];
	int meseImmatricolazione, annoImmatricolazione;
}t_auto;

typedef struct{
	char pIva[MAX_STR +1];
	char nome[MAX_STR +1], cognome[MAX_STR +1];
}t_persona;

typedef struct{
	int codiceConcessionario;
	t_persona gestore;
	t_auto autom[MAX_AUTO_CONCE];
	int nAuto;
}t_concessionario;

void stampa(t_concessionario c[], int dim, int anno);

void stampa(t_concessioanrio c[], int dim, int anno){
	int i, j, trovato;
	for(i=0; i<dim; i++){
		trovato=0;
		printf("Conc. %d, Codice %d: Gestore %s %s\n ", i, c[i].codiceConcessionario, c[i].gestore.nome, c[i].gestore.cognome);
		printf("Immatricolazioni anno %d:\n", anno);
		for(j=0; j<c[i].nAuto; j++){
			if(c[i].autom[j].annoImmatricolazione == anno){
				pritnf("* Mese %d: Modello %s, Targa %s\n", c[i].autom[j].meseImmatricolazione, c[i].autom[j].targa, c[i].autom[j].targa);
				trovato = 1;
			}
		}
		if(!trovato)
			printf("NESSUNA\n");
	}
}
