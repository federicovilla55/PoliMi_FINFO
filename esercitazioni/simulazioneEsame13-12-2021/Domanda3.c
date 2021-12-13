#include <stdio.h> 
#include <stdlib.h> 

typedef struct N{
	int val;
	struct N *next;
}nodo_t;

typedef nodo_t *Ptr_nodo;

Ptr_nodo inserisci_in_testa(int v, Ptr_nodo n);
Ptr_nodo inserisci_in_coda(int v, Ptr_nodo l);
void visualizza(Ptr_nodo l);
int sommaSucc(Ptr_nodo l);
Ptr_nodo listaSommaSucc(Ptr_nodo l);

int main(void){
	Ptr_nodo head;

	head = inserisci_in_testa(1, head);
	head = inserisci_in_testa(-2, head);
	head = inserisci_in_testa(2, head);
	head = inserisci_in_testa(1, head);
	/* Inizializzo la lista come da foglio della simulazione */
	
	head = listaSommaSucc(head);
	visualizza(head);

	return 0;
}

Ptr_nodo inserisci_in_coda(int v, Ptr_nodo l){
	Ptr_nodo tmp, prec;
	tmp=malloc(sizeof(nodo_t));
	if(tmp){
		tmp->val=v;
		tmp->next=NULL;
		if(l==NULL)
			l=tmp;
		else{
			for(prec=l; prec->next!=NULL; prec=prec->next);

			prec->next=tmp;
		}
	}

	return l;
}

Ptr_nodo inserisci_in_testa(int v, Ptr_nodo n){
	Ptr_nodo r;
	r = malloc(sizeof(nodo_t));
	if(!r){
		return NULL;
	}

	r->val = v;
	r->next = n;
	return r;
}

void visualizza(Ptr_nodo l){
	printf("Lista: ");
	while(l){
		printf("%d ", l->val);
		l = l->next;
	}
}

int sommaSucc(Ptr_nodo l){
	int sum;
	sum=0;
	l=l->next;
	while(l){
		sum+=l->val;
		l=l->next;
	}

	return sum;
}

Ptr_nodo listaSommaSucc(Ptr_nodo l){
	Ptr_nodo ris;
	ris=NULL;

	while(l){
		if(l->val > sommaSucc(l))
			ris = inserisci_in_coda(l->val, ris);

		l=l->next;
	}

	return ris;
}
