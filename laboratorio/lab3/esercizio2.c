#include<stdio.h>
#include<string.h>
#define DIM 30
int main(){
	char str[DIM];
	int i, numVocali;
	printf("Dimmi una stringa: ");
	scanf("%s", str);

	i=0;
	numVocali=0;

	while(str[i]!='\0'){
		
		if(toupper(str[i]) == 'A' || toupper(str[i]) == 'E' || toupper(str[i]) == 'I' 
				|| toupper(str[i]) == 'O' || toupper(str[i]) == 'U'){
			numVocali++;
		}

		i++;
	}

	printf("Il numero di vocali e': %d\n", numVocali);

	return 0;
}
