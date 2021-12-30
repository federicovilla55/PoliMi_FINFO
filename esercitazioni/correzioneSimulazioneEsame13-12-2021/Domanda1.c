#define BASE 8

int converti(char ott[]){
	int n, i, pot, cifra;
	
	i = strlen(ott);
	i--;
	n=0;

	for(pot = 1; i>=0 && n!=-1; pot*=BASE){
		if(ott[i]>='0' && ott[i]<='7'){
			cifra = ott[i]-'0';
			n += pot*cifra;
		}else{
			n = -1;
		}
		i--;
	}

	return n;
}


/* Primo esercizio che valeva 7 punti.
 * Errori gravi:
 * - passare la dimensione di ott, ex. (char ott[6]){
 * - fare 10 if per fare la conversione numero base 8 -> base 10
 * - usare la funzione atoi che richiede una stringa e non un carattere
 * - fare il cast dal carattere a int.  */
