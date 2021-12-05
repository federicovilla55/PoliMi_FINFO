#include<stdio.h>
#include<stdlib.h>

typedef struct N{
	int dato;
	struct N *next;
}nodo_t;
typedef nodo_t* ptr_nodo;

ptr_nodo listaMedia(ptr_nodo l);
ptr_nodo caricaInteri(char s[]);
void visualizza(ptr_nodo l);
void salvaListaFile(ptr_nodo l, char s[]);
int main(){
	ptr_nodo head;

	/*Inizializzazione Lista
	printf("Dimmi un valore intero: ");
	scanf("%d", &n);
	while(n>=0){
		tmp = malloc(sizeof(nodo_t));
		if(tmp){
			tmp->dato = n; 
			tmp->next = head;
			head = tmp;
		}
		scanf("%d", &n);
	}
	File inizializzazione lista*/	
	head = caricaInteri("ListaInBinario.dat");
	visualizza(head);
	head = listaMedia(head);
	printf("Dopo: ");
	visualizza(head);
	salvaListaFile(head, "ListaInBinario.dat");
	return 0;
}

ptr_nodo caricaInteri(char s[]){
	FILE*fp;
	int n;
	ptr_nodo tmp, l;
	fp=fopen(s, "rb");
	l=NULL;
	tmp=NULL;
	while(fread(&n, sizeof(int), 1, fp)>0){
		tmp = malloc(sizeof(nodo_t));
		if(tmp){
			tmp->dato = n;
			tmp->next = l;
			l = tmp;
		}
	}
	fclose(fp);

	return l;
}

void visualizza(ptr_nodo l){
	printf("Lista: ");
	while(l){
		printf("%d ", l->dato);
		l=l->next;
	}
	printf("\n");
}

ptr_nodo listaMedia(ptr_nodo l){
	ptr_nodo curr;
	int media;
	curr = l;
	while(curr){
		if(curr->next){
			media = (curr->dato + curr->next->dato)/2;
			curr->dato = media;
		}
		curr = curr->next;
	}

	return l;
}

void salvaListaFile(ptr_nodo l, char s[]){
	FILE*fp;
	fp = fopen(s, "wb");

	while(l){
		fwrite(l, sizeof(int), 1, fp);
		l=l->next;
	}
	fclose(fp);	

}
