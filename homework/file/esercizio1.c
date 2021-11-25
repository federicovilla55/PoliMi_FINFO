#include<stdio.h>
#define DIM 10
int main(){
	FILE *fp;
	int i;
	fp = fopen("ciao.txt", "w");
	if(fp){
		for(i=0; i<DIM; i++)
			fprintf(fp, "%d ", i);
		fclose(fp);	
	}
	return 0;
}
