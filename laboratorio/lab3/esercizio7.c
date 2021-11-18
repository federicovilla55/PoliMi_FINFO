#include<stdio.h>
#define DIM 4

int check_array(int a1[], int a2[]);

int main(){
	int ris, i, arr1[DIM], arr2[DIM];
	
	printf("Riempi il primo array: \n");
	for(i=0; i<DIM; i++){
		scanf("%d", &arr1[i]);
	}
	printf("Riempi il secondo array: \n");
	for(i=0; i<DIM; i++)
		scanf("%d", & arr2[i]);
	
	ris = check_array(arr1, arr2);

	if(ris==-1)
		printf("Errore\n");
	else
		printf("Il secondo array deve essere fatto scorrere di %d posizioni verso destra\n", ris);
	
	return 0;
}

int check_array(int a1[], int a2[]){
	int i, pos, j, tmp;
	pos=DIM;
	for(i=0; i<DIM && pos!=-1; i++){
		for(j=0; j<DIM && pos!=-1 && i<pos; j++){
			if(a2[j]==a1[i] && pos == DIM){
				pos = j - i;
				j=DIM-pos;
				printf("Posizione, %d", pos);
			}
			if(pos!=DIM && a2[j]!=a1[i])
				pos=-1;
		}
		if(i>=pos){
			if(a1[i]!=a2[i-pos])
				pos=-1;

		}
	}

	return pos;

}
