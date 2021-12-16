#include <stdio.h>  
#define REDT "\e[0;31m"
#define GRNT "\e[0;32m"
#define REDB "\e[41m"
#define GRNB "\e[42m"
#define reset "\e[0m"

void greenTitle(void);
void redTitle(void);

int main(void){
	redTitle();
	greenTitle();
	printf(reset);
	return 0;
}
void redTitle(void){
	printf(REDB);
	printf(" ");
}
void greenTitle(void){
	printf(GRNB);
	printf(" ");
}
