#include<stdio.h>
#define N 10
int check_scorrimento(int a[], int b[], int dim);

int main(){
	int i, a[N], b[N];
	printf("Riempi due array di %d elementi:\n", N);
	for(i=0; i<N; i++)
		scanf("%d", &a[i]);
	for(i=0; i<N; i++)
		scanf("%d", &b[i]);

	printf("Spostamento: %d\n", (N-check_scorrimento(a, b, N)));

	return 0;
}

int check_scorrimento(int a[], int b[], int dim){
	int i, j, ok, found;
	for(i=0, found = 0; i<dim && !found; i++){
		for(j=0, ok=1; j<dim && ok; j++){
			if(a[j]!= b[(i+j)%dim])
				ok=0;
		}
		if(ok)
			found = 1;
	}


	if(found)
		i--;
	else
		i=-1;
	return i;
}
