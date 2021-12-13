#include <stdio.h> 
#include <stdlib.h>  

#define MAX 10

int base8to10(char s[]);

int main(void){
	 char s[MAX];
	 int n;
	 printf("Dimmi un numero in base 8 e te lo converto in base 10: ");
	 scanf("%s", s);
	 n=base8to10(s);
	 printf("Numero in base 10: %d\n", n);

	return 0;
}

int base8to10(char s[]){
	int ris, c, i;
	ris=0;
	c=1;
	for(i=1; s[i]!='\0'; i++)
		c*=8;
	for(i=0; s[i]!='\0' && ris!=-1; i++){
		if(!(s[i]>='0' && s[i]<='8'))
			ris=-1;
		else{
			ris += (s[i]-'0')*c;
			c/=8;
		}
	}

	return ris;
}
