#include<stdio.h>
#include<stdlib.h>

typedef struct N{
	float val;
	struct N *next;
} nodo_t;

typedef nodo_t *Ptr_nodo;

float media(Ptr_nodo l);
void visualizza(Ptr_nodo l);
Ptr_nodo inserisci_in_testa(float v, Ptr_nodo n);

int main(){
	int i;
	float n, mean;
	Ptr_nodo l, l2, tmp;

	l=NULL;

	/* Inizializzazione inserendo dei valori positivi */
	printf("Dimmi dei numeri in virgola mobile: ");
	scanf("%f", &n);
	while(n>=0){
		tmp = malloc(sizeof(nodo_t));
		if(tmp){
			tmp->val = n;
			tmp->next = l;
			l=tmp;
		}
		scanf("%f", &n);
	}
	/* Fine inizializzazione lista  */

	mean = media(l);
	l2=NULL;
	while(l){
		if(l->val > mean){
			l2 = inserisci_in_testa(l->val, l2);
		}
		l=l->next;
	}

	visualizza(l2);

	return 0;
}


float media(Ptr_nodo l){
	float media;
	int i;
	i=0;
	media=0;
	
	while(l){
		media+=l->val;
		i++;
		l=l->next;
	}

	media/=i;
	return media;
}

void visualizza(Ptr_nodo l){
	printf("Lista: ");
	while(l){
		printf("%f ", l->val);
		l=l->next;
	}
	printf("\n");
}

Ptr_nodo inserisci_in_testa(float v, Ptr_nodo n){
	Ptr_nodo r;
	r = malloc(sizeof(nodo_t));
	if(!r){
		return NULL;
	}

	r->val = v;
	r->next = n;
	return r;
}
