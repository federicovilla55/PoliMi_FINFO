#include<stdio.h>
#define DIM 30
typedef struct{
	int numeroMatricola;
	char nome[DIM];
	char cognome[DIM];
	int parteA, parteB;
} t_studenti

int main(){
	t_studenti s[DIM];
	int i, min, max, media;
	min=15;
	max=0;
	media=0;
	for(i=0; i<DIM; i++){
		do{
			scanf("%d %s %s %d %d", s[i].numeroMatriocla, s[i].nome, s[i].cognome, s[i].parteA, s[i].parteB);
		}while(s[i].parteA<=15 && s[i].parteB>=0 && s[i].parteB <=15 && s[i].parteB >=0);
		if(max < 
	}
}
