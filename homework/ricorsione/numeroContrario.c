/* Scrivere una funzione ricorsiva che riceve come parametro un numero
 * intero positivo o nullo e ne visualizza le cifre al contrario (da
 * destra verso sinistra). Per esempio se la funzione riceve il numero
 * 123456 visualizzerà il messaggio 654321. Scrivere un programma che
 * chiede all'utente un intero ed invoca la funzione sopra definita. */
#include<stdio.h>
void numeroContrario(int n); 
int main(){
	int n;
	printf("Inserisci un numero: ");
	scanf("%d", &n);

	printf("Numero al contrario: ");
	numeroContrario(n);
	return 0;
}
void numeroContrario(int n){
	if(n==0)
		printf("\n");
	else{
		printf("%d", (n-n/10*10));
		numeroContrario(n/10);
	}	
}
