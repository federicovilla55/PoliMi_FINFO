#include<stdio.h>
#define SECTOMIN 60
int main(){
	int sec, min;
	scanf("%d%d", &min, &sec);
	min = min + (sec / SECTOMIN);
	sec = sec - ((sec/ SECTOMIN) * SECTOMIN);
	printf("Durata effettiva: %d minuti e %d secondi\n", min, sec);
	return 0;
}
