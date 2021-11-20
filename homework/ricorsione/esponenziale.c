/* Scrivere un sottoprogramma ricorsivo che riceve come parametri due interi a e b con
 * a sicuramente diversa da 0 e calcola e restituisce a^b
 * Scrivere un programma che chiede due numeri interi m e n che rappresentano la
 * base e l'esponente di una potenza ed invoca il sottoprogramma per calcolare la
 * potenza m^n. Il programma visualizza infine il risultato.  */
#include<stdio.h>
int potenza(int a, int b);
float calcoloPotenza(int a, int b);
int main(){
	int a, b;
	printf("Dimmi due numeri: ");
	scanf("%d %d", &a, &b);

	printf("Il risultato di a^b e': %f", calcoloPotenza(a, b));
	return 0;
}

int potenza(int a, int b){
	if(b==0){
		return 1;
	}else{
		return a*potenza(a, b-1);
	}
}

float calcoloPotenza(int a, int b){
	if(b>0)
		return potenza(a, b);
	else
		return 1.00/potenza(a, -b);
}
