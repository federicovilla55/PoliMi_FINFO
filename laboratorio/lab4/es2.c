#include<stdio.h>

int main(){
	int max, n;
	FILE*fp;
	fp=fopen("TEST.txt", "r");
	if(fp){
		if(!feof(fp))
			fscanf(fp, "%d", &max);
		while(fscanf(fp, "%d", &n) > 0){
			if(n>max)
				max = n;
		}


		printf("Il valore massimo presente nel file e': %d\n", max);
	}else{
		printf("Errore apertura file...");
	}
	return 0;
}
