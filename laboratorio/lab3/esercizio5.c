#include<stdio.h>
#define MAX 3
#define DIM 30
#define NUM_ESAMI 3
typedef struct{
	char nomeEsame[DIM];
	int voto;
} Exam;

typedef struct{
	int codicePersona;
	Exam esami[NUM_ESAMI];
} Student;

int main(){
	Student s[MAX], mediaAlta;
	int i, j, codPersona, tmp, media;
	printf("Dimmi %d dati di studenti: \n", MAX);

	for(i=0; i<MAX; i++){
		scanf("%d", &s[i].codicePersona);
		for(j=0; j<NUM_ESAMI; j++){
			do{
				scanf("%s %d", s[i].esami[j].nomeEsame, &s[i].esami[j].voto);
			}while(s[i].esami[j].voto < 1 || s[i].esami[j].voto > 30);
		}
	}

	printf("Dimmi un codice persona: ");
	scanf("%d", &codPersona);

	for(i=0; i<MAX; i++){
		if(codPersona == s[i].codicePersona)
			for(j=0; j<NUM_ESAMI; j++){
				printf("Esame di %s, voto %d\n", s[i].esami[j].nomeEsame, s[i].esami[j].voto);
			}
	}

	mediaAlta = s[0];
	media = 0;
	for(j=0; j<NUM_ESAMI; j++)
		media+=s[0].esami[j].voto;

	for(i=0; i<MAX; i++){
		tmp=0;
		for(j=0; j<NUM_ESAMI; j++){
			tmp+=s[i].esami[j].voto;	
		}
		if(media<tmp){
			mediaAlta = s[i];
			media = tmp;
		}
	}
	printf("Lo studente con la media piu' alta e': %d\n", mediaAlta.codicePersona);
	
	/* Il programma poteva anche essere eseguito con un due cicli  */
	
	return 0;
}
