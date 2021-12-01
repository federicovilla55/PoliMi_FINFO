/* Scrivere un sottoprogramma che riceve in input un array arr[] di interi positivi (non
necessariamente distinti) e qualsiasi altro parametro ritenuto necessario, e restituisce:
• 1 se esistono due elementi in arr[] la cui somma sia esattamente uguale a 17,
altrimenti 0
• il massimo valore presente nell'array
• il quasi massimo, cioè il più grande numero contenuto nell’array che non sia il
massimo (ossia il secondo numero più grande dell’array)
Ad esempio,
se arr ={1,2,3,4,7,10,33,1,1,99}, vengono restituiti 1, 99, 33
se arr ={4,5,6,7,7,88,22} vengono restituiti 0, 88, 22 */

int cerca(int arr[], int N; int *quasiMassimo, int *massimo){
	int i, j;
	int somma17;

	somma17 = 0;
	*quasiMassimo = 0;
	*massimo = arr[0];
	for(i=0; i<N; i++){
		if(arr[i] > *massimo)
			*massimo = arr[i];
		
		if(arr[i] < *massimo && arr[i] > *quasiMassimo){
			*quasiMassimo = arr[i];
		}

	}
	for(i=0; i<N; i++){
		for(j=i+1; j<N; j++){
			if(arr[i]+arr[j] == 17){
				somma=1;
			}
		}
	}

	return somma17;
}
