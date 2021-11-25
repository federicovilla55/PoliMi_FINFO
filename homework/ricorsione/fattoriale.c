/* Scrivere un sottoprogramma ricorsivo per il calcolo del fattoriale di un numero intero
 * positivo o nullo n ricevuto come parametro.
 * Scrivere un programma che chiede all'utente un valore, invoca il sottoprogramma
 * definito e visualizza il risultato.  */
#include<stdio.h>

int fattoriale(int n);
int main(){
	int num;
	printf("Dimmi un  numero: ");
	scanf("%d", &num);
	printf("Il fattoriale di %d e': %d\n", num, fattoriale(num));
	return 0;
}

int fattoriale(int n){
	if(n==1)
		return 1;
	else
		return n*fattoriale(n-1);
}
