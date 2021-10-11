#include<stdio.h>
int main(){
	int a, b, temp;
	int MCD, mcm;
	do{
		scanf("%d %d", &a, &b);
	}while(a<0 && b<0);
	mcm = a*b;
	if (a>b){
		temp=a;
		a=b;
		b=temp;
	}
	while(b!=0){
		temp=a%b;
		a=b;
		b=temp;
	}
	MCD = a;
	mcm = mcm/MCD;
	printf("MCM: %d\t mcm: %d\n", MCD, mcm);
	return 0;
}
