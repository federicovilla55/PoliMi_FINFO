/*Scrivere un sottoprogramma che riceve in input un array arr[] di interi positivi (non necessariamente
distinti) e qualsiasi altro parametro ritenuto necessario, e restituisce:
- 1 se esistono due elementi in arr[] la cui somma sia esattamente uguale a 17, altrimenti 0
- il massimo valore presente nell'array
- il quasi massimo, cioè il più grande numero contenuto nell’array che non sia il massimo (ossia il
secondo numero più grande dell’array)
Ad esempio,
se arr ={1,2,3,4,7,10,33,1,1,99}, vengono restituiti 1, 99, 33
se arr ={4,5,6,7,7,88,22} vengono restituiti 0, 88, 22 */

#include<stdio.h>

int analizzaArray(int arr[], int dim, int *max, int *qmax);

int main(){
    int massimo, quasimassimo, ris;
    int arr[10] ={1,2,3,4,7,10,33,1,1,99};
    ris = analizzaArray(arr, 10, &massimo, &quasimassimo);

    printf("Risultato: %d \t Massimo: %d \t Quasi: %d \n", ris, massimo, quasimassimo);

    return 0;
}

int analizzaArray(int arr[], int dim, int *max, int *qmax){
    int i, j, tmp, ris;
    ris = 0;
    if(arr[0] > arr[1]){
        *max = arr[0];
        *qmax = arr[1];
    }else{
        *max = arr[1];
        *qmax = arr[0];
    }
    for(i=1; i<dim; i++){
        for(j=i+1; j<dim && !ris; j++){
            if(arr[i]+arr[j] == 17)
                ris=1;
        }
        if(arr[i] > *max){
            *qmax = *max;
            *max = arr[i];
        }
        if(arr[i] > *qmax && arr[i] < *max)
            *qmax = arr[i];
    }
    return ris;
}