#include<stdio.h>
int main(){
	int a,b,c;
	scanf("%d%d%d", &a, &b, &c);
	if((a*a)==(b*b)+(c*c) || (b*b)==(a*a)+(c*c) || (c*c)==(b*b)+(a*a))
		printf("Terna Pitagorica (1)\n");
	else
		printf("No Terna Pitagorica (0)\n");
	return 0;
}
