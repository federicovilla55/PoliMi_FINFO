#include<stdio.h>
/*File utile per la creazione di un file che sara' poi usato nel 5° esercizio*/
int main(){
	FILE*fp;
	int a[4];
	a[3] = 8;
	a[2] = 5;
	a[1]=16;
	a[0] = 7;
	fp = fopen("ListaInBinario.dat", "wb");
	fwrite(a, sizeof(int), 4, fp);

	fclose(fp);

	return 0;
}
