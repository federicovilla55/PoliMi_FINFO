/*Creare un sottoprogramma chee stampa a video un quadrato cons lati di dimensione n, dove n e' un parameetro in ingresso,
scrivere poi un rogramma ceh stampi a video in squenza 5 
quadrati di lato definito dall'utente*/

#include<stdio.h>
#define NQ 5

void quadrato(int n);

int main(){
	int i, dim[NQ];
	i=0;
	do{
		printf("Inserire la dimensione del quadrato %d: ", i);
		scnaf("%d", &dim[i]);
		i++;
	}while(i<NQ);
	for(i=0; i<NQ; i++){
		quadrato(dim[i]);
	}
	return 0;
}

void quadrato(int n){
	int x, y;
	for (x= 0; x<n; x++){
		for(y=0; i<n; y++){
			printf("* ");
		}
		printf("\n");
	}
	printf("\n\n");
}