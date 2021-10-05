#include<stdio.h>
int main(){
	int n1, n2;
	scanf("%d%d", &n1,&n2);
	if (n1>n2)
		printf("Il maggiore e': %d", n1);
	else
		printf("Il maggiore e': %d", n2);
	return 0;
}
