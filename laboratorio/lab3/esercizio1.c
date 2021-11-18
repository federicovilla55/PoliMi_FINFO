#include<stdio.h>
#define N 10

int main(){
	int somma, prodotto, i, v[N], x;

	printf("Dimmi %d inseri e un altro valore: ", N);
	for(i=0; i<N; i++)
		scanf("%d", &v[i]);
	do{
		scanf("%d", &x);
	while(x<0 || x>=10);
	somma=0;
	prodotto=1;
	for(i=0; i<N; i++){
		if(i<=x)
			somma+=v[i];
		if(i>x)
			prodotto*=v[i];	
	}

	printf("La somma degli elementi precedenti a %d e': %d\n", x, somma);
	printf("Il prodotto e': %d\n", prodotto);

	return 0;
}
