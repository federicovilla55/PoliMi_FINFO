#include<stdio.h>
#include<string.h>
#define N 30
int main(){
	int i, n;
	char path[N], p[N], tmp[N];
	FILE *in;
	printf("Dimmi il nome del file: ");
	scanf("%s", path);
	printf("Dimmi una parola: ");
	scanf("%s", p);
	in = fopen(path, "r");
	
	if(in){
		n = 0;
		while(fscanf(in, "%s ", tmp) > 0){
			if(!strcmp(tmp, p))
					n++;
		}

		printf("Numero di ricorrenze: %d\n", n);
		fclose(in);
	}else{
		printf("Errore");
	}

	return 0;
}
