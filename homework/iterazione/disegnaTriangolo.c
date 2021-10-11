#include<stdio.h>
int main(){
	int n, i, tmp;
	tmp = 2;
	scanf("%d",&n);
	while(n<=0 || n%2!=0)
		scanf("%d",&n);
	while(tmp<n){
		for(i=0; i<n; i++){
			if(i<(n-tmp)/2 || i>=((n-tmp)/2)+tmp)
				printf(" ");
			else
				printf("*");
		}
		tmp+=2;
		printf("\n");
	}
	return 0;
}
