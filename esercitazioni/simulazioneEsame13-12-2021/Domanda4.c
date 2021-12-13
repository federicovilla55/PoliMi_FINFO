#include <stdio.h> 
#include <string.h>
#define MAX 80

void analizzaFile(char fileName[], int *numChar, int *numWord, int *numLine);

int main(){
	int caratteri, righe, parole;
	char nomeFile[MAX];
	strcpy(nomeFile, "input.txt");	
	analizzaFile(nomeFile, &caratteri, &parole, &righe);

	printf("Contenuto del file: \n\t %d caratteri,\n\t %d parole, \n\t %d righe\n", caratteri, parole, righe); 
	return 0;
}

void analizzaFile(char fileName[], int *numChar, int *numWord, int *numLine){
	FILE*fp;
	char c;
	int isWord;
	fp = fopen(fileName, "r");
	*numChar=0;
	*numWord=0;
	*numLine=0;

	if(fp){
		while(fscanf(fp, "%c", &c)>0){
			if(c=='\n'){
				(*numLine)++;
			}
			if(c!=' ' && c!='\n' && isWord==0){
				isWord=1;
				(*numWord)++;
			}
			if((c==' ' || c=='\n') && isWord==1){
				isWord=0;
			}
			(*numChar)++;
		}

		fclose(fp);
	}else{
		printf("Errore apertura file...\n");
	}


}
