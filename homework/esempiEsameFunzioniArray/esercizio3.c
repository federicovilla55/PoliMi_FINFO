/* 3) Si scriva un sottoprogramma rightshift che ricevuta in ingresso una stringa
 * sorgente s e un numero
 * intero senz’altro positivo n, modifica la stringa in modo tale che la stringa
 * finale sia quella iniziale, fatta
 * scorrere di n posizioni a destra (con gli ultimi n caratteri riportati all’inizio).
 * Per esempio se la stringa iniziale è Giuseppe ed n = 1, la stringa finale sarà
 * eGiusepp, se n = 2, la
 * stringa finale sarà peGiusep. */

#include<stdio.h>
#include<string.h>
#define DIM 20

void rightshift(char [], int);

int main(){
	char str[DIM];
	int n;

	printf("Dimmi una stringa ed un numero intero: ");
	scanf("%s %d", str, &n);

	rightshift(str, n);
	
	printf("Ecco la nuova stringa traslata di %d posizioni: %s\n", n, str);

	return 0;
}

void rightshift(char s[], int n){
	int i, j, len, precedente, tmp;
	len=strlen(s);
	for(j=0; j<n; j++){
		precedente = s[0];
		for(i=1; i<=len; i++){
			if(s[i]=='\0'){
				tmp=s[0];
				s[0]=precedente;
				precedente=tmp;
			}else{
				tmp = s[i];
				s[i] = precedente;
				precedente = tmp;
			}	
		}
	}
}
