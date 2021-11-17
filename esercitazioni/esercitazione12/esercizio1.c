/*Scrivere una funzione ricorsiva in C che dati in input due numeri interi positivi, ne restituisca
 * il Massimo Comune Divisore*/
#include<stdio.h>
int MCD(int n1, int n2);

int main(){
	int a, b, tmp;
	

	printf("Dimmi due numeri interi: ");
	scanf("%d %d", &a, &b);
	
	if(a<b){
		tmp = b;
		b = a;
		a = tmp;
	}

	printf("MCD e': %d", MCD(a, b));

	return 0;

}

int MCD(int n1, int n2){
	if (n2 == 0){
		return n1;
	} else {
		return MCD(n2, n1%n2);	
	}
}
