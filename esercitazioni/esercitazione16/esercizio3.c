/* Si scriva un sottoprogramma che riceve come parametro una stringa (che si garantisce non
essere vuota e formata da qualsiasi carattere ASCII), un intero k e qualsiasi altro parametro
ritenuto necessario, e restituisce una nuova stringa, derivata da quella passata come
parametro conservando i primi k caratteri. Se k è maggiore della lunghezza della stringa
data, la parte rimanente viene completata ripetendo l'ultimo carattere fino al
raggiungimento del valore k.
Esempi :
"L'appetito vien mangiando" e k=10 → "L'appetito"
"0123456789ABCDEF" e k =20 → "0123456789ABCDEFFFFF"  */

/* Memoria dinamica e' fondamentale poiche' la dimensione
 * di k la conosciamo solo a runtime */

char *taglia(char stringa[], int k){
	char *ret;
	int i;
	char last;
	ret = (char *) malloc(sizeof(char) * (k + 1));
	i=0;
	if(!ret){
		return NULL;
	}
	while(k>0 && stringa[i] !='\0'){
		ret[i]= stringa[i];
		++i;
		--k;

	}
	last = stringa[i-1];
	while(k>0){
		ret[i]=last;
		i++;
		k--;
	}
	ret[i] = '\0';
	return ret;
}
