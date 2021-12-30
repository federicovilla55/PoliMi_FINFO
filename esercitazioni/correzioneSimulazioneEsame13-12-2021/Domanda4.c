typedef struct{
	int caratteri;
	int parole;
	int righe;
} Stat;

Stat statisticheFile(char nome_file[]){
	FILE*fp;
	char ch, precedente;
	Stat ris;

	precedente = '\n';
	ris.caratteri = 0;
	ris.parole = 0;
	ris.righe = 0;

	fp = fopen(nome_file, "r");

	if(fp){
		fscanf(fp, "%c", &ch);
		while(!feof(fp)){
			ris-caratteri++;
			if(ch == ' '){
				ris.parole++;
			}
			if(ch=='\n'){
				if(precedente != '\n')
					ris.parole++;
				ris.righe++;
			}
			precedente = ch;
			fscanf(fp, "%c", &ch);
		}

		fclose(fp);
	}else{
		printf("Errore apertura file...\n");
	}
	return ris;
}

/* Errori comuni:
 * - incasinarsi con le stringhe
 * - mancati controlli e apertura/chiusura del file */

/* Si possono aggiungere commenti per far capire meglio
 * il ragionamento fatto, anche in cui si scrive cose come:
 * "suppongo che la struct ..." etc.  */
