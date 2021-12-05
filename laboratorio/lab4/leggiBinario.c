#include<stdio.h>

int main(){
	FILE*fp;
	int i;
	fp = fopen("ListaInBinario.dat", "rb");
	if(fp){
		while(fread(&i, sizeof(int), 1, fp)>0)
			printf("%d ", i);
	}
	return 0;
}
