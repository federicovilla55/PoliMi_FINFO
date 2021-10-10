#include<stdio.h>
#define MAX 17
#define MIN 31
int main(){
	int n, voto, media, max, min;
	n=0;
	media=0;
	max=MAX;
	min=MIN;
	scanf("%d",&voto);
	while(voto>=18 && voto <=30){
		media+=voto;
		n++;
		if(voto<min)
			min = voto;
		if(voto>max)
			max=voto;
		scanf("%d",&voto);
	}	
	if(n==0)
		printf("Errore\n");
	else{
		media/=n;
		printf("Media: %d\tMassimo: %d\tMinimo: %d\tN voti: %d\n", media, max, min, n);
	}

	return 0;
}
