#include <stdio.h> 
#include <string.h>

int verifica(char p[]);
int main(int argc, char *argv[]){	
	if(argc == 2){
		if(verifica(argv[1]))
			printf("Password Valida\n");
		else
			printf("Password Non Valida\n");
	}else{
		printf("Argomenti Insufficienti \n");
	}

	return 0;
}

int verifica(char p[]){
	int len, i, ris, num, special;
	num = 0;
	special = 0;
	len = strlen(p);

	ris = len >= 8;

	for(i=0; i<len && ris; i++){
		if(p[i] >= '0' && p[i]<= '9')
			num = 1;
		else
			if(!(p[i]>='a' && p[i]<='z') && !(p[i]>='A' && p[i]<='Z'))
				special = 1;
		if(i>1){
			if(p[i]==p[i-1] && p[i]==p[i-2])
				ris = 0;
		}
	}
	ris = ris && num && special; 
	return ris;
}
