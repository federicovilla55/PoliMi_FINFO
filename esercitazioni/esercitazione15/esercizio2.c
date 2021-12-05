#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SMAX 100
typedef struct{
    char *cognome;
    char *nome;
    char sesso;
    int anno;
} Persona;

Persona input_persona();
char *dup_string(char *s);
void stampa_persona(Persona *p);
Persona *clona_persona(Persona *p);
void free_persona(Persona *p);

int main(){
    Persona p1;
    Persona *p2;
    p1 = input_persona();
    p2 = clona_persona(&p1);
    if(p2 != NULL){
        p2->anno = 1995;
        p2->nome[0] = 'A';
        stampa_persona(&p1);
        stampa_persona(p2);

        free_persona(p2);
        p2 = NULL;
    }

    free(p1.nome);
	p1.nome=NULL;
	free(p1.cognome);
	p1.cognome=NULL;

	return 0;

}

Persona input_persona(){
	Persona p;
	char str[SMAX + 1];
	printf("Nome: ");
	scanf("%s", str);
	p.nome = dup_string(str);
	/*il nome in str viene copiato in p.nome con l'utilizzo 
	 * dei soli byte strettamente necessari*/
	printf("Cognome: ");
	scanf("%s", str);
	p.cognome = dup_string(str);
	printf("Sesso (M/F): ");
	scanf(" %c", &p.sesso); 
	/*Lo spazio nella scanf per svuotare il buffer*/
	printf("Anno di nascita: ");
	scanf("%d", &p.anno);
	return p;
}

void stampa_persona(Persona *p){
	printf("%s %s %c %d \n", p->nome, p->cognome, p->sesso, p->anno);
	/*Poiche' si e' passato un puntatore e' necessario usare 
	 * per accedere ai campi la notazione: " -> " */
}

char *dup_string(char *s){
    char *d = malloc((strlen(s) + 1) * sizeof(char));
    if(d==NULL){
        return NULL;
    }
    strcpy(d, s);
    return d;
}

Persona *clona_persona(Persona *p){
    Persona *np = (Persona *) malloc(sizeof(Persona));
    if(np == NULL){
        return NULL;
    }
    np->cognome = dup_string(p->cognome);
    np->nome = dup_string(p->nome);
    np->sesso = p->sesso;
    np->anno = p->anno;
    return np;
}

void free_persona(Persona *p){
    free(p->cognome);
    free(p->nome);
    free(p);    
}