#include<stdio.h>
int main(){
	int n, i, fattoriale;
	fattoriale=1;
	scanf("%d", &n);
	while(n<0){
		printf("Errore, e' stato inserito un numero engativo\n");
		scanf("%d",&n);
	}
	for(i=1; i<=n; i++){
		fattoriale*=i;
	}
	printf("Il fattoriale di %d e': %d\n", n, fattoriale);
	return 0;
}
