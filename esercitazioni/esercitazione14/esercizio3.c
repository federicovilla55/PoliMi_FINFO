#include<stdio.h>
#define GMAX 30
#define DMAX 8
#define GA 10
#define GB 20
int main(){
	FILE *fp_in, *fp_out;
	int venditeA[GMAX], venditeB[GMAX];
	int sommaA, sommaB, i, ngiorni;
	char date[GMAX][DMAX+1];
	fp_in = fopen("vendite.txt", "r");
	fp_out = fopen("guadagniTotali.txt", "w");

	if(fp_in && fp_out){
		sommaA = 0;
		sommaB = 0;
		
		while(fscanf(fp_in, "%s %d %d", date[i], &venditeA[i], &venditeB[i]) == 3){
			sommaA += venditeA[i];
			sommaB += venditeB[i];
			i++;
		}

		printf("Numero di vendite di A: %d \n", sommaA);
		printf("Nummero di vendite di B: %d\n", sommaB);

		ngiorni = i;

		for(i=0; i<ngiorni; i++){
			fprintf(fp_out, "%s %d \n", date[i], venditeA*GA + venditeB*GB);
		}


	} else {
		printf("Errore apertura file...\n");
	}
	if(fp_in)
		fclose(fp_in);
	if(fp_out)
		fclose(fp_in);
	return 0;
}
