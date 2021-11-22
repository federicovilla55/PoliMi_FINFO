#include<stdio.h>
#include<string.h>

#define MAX_STRINGA 100

void calcola_diff(char *src_path, char *dst_path);

int main(){
	char src_path[MAX_STRINGA], dst_path[MAX_STRINGA];
	printf("Inserie il path del file di input: ");
	scanf("%s", src_path);
	printf("Path file output: ");
	scanf("%s", dst_path);

	calcola_diff(src_path, dst_path);

	return 0;

}

void calcola_diff(char *src_path, char*dst_path){
	int x, y;
	FILE *src_f;
	FILE *dst_f;

	src_f = fopen(src_path, "r");
	dst_f = fopen(dst_path, "w");

	if(!src_f){
		printf("Errore apertura file input\n");
	}else if(!dst_f)
		printf("Errore apertura file output\n");
	else{
		fscanf(src_f, "%d %d", &x, &y);
		do{
			fprintf(dst_f, "%d \n", (x-y));
		}while(!feof(src_f));
		fclose(src_f);
		fclose(dst_f);

		return;
	}

}
