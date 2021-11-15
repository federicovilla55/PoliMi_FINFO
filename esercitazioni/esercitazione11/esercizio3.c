/*Scrivere una funzione in C che avendo in input un array di n interi positivi dia in output
 * l'elemento minimo della lista. Fare cio' in modo ricorsivo*/

#include<stdio.h>
#include<limits.h>
#define N 5

int min_it(int A[], int n);
int min_ric(int A[], int n);
int min_ric2(int A[], int i, int n, int min);

/*Si poteva anche creare una funzione con i puntatori al posto degli indici*/

int main(){
	int arr[N], i;
	for(i=0; i<N; i++){
		printf("inserire elemento %d: ", i);
		scanf("%d", &arr[i]);
	}

	printf("Il minimo e': %d \n", min_ric2(arr, 0, N, INT_MAX));
	return 0;
}

int min_it(int A[], int n){
	int min = A[n-1], i;
	for(i= n-1; i > 0; i--){
		if(A[i-1] < min){
			min = A[i-1];
		}
	}

	return min;
}

int min_ric(int A[], int n){
	int min_resto;
	if(n == 1){
		return A[0];
	}else{
		min_resto = min_ric(A, n-1);
		if(A[n-1] < min_resto){
			return A[n-1];
		}else{
			return min_resto;
		}
	}
}

int min_ric2(int A[], int i, int n, int min){
	if(i >= n){
		return min;
	}else if(A[i] < min){
		min = A[i];
	}
	
	return min_ric2(A, i+1, n, min);

	/* Le due funzioni ricorsive presentano differenze nel
	 * numero degli argomenti e nel modo in cui la ricorsione viene fatta
	 * passando il minimo dell'argomento la funzione finisce con il minimo 
	 * della funzione ricorsiva stessa. Queste tipologie di funzioni sono
	 * dette Tail Recursive. */
}
