#include<stdio.h>
#include<string.h>
#define MAX 30
int main(){
	char parola1[MAX+1], parola2[MAX+1];
	int corretto;
	int i, j, len1, len2;
	corretto = 0;
	printf("Inserire parola 1: ");
	scanf("%s", parola1);
	printf("inserisci parola 2: ");
	scanf("%s", parola2);
	
	len1= strlen(parola1);
	len2= strlen(parola2);

	if(len2>len1){
		printf("%s non e' sottostringa di %s", parola2, parola1);
	}
	/* parola1: aaaaacasacccc
	 * parola2: casa*/
	else{
		for(i=0; i<MAX && !corretto; i++)
		{
			if(parola2[0]==parola1[i]){
				corretto = 1;
				for(j=0; j<len2; j++){
					if(parola2[j]!=parola1[i+j]){
						corretto=0;
					}
				}
			}
		}
		if(corretto==1){
			printf("%s e' sottostringa di %s", parola2, parola1);
		}else{
			printf("%s non e' sottostringa di %s", parol2, parola1);
		}
	}
			
	
	
	return 0;
}
