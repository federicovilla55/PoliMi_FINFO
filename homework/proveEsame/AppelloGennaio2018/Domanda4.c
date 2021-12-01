/* Domanda 4 (…/6 punti)
Scrivere un programma che chiede all’utente una sequenza di lunghezza indefinita di numeri positivi
terminata da un valore non positivo (si consideri che i valori sono inseriti correttamente). Il programma
conta per ciascun valore della sequenza tutti i divisori propri (cioè diversi da 1 e dal valore stesso) e
salva nel file “risultati.txt” su ogni riga la coppia valore e numero divisori propri trovati.
Ad esempio: se l’utente inserisce la sequenza
1 12 8 32 9 -1
Il programma salverà nel file risultati.txt il seguente contenuto:
1 0
12 4
8 2
32 4
9 1  */

#include<stdio.h>
#include<stdlib.h>
typedef struct N{
	int dato;
	struct N *next;
}nodo_t;
typedef nodo_t* ptr_nodo;
int contaDivisoriPropri(int n);
void stampaContenuto(ptr_nodo l, FILE* fp);
int main(){
	ptr_nodo tmp, head;
	FILE *fp;
	int i, n;
	head = NULL;
	tmp = NULL;
	printf("Riempi una lista: ");
	scanf("%d", &n);
	while(n>=0){
		tmp=malloc(sizeof(nodo_t));
		if(tmp){
			tmp->dato = n;
			tmp->next = head;
			head = tmp;
		}else{
			printf("Errore allocazione");
		}
		scanf("%d", &n);
	}
	
	fp = fopen("risultati.txt", "w");
	if(fp){
		stampaContenuto(head, fp);
		fclose(fp);
	}else{
		printf("Errore apertura file...");
	}

	return 0;
}

int contaDivisoriPropri(int n){
	int i, numDivisori;
	numDivisori=0;

	for(i=2; i<=n/2; i++){
		if(n%i==0)
			numDivisori++;
	}
	printf("%d -> %d\n", n, numDivisori);
	return numDivisori;
}

void stampaContenuto(ptr_nodo l, FILE*fp){
	if(l == NULL){
		return;
	}
	stampaContenuto(l->next, fp);
	fprintf(fp, "%d %d\n", l->dato, contaDivisoriPropri(l->dato));
	return;
}
