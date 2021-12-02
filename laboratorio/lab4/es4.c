#include<stdio.h>
#define DIM 15
void convertiNumero(char s[], int *num, int*valido);
int main(){
	char s[DIM+1];
	int sum, num, valido;
	FILE*fp;
	fp = fopen("testo.txt", "r");
	sum=0;

	if(fp){
		while(fscanf(fp, "%s ", s) > 0){
			convertiNumero(s, &num, &valido);
			if(valido){
				sum+=num;
			}
		}
		printf("La somma di tutti i numeri identificati e': %d\n", sum);
		fclose(fp);
	}else{
		printf("Errore apertura file...");
	}

	return 0;
}

void convertiNumero(char s[], int *num, int *valido){
	int i;
	*num=0;
	*valido=1;
	for(i=0; s[i]!='\0' && *valido; i++){
		if(!(s[i]>='0' && s[i]<='9')){
			*valido=0;
		}else{
			*num*=10;
			*num += (s[i]-'0');
		}
	}
}
