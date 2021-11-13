/* Gioco matematico
 * - tre pioli
 *   - n dischi di dimensioni diverse
 *   - Inizialmente tutti i dischi sono impilati in ordine decrescente
 *   (più piccolo in alto) nel piolo di sinistra
 *   l Scopo del gioco
 *   - Impilare in ordine decrescente i dischi sul piolo di destra
 *   - Senza mai impilare un disco più grande su uno più piccolo
 *   - Muovendo un disco alla volta
 *   - Utilizzando se serve anche il piolo centrale */

#include<stdio.h>

void TowerOfHanoi(int n, int A, int B, int C);

int main(){
	int numDischi, p1, p2, p3;
	
	p1 = 1;  /* Ho utilizzato tre variabili contenenti */
	p2 = 2;  /* l'indice del piolo usato nello spostamento */
	p3 = 3;  /* dei dischi */
	
	printf("Dimmi il numero di dischi: ");
	scanf("%d", &numDischi);

	printf("Ecco le mosse fatte per risolvere il gioco matematico: \n");
	TowerOfHanoi(numDischi, p1, p2, p3);

	return 0;	
}

void TowerOfHanoi(int n, int A, int B, int C){
	if(n>0){
		TowerOfHanoi(n-1, A, C, B);
		printf("Move a Disc from %d to %d\n", A, C);
		TowerOfHanoi(n-1, B, A, C);
	}
}
