/* Scrivere un programma che dato un 
 * anno inserito dall'utente come numero 
 * intero dica se e' bisestile o meno
 */
#include<stdio.h>
int main(){
	/*Dichiarazione Variabili*/
	int anno;

	/*Richiesta dati in Input*/
	printf("Dammi un anno e io ti diro' se e' bisestile: ");
	scanf("%d", &anno);

	if((anno%4 == 0 && anno%10!=0) || anno%400==0)
		printf("Anno Bisestile\n");
	else
		printf("Anno non Bisestile\n");
	return 0;

	/* Correzione docente Laboratorio:
	 * ris=anno%4 && anno%100!=0 || anno%400==0;
	 * if(ris == 0){
	 *	printf("Anno Bisestile");
	 * }
	 * */
}
