/* 7) Scrivere un sottoprogramma Baricentro che, ricevuto in ingresso un array di
 * valori interi e qualsiasi
 * altro parametro ritenuto strettamente necessario, restituisce l’indice
 * dell’elemento che fa da baricentro
 * agli elementi dell’array, o -1 se questo non esiste.
 * Definiamo baricentro di un array di h elementi, l’elemento in posizione i tale per
 * cui:
 * v[0] + v[1] + ... + v[i] = v[i + 1] + v[i + 2] + … + v[h - 1]
 * Se dovessero esserci più baricentri, il sottoprogramma restituisce quello più a
 * sinistra.
 * 3
 * Esempio 1:
 * se il vettore contiene i valori: 1 5 10 4 4 2 6
 * il sottoprogramma restituisce il valore 2 (infatti la somma dei primi 3 elementi è
 * uguale a 16 come
 * quella degli ultimi 4 elementi).
 * Esempio 2:
 * se il vettore contiene i valori: 1 5 10 4 4 2 7
 * il sottoprogramma restituisce il valore -1, non essendoci alcun baricentro. */

#include<stdio.h>
#define DIM 7

int baricentro(int v[]);

int main(){
	int i, arr[DIM], baric;

	printf("Riempi l'array di %d elementi: ", DIM);
	for(i=0; i<DIM; i++){
		scanf("%d", &arr[i]);
	}

	baric = baricentro(arr);

	if(baric== -1)
		printf("Errore, baricentro non trovato\n");
	else
		printf("Il baricentro dell'array e' l'elemento in posizione %d\n", baric);
	
	return 0;

}

int baricentro(int v[]){
	int i, j, ris, sommaParz, tmp;
	ris = -1;
	sommaParz=0;

	for(i=0; i<DIM && ris==-1; i++){
		sommaParz+=v[i];
		tmp = 0;
		for(j=i+1; j<DIM; j++){
			tmp+=v[j];
		}
		if(tmp == sommaParz){
			ris = i;
		}
	}

	return ris;
}
