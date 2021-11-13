/* 6) Scrivere un sottoprogramma che riceve come parametro una stringa che rappresenta
 * un numero intero
 * positivo in base 8 (cioè composta soltanto dai caratteri dallo ‘0’ al ‘7’). Il
 * sottoprogramma calcola e
 * restituisce il valore intero rappresentate lo stesso numero in base 10. Nel caso la
 * stringa contenga un
 * carattere non valido, il sottoprogramma restituisce il valore -1.
 * Esempio 1: Se il sottoprogramma riceve in ingresso la stringa “24” restituisce il
 * valore 20 (infatti 2 x 81
 * + 4 x 80 = 20).
 * Esempio 2: Se il sottoprogramma riceve in ingresso la stringa “95” restituisce il
 * valore -1 (infatti ‘9’
 * non è un carattere tra ‘0’ e ‘7’). Stessa cosa se il sottoprogramma riceve in
 * ingresso la stringa “h5” */

#include<stdio.h>
#include<string.h>
#define DIM 20
#define BASE 8

int conversioneBase8(char s[]);

int main(){
	char base8[DIM];
	int ris;
	printf("Dimmi un numero in base %d: ", BASE);
	scanf("%s", base8);
	ris =  conversioneBase8(base8);
	
	if(ris == -1)
		printf("Errore, non e' stato inserito un numero corretto numero in base 8\n");
	else
		printf("Il numero %s in base 10 e': %d", base8, ris);
	
	return 0;	
}

int conversioneBase8(char s[]){
	int result, i, j, len;
	result = 0;
	j=1;
	len=strlen(s);	
	for(i=0; i<len-1; i++)
		j*=BASE;
	for(i=0; i<len; i++){
		if(!(s[i]>='0' && s[i]<='8')){
			result=-1;
			i=len;
		}
		else{
			result +=  (s[i]-'0') * j;
			j/=BASE;
		}
	}

	return result;

}
