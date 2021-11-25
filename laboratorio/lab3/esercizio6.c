#include<stdio.h>
#define DIM 20

int asciiToInt(char s[]);

int main(){
	char s[DIM];
	int ris;
	printf("Dimmi una stringa: ");
	scanf("%s", s);
	
	ris = asciiToInt(s);

	printf("Risultato: %d\n", ris);

	return 0;
}

int asciiToInt(char s[]){
	int res, i;

	res=0;

	for(i=0; s[i]!='\0' && res!=-1; i++){
		if(s[i]>='0' && s[i]<='9'){
			res*=10;
			res+= s[i] - '0';

		}else{
			res = -1;
		}

	}

	return res;
}

