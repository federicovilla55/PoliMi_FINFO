#include<stdio.h>
int main(){
	int max, i, n;
	scanf("%d", &max);
	for(i=0; i<4; i++){
		scanf("%d", &n);
		if(n>max)
			max=n;

	}
	printf("Il massimo e': %d\n", max);
	return 0;	
}
