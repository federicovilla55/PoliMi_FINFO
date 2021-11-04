/* Somma valori dispari
Scrivere una funzione che riceve in ingresso due numeri itneri a e b e restituisce la somma dei numeri dispari nell'intervallo, compresi gli estremi. LA funzione gestisce sia il caso a>b che b>a. Scrivere un programma con chiamata alla funzione e visualizza il valore.
*/
#include<stdio.h>

int sommaDispari (int a, int b);

int chiamaSomma(int a, int b);

int main(){
	int n, m, sum;
	printf("Inserire il minimo e il massimo dell'intervallo: ");
	scanf("%d %d", &n, &m);
	sum = sommaDispari(n, m);
	printf("La somma e': %d", sum);
	return 0;
}

int sommaDispari (int a, int b){
	int somma, t;
	somma = 0;
	
	if(a>b){
		t = a;
		a = b;
		b = t;
	}
	
	for(t=a; t<=b; t++){
		if(t%2){
			somma+=t;
		}
	}
	return somma;
}

int chiamaSomma(int a, int b){
	if(a<b){
		return sommaDispari(a, b);
	} else{
		return sommaDispari(b, a);
	}
	
	/* Si potrebbe anzichè usare un if fare la seguente funzione */
}
