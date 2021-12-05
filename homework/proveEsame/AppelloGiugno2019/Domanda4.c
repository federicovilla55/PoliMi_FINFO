#include<stdio.h>
#include<string.h>
#define MAX_LEN 15

int main(){
	char s[MAX_LEN];
	int i, isNum, len;
	FILE *fp;
	fp = fopen("testo.txt", "r");

	if(fp){
		while(fscanf(fp, "%s", s) >0){
			len = strlen(s);
			isNum = 1;
			for(i=0; i<len && isNum; i++){
				if(!(s[i]>='0' && s[i]<='9'))
					isNum = 0;
			}
			if(isNum)
				printf("%s ", s);
		}
	}else{
		printf("Errore apertura file");
	}
	return 0;
}
