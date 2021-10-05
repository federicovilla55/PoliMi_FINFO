//Scrivere un programma in C che acquisito un numero intero visualizza il messaggio
//"positivo", "negativo" o "nullo" in base al valore.
#include<stdio.h>
int main(){
	int num;
	scanf("%d",&num);
	if (num>0){
		if (num==0)
			printf("Il numero inserito e' nullo\n");
		printf("Il numero inserito e' positivo\n");
	}
	else
		printf("Il numero inserito e' negativo\n");
	return 0;
}
