#include<stdio.h>
#define DIM 15

int analizzaStringa(char s[]);

int main(){
	FILE *in, *out;
	char s[DIM];
	in = fopen("testo.txt", "r");
	
	if(in){
		out=fopen("risultato.txt", "w");
		while(fscanf(in, "%s ", s) > 0 && out){
			if(analizzaStringa(s))
				fprintf(out, "%s \n", s);
		}

		fclose(in);
		fclose(out);
	}else{
		printf("Errore apertura file...\n");
	}

	return 0;


}

int analizzaStringa(char s[]){
	int ris, i, notCifra, numInt;
	numInt = 0;
	notCifra = 0;
	ris=0;
	for(i=0; s[i]!='\0' && !ris; i++){
		if(s[i]>='0' && s[i]<='9')
			numInt++;
		else
			notCifra=1;

		ris= (notCifra)&&(numInt>1)&&(i>4);
	}

	return ris;
}
