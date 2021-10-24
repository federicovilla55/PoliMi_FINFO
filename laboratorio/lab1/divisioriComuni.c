/* Scrivere un programma che dati due numeri interi positivi
 * inserti dall'utente, stampi a video i divisori comuni 
 * maggiori di 1  */
#include<stdio.h>
int main(){
	int a, b, temp, i, cont;
	scanf("%d %d", &a, &b);
	/* Riordino i due valori mettendo in a il più piccolo*/
	if (a>b){
		temp = a;
		a = b;
		b = temp;
	}
	cont = 0;
	for(i = 2; i <= a; i++){
		if(a%i==0 && b%i==0){
			printf("Un divisiore comune: %d\n", i);
			cont++;
		}
	}
	if(cont==0)
		printf("I due numeri sono coprimi");
	return 0;

	/* Soluzione del Docente:
	 * int n, m;
	 * Inserimento variabili con 2 printf e scanf
	 * for(i=2; i<m && i<n; i++){
	 *	if(n%i==0 && m%i==0){
	 *		printf("%d", i);
	 *	}
	 * }  */
}
