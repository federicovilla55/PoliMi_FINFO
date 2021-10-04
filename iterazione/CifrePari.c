//Inserire un numero e dire se questo e' composto da sole cifre pari
#include<stdio.h>
int main(){
	int n, bul;
	bul = 0; // Bul variabile sentinella che dice se ci sono cifre dispari
	printf("Dimmi un numero di cui vuoi controllare se le cifre sono pari: ");
	scanf("%d", &n);
	while(n>0 && bul==0){
		if(n%2!=0)
			bul=1;
		n=n/10;
	}
	if(bul == 0)
		printf("Tutte le cifre sono pari\n");
	else
		printf("Ci sono alcune cifre dispari\n");
	return 0;
}
