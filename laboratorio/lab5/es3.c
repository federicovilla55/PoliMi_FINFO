#include <stdio.h>  
#define BLKB "\e[40m"
#define REDB "\e[41m"
#define GRNB "\e[42m"
#define YELB "\e[43m"
#define BLUB "\e[44m"
#define MAGB "\e[45m"
#define CYNB "\e[46m"
#define WHTB "\e[47m"
#define BLKT "\e[0;30m"
#define REDT "\e[0;31m"
#define GRNT "\e[0;32m"
#define YELT "\e[0;33m"
#define BLUT "\e[0;34m"
#define MAGT "\e[0;35m"
#define CYNT "\e[0;36m"
#define WHTT "\e[0;37m"
#define reset "\e[0m"

void christmasTree(int rows);

void star(void){
	printf(YELT);
	printf("*");
}
void green(void){
	printf(GRNT);
	printf(" ");
}
void resetS(void){
	printf(reset);
}
int main(){
	int rows;
	printf("Number of rows: ");
	scanf("%d", &rows);
	christmasTree(rows);
	return 0;	
}

void christmasTree(int rows){
	int i, j, dim, half, curr;
	dim = rows*2 -1;
	dim/2;

	for(i=0; i<rows; i++){
		curr = i*2 + 1;
		for(j=0; j<dim; j++){
			if(j<half - curr/2){
				printf(" ");
			}else if (j>=half-curr/2 && j<= half+curr/2){
				if(i==0){
					star();
				}else{
					green();
				}
			}
		}
		resetS();	
		printf("\n");
	}
}
