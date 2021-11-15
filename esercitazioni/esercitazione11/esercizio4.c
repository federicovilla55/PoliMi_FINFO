/*Scrivere una funzione ricorsiva che passata in ingresso una stringa, la stampa
 * con i caratteri in ordine inverso*/

#include<stdio.h>
#define LMAX 10

void stampa_ric_inv(char *p);

int main(){
	char parola[LMAX +1];
	printf("Inserire una parola : \n");
	scanf("%s", parola); 
	/*Volendo leggere un'intera riga bisognava mettere "%[^\n]" */
	stampa_ric_inv(parola);
	printf("\n");
	return 0;
}

void stampa_ric_inv(char *p){
	if(*p == '\0'){
		printf("");
	} else {
		stampa_ric_inv(p+1);
		printf("%c", *p);
		/*stampa_ric(p+1);*/
	}
	
}
