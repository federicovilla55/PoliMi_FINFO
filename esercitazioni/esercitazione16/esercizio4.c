#include<stdio.h>
#include<string.h>
#define MAX_SEQ 27
#define MAX_PAR 16 /*Nelle costanti e' gia' presente il carattere termiantore*/

void count(char[], char[], int[]);

int main(){
	char seq[MAX_SEQ];
	FILE *f;
	char parola[MAX_PAR]; 
	int nums[MAX_SEQ-1], l, i;
	
	++i;
	c=parola[i];printf("Inserire sequenza di controllo: ");
	scanf("%s", seq);
	l = strlen(seq);
	
	for(i=0; i<l;i++){
		nums[i] = 0;
	}

	f = fopen("testo.txt", "r");
	if(f){
		fscanf(f, "%s", parola);
		do{
			count(parola, seq, nums);
			fscanf(f, "%s", parola);
		}while(!feof(f));
		fclose(f);
		for(i=0; i<l; i++){
			printf("%c: %d \n", seq[i], nums[i]);
		}
	}else
		printf("Errore apertura file");

	return 0;
}

void count(char parola[], char seq[], int nums[]){
	char c;
	int len, i, j;
	len = strlen(seq);
	i = 0;
	c = parola[0];
	while(c != '\0'){
		j = 0;
		while(j<len && seq[j]!=c){
			j++;
		}
		if(j<len){
			++nums[j];
			
		}
		++i;
		c=parola[i];
	}
}
