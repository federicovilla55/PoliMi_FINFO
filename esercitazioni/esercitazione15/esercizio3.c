/*Stringhe dinamiche
 * Si scriva una funzione in grado di creare (e ritornare) una stringa data dalla
 * concatenazione di un array di stringhe, ricevute come parametri.
 * La stringa generata va allocata dinamicamente.*/
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#define N 5
#define SMAX 50

char *concatena(char *ls[], int n);

int main(){
	char *l_str[N];
	char tmp[SMAX];
	char *concat;
	int i;
	for(i=0; i<N; i++){
		printf("inserire stringa: ");
		scanf("%s", tmp);
		l_str[i] = malloc(sizeof(char) * (strlen(tmp) + 1 ));

		if(l_str[i] != NULL){
			strcpy(l_str[i], tmp);
		}
	}

	concat = concatena(l_str, N);
	
	if(concat != NULL){
		printf("Stringa concatenata: %s\n", concat);
	}

	free(concat);
	for(i=0; i<N; i++){
		free(l_str[i]);
	}

	return 0;
}

char *concatena(char *ls[], int n){
	int i, lung;
        char *res;
	lung = 0;
	for(i=0; i<n; i++){
		lung +=strlen(ls[i]);
	}
	res = malloc((lung +1) * sizeof(char));
	if(res == NULL){
		return NULL;
	}
	res[0] = '\0'; 	/*Inizializzazione di res come una stringa vuota*/
	/*L'inizializzazione e' fondamentale poiche' strcat e' una funzione
	 * che si aspetta di avere una stringa ben formata quindi con un
	 * terminatore*/
	for(i=0; i<n; i++){
		strcat(res, ls[i]);
	}
	return res;
}
