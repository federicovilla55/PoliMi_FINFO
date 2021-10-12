#include<stdio.h>
#include<string.h>
#define DIM 50
int main(){
	char str[DIM];
	int i, len, max, count;
	max = 0;
	printf("Dimmi una frase: ");
	scanf("%[^\n]s", str);
	len = strlen(str);
	for(i=0; i<len; i++){
		if (str[i]==' '){
			if(count>max)
				max=count;
			count=0;
		}else{
			count++;
		}
	}
	
	
	printf("\nLa parola con lunghezza maggiore e' lunga: %d caratteri\n", max);
}
