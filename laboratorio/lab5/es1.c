#include <stdio.h>  
#define BLKT "\e[0;30m"
#define REDT "\e[0;31m"
#define GRNT "\e[0;32m"
#define YELT "\e[0;33m"
#define BLUT "\e[0;34m"
#define MAGT "\e[0;35m"
#define CYNT "\e[0;36m"
#define WHTT "\e[0;37m"
#define BLKB "\e[40m"
#define REDB "\e[41m"
#define GRNB "\e[42m"
#define YELB "\e[43m"
#define BLUB "\e[44m"
#define MAGB "\e[45m"
#define CYNB "\e[46m"
#define WHTB "\e[47m"
#define reset "\e[0m"
void redHello();
void greenHello();
int main(void){
	 
	greenHello();
	redHello();
	printf(reset);
	return 0;
}

void greenHello(){
	printf(GRNT);
	printf("Hello");
}

void redHello(){
	printf(REDT);
	printf("Hello");
}
