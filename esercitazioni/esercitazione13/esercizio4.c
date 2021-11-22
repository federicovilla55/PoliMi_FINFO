#include<stdio.h>
#define NUM_LETTERE 26
#define KEY 13
int main(){
	FILE *fp_input, *fp_output;
	char temp, converted;
	int index;

	fp_input = fopen("input.txt", "r");
	fp_output = fopen("output.txt", "w");

	if(fp_input && fp_output){
		fscanf(fp_input, "%c", &temp);
		while(!feof(fp_input)){
			index = temp - 'a';		
			if(index >=0 && index < NUM_LETTERE){
				converted = (index + KEY ) % NUM_LETTERE + 'a';
			}

			fprintf(fp_output, "%c", converted);
			fscanf(fp_input, "%c", &temp);
		}

		fclose(fp_input);
		fclose(fp_output);

	}else{
		printf("Errore\n");
	}

	return 0;

}
