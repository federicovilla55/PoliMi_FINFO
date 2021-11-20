/* Scrivere un sottoprogramma ricorsivo che riceve due numeri interi
 * positivi a e b e calcola risultato e resto della divisione intera a/
 * b (senza l'utilizzo degli operatori / e %).
 * Scrivere un programma che acquisisce due valori x e y ed invoca la
 * funzione sopra definita, visualizzando poi il risultato.  */
#include<stdio.h>
int resto(int x, int y);
int main(){
	int a, b;
	printf("Dimmi due numeri: ");
	scanf("%d %d", &a, &b);
	printf("Il resto di %d/%d e': %d\n", a, b, resto(a, b));
	
	return 0;
}

int resto(int x, int y){
	if(x < y)
		return x;
	else
		return resto(x-y, y);
}
