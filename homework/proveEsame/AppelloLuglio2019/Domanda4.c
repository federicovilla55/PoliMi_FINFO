/* Scrivere un programma C che apre un file di testo “input.txt” contenente una sequenza di lunghezza
indefinita di numeri. Il programma calcola e stampa a video il numero di cifre che compongono il
numero e sono divisori del numero stesso.
Per esempio, se il file input.txt contiene
12
323
45
A video verrà stampato:
2 (1 è divisore di 12, 2 è divisore di 12)
0 (3 e 2 non sono divisori di 323)
1 (4 non è divisore di 45, 5 è divisore di 45)  */

#include<stdio.h>
#define DIM 10

int main(){
	int num, i, c, numDivisori;
	char s[DIM];
	FILE *fp;
	fp = fopen("input.txt", "r");

	if(fp){
		while(fscanf(fp, "%s ", s) > 0){
			numDivisori = 0;
			c = 1;
			num = 0;
			for(i=0; s[i]!='\0'; i++){
				num*=10;
				num+= (s[i]-'0');
			}
			
			for(i=0; s[i]!='\0'; i++){
				if(num % (s[i]-'0') == 0)
					numDivisori++;
			}

			printf("%d \n", numDivisori);
		}
		fclose(fp);
	}else{
		printf("Errore apertura file...\n");
	}
	return 0;
}
