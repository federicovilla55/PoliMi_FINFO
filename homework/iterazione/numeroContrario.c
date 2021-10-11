#include<stdio.h>
int main(){
	int n, reverse;
	scanf("%d", &n);
	reverse = 0;
	while(n>0){
		reverse*=10;
		reverse+=(n%10);
		n/=10;
	}
	printf("Il numero con le cifre al contraro e': %d", reverse);
	return 0;
}
