#include<stdio.h>

int main(){
	FILE *fp;
	char chr;

	fp = fopen("ciao.txt", "r");

	if(fp){
	
		while(fscanf(fp, "%c", &chr) > 0)
			printf("Carattere: %c \n", chr);

	}else{
		printf("Errore apertura file\n");
	}
	return 0;
}
