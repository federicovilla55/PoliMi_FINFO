#include<stdio.h>

int main(){
	FILE* in;
	FILE* out;
	int n1, n2, diff;

	in = fopen("numeri.txt", "r");
	out = fopen("differenze.txt", "w");
	
	if(in || out){
		printf("Apertura corretta");
		while(fscanf(in, "%d %d", &n1, &n2)>0){
			diff = n1 - n2;
			fprintf(out, "%d \n", diff);
		}	
		fclose(in);
		fclose(out);
	}else{
		printf("Errore");
	}

	return 0;
}
