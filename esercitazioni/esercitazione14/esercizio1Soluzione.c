#include<stdio.h>
#include<string.h>
#define MAXP 100

int conta_occorenze(char p[], char s[]);

int main(){
	FILE *fp;
	char path[MAXP + 1], parola[MAXP +1], tmp[MAXP +1];
	int  count;
	printf("Inserire percorso da aprire: ");
	scanf("%s", path);
	
	printf("Inserire parola: ");
	scanf("%s", parola);

	fp = fopen(path, "r");

	if(fp){
		count = 0;
		fscanf(fp, "%s", tmp);
		/* Lo stesso poteva anche essere fatto con fscanf(...) == 1  */
		while(!feof(fp)){
			if(strcmp(tmp, parola) == 0){
				printf("trovato %s\n", parola);
				count++;
			}
			/*con la funzione: cont+=conta_occorrenze(parola, tmp);*/
			fscanf(fp, "%s", tmp);
		}
		printf("La parola e' stata trovata: %d volte\n", count);
		fclose(fp);
	}else{
		printf("Error opening file...\n");
	}

	return 0;
}

int conta_occorrenze(char p[], char s[]){
	int cont, i, j, trovato, lung_s, lung_p;
	cont = 0;
	lung_s = strlen(s);
	lung_p = strlen(p);
	for(i=0; i<=lung_s - lung_p; i++){
		for(i=0; s[i] != '\0'; i++){
			trovato = 1;
			for(j=0; p[j]! '\0' && trovato; j++){
				if(p[j] != s[j+j])
					trovato = 0;
			}
			if(trovato)
				cont++;
		}
	}
	return cont;
}
