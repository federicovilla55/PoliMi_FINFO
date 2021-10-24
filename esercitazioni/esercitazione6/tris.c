/* Tris
 * Scrivere un programma che implementi una versione semplificata di Tris a due giocatori. d ogni turno, il programma:
 * •    chiede al giocatore 1 di inserire le coordinate della propria giocata;
 * •    inserisce il simbolo del giocatore 1 (‘X’) nella posizione indicata;
 * •    visualizza la griglia di gioco aggiornata;
 * •    controlla se il giocatore 1 ha vinto;
 * •    ripete le stesse operazioni per il giocatore 2 (simbolo ‘O’).
 * Il programma prosegue finché uno dei due giocatori non vince oppure fino a quando viene raggiunto il numero massimo di mosse disponibili. Si assuma che i due giocatori inseriscano sempre coordinate valide.
 * */
#include<stdio.h>

int main(){
	int vinto;
	int nIns, c, t;
	int x, y;
	char tris[3][3];
	char simbolo[2];

	vinto = 0; 
	nIns=0;
	simbolo[0]='X';
	simbolo[1]='O';
	for(c=0; c<3; c++){
		for(t=0; t<3; t++){
			tris[c][t]=' ';
		}
	}
	t=0; /* per indicare i turni */
	while(!vinto && nIns<9){
		do{
			scanf("%d%d", &x, &y);
			/* Volendo si puo' aggiungere che le coordiante
			*  siano valide */
		}while(tris[x][y]!=' ');
		tris[x][y]=simbolo[t];
		nIns++;
		for(c=0; c<3; c++){
			printf("\n %c|%c|%c", tris[c][0], tris[c][1], tris[c][2]); /* 0|X|  */
			if(c<2){
				printf("\n______");
			}
		}

		/* Controllo Vittoria */
		if((tris[0][0] == simbolo[t] && tris[1][1]==simbolo[t] &&
			tris[2][2]==simbolo[t]) || (tris[0][2] == simbolo[t]
			&& tris[1][1]==simbolo[t] && tris[2][0]==simbolo[t])){
			vinto=1;
		}else{
			for(c=0; c<3; c++){
				if((tris[c][0]==simbolo[t] && tris[c][1]==simbolo[t]
					&& tris[c][2]==simbolo[t]) || (tris[0][c]==simbolo[t]
					&& tris[1][c]==simbolo[t] && tris[2][c]==simbolo[t]))
					vinto=1;
			}
		}
		if(!vinto)
			t=(t+1)%2;
	}
	if(vinto){
		printf("Giocatore %d vince la partita\n", t);
	}else{
		printf("Pari\n");
	}

	return 0;
}
