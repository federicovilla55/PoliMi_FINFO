#include<stdio.h>
int main(){
	int n, tmp, reverse;
	scanf("%d", &n);
	reverse = 0;
	tmp = n;
	while(tmp>0){
		reverse*=10;
		reverse+=(tmp%10);
		tmp/=10;
	}
	if(n == reverse)
		printf("Il numero e' palindromo, 1");
	else
		printf("Il numero non e' palindromo, 0");
	return 0;
}
