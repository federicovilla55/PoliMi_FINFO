#include<stdio.h>
int main(){
	float x,a,b;
	scanf("%f %f", &a, &b);
	if (a!=0)
	{
		x = -b/a;
		printf("%f\n", x);
	}else{
		if(b==0)
			printf("indeterminata");
		else
			printf("Impossibile");
	}
	return 0;
}
