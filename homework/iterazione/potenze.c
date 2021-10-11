#include<stdio.h>
int main(){
	int i, n, m;
        float ris;
	ris=1;
	do{
		scanf("%d %d", &n, &m);
	}while(n==0 && m<=0);
	if (m>0){
		for(i=0; i<m; i++){
			ris*=n;	
		}
	}
	else{
		for(i=0; i>m; i--){
			ris=ris/n;
		}
	}
	printf("Risultato: %f \n", ris);
	return 0;	
}
