/*Scrivere un programma che riceve in   input un  array di interi positii e restituisce
 * 1 se esistono due elementi d arr la cui somma sia uguale a 17 o altrimenti 0
 * il massimo valore presente nell'array
 * il quasi massimo*/

#include<stdio.h>

int coppia17(int arr[], int dim, int *max, int *qmax){
	int h, k, trovato;
	
	trovato = 0;
	*qmax=-1;
	*max=arr[0];

	for(k=0; k<dim; k++){
		if(*max<arr[k]){
			*max=arr[k];
		} 
	}
	for(k=0; k<dim; k++){
		if(*qmax<arr[k] && *max>arr[k]){
			*qmax = arr[k];
		}

	}

	for(k=0; k<dim; k++){
		for(h=k; h<dim && !trovato; h++){
			if(arr[h]+arr[k] == 17){
				trovato = 1; 
			}
		}
	}

	return trovato;
}
