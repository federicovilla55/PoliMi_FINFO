// Scrivere un programma in C chiede all'utente un numero intero
// e ne visualizza il suo valore assoluto.
#include<stdio.h>
int main(){
	int x;
	scanf("%d", &x);
	if (x<0)
		x=-x;
	printf("Valore Assoluto: %d\n", x);
	return 0;
}
