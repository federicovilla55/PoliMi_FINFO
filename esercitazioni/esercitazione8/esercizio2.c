/*Polinomi:
Scrivere un programma in grado di calcolare il valore di polinomi di grado massimo  8. 
Il programma chiede all'utente il grado n del polinomio desiderato 
(numero intero tra 0 e 8 inclusi). Successivamente chiedere all'utente i coeffiecienti dei monomi,
infien chiedere all'utente il valore x...
*/

#include<stdio.h>
#define MAX_GRADO 8

int potenza(int, int);

int main(){
	int grado, coeff[MAX_GRADO + 1], x, risultato, pot;
	
	do{
		scanf("%d", &grado);
	}while(grado < 0 || grado > MAX_GRADO);
	
	for(i=-grado; i<=0; i++){
			printf(" Inserire il coefficiente per x alla %d: ", -i);
			scanf("%d", &coeff[-i]); /*Lo stesso si poteva fare anche con -i e -grado*/
	}
	
	printf("Inserire il valore di x: ");
	scanf("%d", &x);
	
	risultato = 0;
	for(i=0; i<grado; i++){
		risultato += coeff[i]*potenza(x, i);
	}
	printf("Risultato %d", risultato);
	
	return 0;
	
}

int potenza(int n, int m){
	int ris, i;
	ris = 1;
	
	for(i=0; i<m; i++){
		ris*=n;
	}
	return ris;
}