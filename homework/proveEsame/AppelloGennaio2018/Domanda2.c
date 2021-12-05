/* Domanda 2- (…/6 punti)
Realizzare la funzione replica che accetta come parametri una stringa s, un intero n >= 0 e qualsiasi
altro parametro si ritenga opportuno; la funzione deve restituire una NUOVA stringa ottenuta
concatenando n copie di s. Ad esempio, replica con parametri "ciao" e 3 ritorna la stringa
"ciaociaociao" in cui la parola "ciao" viene ripetuta tre volte; replica con parametri "ciao" e 0 ritorna la
stringa vuota "".
Se lo si ritiene utile è possibile fare uso della funzione strlen(); non è invece consentito usare funzioni
come strcat(), strcpy() e simili.  */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DIM 15
char *replica(char s[], int n);

int main(){
	char *str, s[DIM];
	int n;
	printf("Dimmi una stringa e un intero: ");
	scanf("%s %d", s, &n);
	
	str=replica(s, n);
	printf("Risultato: %s\n", str);
	
	return 0;
}

char *replica(char s[], int n){
	char *stringa;
	int i, len, j, dim;
	len = strlen(s);
	dim = n*len;
	stringa=NULL;
	stringa = (char *) malloc(sizeof(char) * (n*len + 1));
	if(stringa){
		j=0;
		for(i=0; i<dim; i++){
			if(s[j]=='\0'){
				j=0;	
			}
			stringa[i] = s[j];
			j++;	
		}
		stringa[i+1]='\0';
	}else{
		printf("Errore allocazione...");
	}
	return stringa;
}
