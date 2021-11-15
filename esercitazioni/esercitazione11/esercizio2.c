/*Scrivere una funzione positiva che dati n numeri itneri positivi, 
 * restituisce in output 1 se sono tutti maggiori di n (con n dato in input)
 * oppure 0 se cio' e' falso */

#include<stdio.h>
#define N 5

int tutti_maggiori_it(int A[], int n, int m);
int tutti_maggiori_ric(int A[], int n, int i, int m);
int tutti_maggiori_it1(int A[], int n, int m);
int tutti_maggiori_ric1(int A[], int n, int m);
int tutti_maggiori_it2(int *A, int *A_end, int m);
int tutti_maggiori_ric2(int *A, int *A_end, int m);


int main(){
	int arr[N], i, m;
	i=0;
	do{
		printf("Inserire numero %d: ", i);
		scanf("%d", &arr[i]);
		i++;
	}while(i < N);

	printf("Inserire valore m: ");
	scanf("%d", &m);

	if(tutti_maggiori_ric(arr, N, 0, m))
		printf("Sono tutti maggiori.\n");
	else
		printf("Non sono tutti maggiori.\n");

	return 0;
}

int tutti_maggiori_it(int A[], int n, int m){
	int i, maggiori;
	maggiori = 1;
	for(i = 0; i<n; i++){
		if(A[i] <= m){
			maggiori = 0;
		}
	}
	return maggiori;
}

int tutti_maggiori_ric(int A[], int n, int i, int m){
	if(i==n){
		return 1;
	} else if (A[i] <= m) {
		return 0;
	} else {
		return tutti_maggiori_ric(A, n, i+1, m);
	}
}

int tutti_maggiori_it1(int A[], int n, int m){
	int maggiori = 1;
	while(n>0 && maggiori){
		if(A[n-1] <= m){
			maggiori = 0;
		}
		n--;
	}

	return maggiori;
}

int tutti_maggiori_ric1(int A[], int n, int m){
	if(n<=0){
		return 1;
	} else if(A[n-1] <= m){
		return 0;
	} else {
		return tutti_maggiori_ric1(A, n-1, m);
	}
}

int tutti_maggiori_it2(int *A, int *A_end, int m){
	int maggiore = 1;
	while(A != A_end && maggiore){
		if(*A <= m){
			maggiore = 0;	
		}
		A++;
	}
	return maggiore;

	/* nel Main lo si richiama con tutti_maggiori_it2(A, A + N, m) */
}

int tutti_maggiori_ric2(int *A, int *A_end, int m){
	if(A == A_end){
		return 1;
	} else if(*A <= m){
		return 0;
	} else{
		return tutti_maggiori_ric2(A+1, A_end, m);
	}

}
