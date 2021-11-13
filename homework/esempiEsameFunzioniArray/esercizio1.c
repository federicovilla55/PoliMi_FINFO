/* 1) Scrivere un sottoprogramma verifica che ricevuta in ingresso una stringa che
 * contiene una
 * password, restituisce 1 se sono verificate tutte le condizioni seguenti, 0
 * altrimenti:
 * • è presente almeno una cifra
 * • è presente almeno un carattere che non sia una cifra o un carattere dell’alfabeto
 * • è di almeno 8 caratteri
 * • non contiene tre caratteri uguali consecutivi  */

#include<stdio.h>
#define DIM 20
int isSecure(char s[]);
int main(){
	char s1[DIM];
	int ris;
	printf("Dimmi una password: ");
	scanf("%s", s1);
	ris=isSecure(s1);

	if(ris)
		printf("La password inserita e' sicura\n");
	else
		printf("La password inserita non rispetta gli standard di sicurezza\n");
	return 0;
}

int isSecure(char s[]){
	int result, isNum, isSpecial, isLen, isNotConsec, i;
	isNum=0;
	isSpecial=0;
	isLen=0;
	isNotConsec=1;
	result = 0;
	for(i=0; s[i]!='\0' && !result; i++)
	{
		if(s[i]>='0' && s[i]<='9'){
			isNum=1;
		}

		if(!((s[i]>='0' && s[i]<='9') || ( s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))){
			isSpecial=1;
		}
		if(i>=7){
			isLen=1;
		}
		if(i>0 && s[i]==s[i-1] && s[i]==s[i+1]){
			isNotConsec=0;
		}
		
		result = isNum && isSpecial && isLen && isNotConsec; 
	}
	return result;	
}
