/* Un tautogramma è una frase in cui tutte le parole iniziano con la stessa lettera dell'alfabeto. Ad
esempio, le frase:
 "veni vidi vici"
è un tautogramma.
Realizzare un sottoprogramma tautogramma che accetta in input una stringa s (e qualsiasi altro
parametro ritenuto necessario), e restituisce 1 se e solo se s è un tautogramma, 0 altrimenti. Si
garantisce che in s non siano mai presenti lettere maiuscole; possono però essere presenti spazi, numeri
e altri segni di punteggiatura, che devono essere ignorati.
Se lo si ritiene utile è possibile usare le funzioni definite in <string.h>. È anche possibile definire
ulteriori funzioni.  */

#include<stdio.h>

#define DIM 30

int isTautogramma(char s[]);

int main(){
	char str[DIM];

	printf("Inserisci una stringa: ");
	scanf("%[^\n]", str);

	if (isTautogramma(str))
		printf("La stringa inserita e' un tautogramma \n");
	else
		printf("La stringa inserita non e' un tautogramma\n");

	return 0;
}

int isTautogramma(char s[]){
	int ris, i, begin, len;
	ris = 1;
	begin=-1;
	for(i=0; s[i]!='\0' && ris; i++){
		if(begin==-1 && (s[i] >= 'a' && s[i]<='z'))
			begin = i;
		else if(s[i-1]==' ' && s[i]!=s[begin]){
			ris=0;
		}
	}

	return ris;

}
