#include<stdio.h>
int main(){
	int num, bin, cifre, r;
	cifre=1;
	bin=0;
	scanf("%d", &num);
	while(num>0){
		r=num%2;
		printf("Q: %d | 2   r: %d\n", num, r);
		num/=2;
		bin+=(r*cifre);
		cifre*=10;
	}
	printf("Il valore in codifica binaria e': %d", bin);
	return 0;
}
