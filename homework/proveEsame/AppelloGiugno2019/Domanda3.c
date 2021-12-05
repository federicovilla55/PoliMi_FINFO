/* Si definisca un sottoprogramma che data una stringa s e un carattere ch (e qualsiasi altro parametro
ritenuto necessario), restituisca una NUOVA stringa contenente i caratteri compresi tra la prima e la
seconda occorrenza di ch in s (queste occorrenze escluse). Si garantisce che il carattere ch è sempre
presente almeno due volte in s. Se lo si ritiene utile, è possibile usare la funzione strlen(); nessun'altra
funzione definita nel file string.h può essere usata.
Ad esempio,
s = "abracadabra" e ch='a', il sottoprogramma restituisce la stringa "br".
s="abcDdefDD" e ch=’D', il sottoprogramma restituisce la stringa "def"
s="uno,due;tre,quattro" e ch=',' il sottoprogramma restituisce la stringa "due;tre"
Nota: il sottoprogramma deve fare differenza tra maiuscole e minuscole (quindi 'a' e 'A' sono due
caratteri diversi). Inoltre, ch potrebbe essere un simbolo o un carattere numerico. */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_LEN 30

char *strCompresa(char s[], char ch);
int main(){
	char *s2, s[MAX_LEN], ch;
	printf("Inserisci una stringa ed un carattere: ");
	scanf("%s %c", s, &ch);
	s2 = strCompresa(s, ch);
	printf("Stringa compresa: %s\n", (s2));
	free(s2);

	return 0;
}

char *strCompresa(char s[], char ch){
	char *ris;
	int i, numChr, len, j, n;
	len = strlen(s);
	numChr = 0;
	j = 0;

	for(i=0; i<len && j!=2; i++){
		if(s[i] == ch)
			j++;
		else{
			if(j==1)
				numChr++;
		}
	}

	ris = malloc(sizeof(char) * numChr);

	if(ris){
		j=0;
		n=0;
		for(i=0; i<len && j!=2; i++){
			if(s[i] == ch)
				j++;
			else if(j==1){
				ris[n] = s[i];
				n++;
			}
		}


	}else
		printf("Errore allocazione");

	return ris;

}
