#include <stdio.h> 

int main(int argc, char *argv[]){
	
	if(argc == 3){
		printf("Argomenti inseriti: %s %s \n", argv[1], argv[2]);
	}else{
		printf("Inserire due argomenti...\n");
	}

	return 0;
}
