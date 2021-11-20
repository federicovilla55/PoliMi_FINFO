/* Scrivere un sottoprogramma ricorsivo che riceve come parametro un array di interi
 * (e la sua dimensione) e calcola e restituisce il valore massimo.
 * Scrivere un programma che chiede all'utente 10 valori interi, invoca il
 * sottoprogramma definito e visualizza il risultato.  */
#include<stdio.h>
#define DIM 10
int massimo(int v[], int max, int p);
int main(){
	int v[DIM], i, p;
	printf("Riempi un array di %d elementi: \n", DIM);
	for(i=0; i<DIM; i++){
		scanf("%d", &v[i]);
	}
	p=1;
	printf("L'elemento massimo dell'array e': %d\n", massimo(v, v[0], p));
	return 0;
}

int massimo(int v[], int max, int p){
	if(p==DIM)
		return max;
	if(max < v[p])
		max = v[p];
	p++;
	return massimo(v, max, p);
}

