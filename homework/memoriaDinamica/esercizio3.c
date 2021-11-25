/*3) Un elemento di una sequenza si dice basso se il suo valore è strettamente minore
 * del valore dell’elemento che lo precede e di quello che lo segue;
 * il primo e l’ultimo elemento della sequenza, non avendo entrambi gli elementi
 * precedente e successivo non sono mai definiti bassi.
 * Scrivere un sottoprogramma cercabassi che ricevuto in ingresso un array di valori
 * reali (e qualsiasi altro parametro ritenuto strettamente necessario) vi individua gli
 * elementi bassi e li salva in un nuovo array delle dimensioni strettamente necessarie
 * per contenerli.
 * Il sottoprogramma restituisce il nuovo array e ne trasmette inoltre al chiamante la
 * dimensione.
 * Esempio:
 * Se l’array ricevuto in ingresso contiene i valori:
 * 3.4 2.4 2.0 1.8 7.2 -3.1 -3.1 9.4 2.6 2.2 8.4 -3.1 5.4 2.1 7.4 -4.0 -11.4 -8.9
 * il sottoprogramma rileva i seguenti 5 elementi bassi:
 * 1.8 2.2 -3.1 2.1 -11.4
 * Scrivere un programma che chiede all’utente prima quanti dati reali vuole processare
 * (un valore strettamente positivo che nel caso di errore di inserimento va richiesto) e
 * poi tali valori reali.
 * Il programma invoca il sottoprogramma cercabassi e visualizza il nuovo array
 * restituito.*/

#include<stdio.h>
#include<stdlib.h>
float *cercaBassi(float a[], int dim, int *dim2);

int main(){
	int d1, d2, i;
	float *arr, *bassi;
	printf("Quanti elementi vuoi processare? ");
	scanf("%d", &d1);
	printf("Riempi l'array di %d valori reali: ", d1); 
	arr = malloc(sizeof(float) * d1);
	if(arr){
		for(i=0; i<d1; i++)
			scanf("%f", &arr[i]);
		
		bassi = cercaBassi(arr, d1, &d2);

		printf("I bassi sono: ");
		for(i=0; i<d2; i++)
			printf("%f ", *(bassi+i));

		free(arr);
		arr = NULL;
		free(bassi);
		bassi = NULL;
	}else{
		printf("Errore allocazione...\n");
	}
	return 0;
}
float *cercaBassi(float a[], int dim, int *dim2){
	int i, j;
	float *b;

	for(i=1; i<dim-1; i++){
		if(a[i]<a[i-1] && a[i]<a[i+1])
			(*dim2)++;
	}
	b = malloc(sizeof(float) * *(dim2));
	j = 0;
	if(b){
		for(i=1; i<dim-1; i++){
			if(a[i]<a[i-1] && a[i]<a[i+1]){
				b[j] = a[i];
				j++;
			}
		}
	}else{
		printf("Errore allocazione\n");
	}

	return b;
}
