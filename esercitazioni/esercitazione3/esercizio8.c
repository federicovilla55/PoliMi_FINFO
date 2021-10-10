//Scrivere un programma che stampi a schermo una piramide di *
// di altezza n definita dall'utente
#include<stdio.h>
int main(){
	int n, i, j, spazi, tmp;
	i = 0;
	printf("Dimmi l'altezza della piramide:  ");
	scanf("%d", &n);
	spazi = (n-1)*2 + 1;
	tmp = spazi;
	while(i < n){
		j = 0;
		printf("\n");
		while(j<spazi){
			if(j<(tmp/2) || j>=(spazi - (tmp/2))) 
				printf(" ");
			else
				printf("*");
			j=j+1;
		}
		tmp = tmp - 2;
		i=i+1;
	}
	printf("\n");
	return 0;
}
