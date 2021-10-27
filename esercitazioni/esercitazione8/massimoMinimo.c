#include<stdio.h>

void maxMin(int *, int *);

int main(){
	int a, b, max, min;
	scanf("%d %d", &a, &b);
	maxMin(&a, &b);
	printf("%d %d", max, min);
	return 0;
}

void maxMin(int* a, int* b){
	int tmp;
	if(a>b){
		tmp = *a;
		*a = *b;
		*b = *a;
	}
}