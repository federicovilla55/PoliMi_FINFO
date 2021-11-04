#include<stdio.h>

#define MAX_LEN 50
#define STUD 30

typedef struct{
	int matricola;
	char nome[MAX_LEN];
	char cognome[MAX_LEN];
	int votoA, votoB;
}esame;

int main(){
	esame esami[STUD];
	int i, min, max, sum, temp; 
	min = 30;
	max = 0;
	sum = 0;
	
	for(i=0; i<STUD; i++){
		/*Inserire dati con scanf e printf*/
		scanf("%s", esame[i].nome); /* ... */
		temp = esami[i].votoA + esami[i].votoB;
		if(max < temp){
			max = temp;
		}
		if(temp < min){
			min = temp;
		}
		sum += temp;
	}
	sum=(sum)/STUD;

	/*Insert here the elements to print  (do a cast operation on sum) ... */
	printf("...");

	
	for(i=0; i<STUD; i++){
		if((esami[i].votoA + esami[i].votoB)>=18 && esami[i].votoA <=8){
			pritnf("%s %s A\n", esami[i].nome, esami[i].cognome);
		}
		/*Lo stesso anche per B*/
	}

	return 0;
}
