#include<stdio.h>
#define SECTOMIN 60
int main(){
	int sec, min, secRis, minRis;
	scanf("%d%d", &min, &sec);
	secRis = sec;
	minRis = min;
	scanf("%d%d", &min, &sec);
	secRis = secRis + sec;
	minRis = minRis + min + (secRis/SECTOMIN);
	secRis = secRis - ((secRis/SECTOMIN) * SECTOMIN);
	printf("Tempo Totale dei due esperimenti: %d minuti e %d secondi\n", minRis, secRis);
	return 0;
}
