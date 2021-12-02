#include<stdio.h>
#include<stdlib.h>
typedef struct N{
	int val;
	struct N *next;
}nodo_t;
typedef nodo_t* Ptr_nodo;

Ptr_nodo primoPari(Ptr_nodo l);

int main(){
	/* ... */
	return 0;
}

Ptr_nodo primoPari(Ptr_nodo l){
	while(l && l->val % 2){  /*L'ordine delle due condizioni e' importante*/
		l=l->next;
	}

	return l;
}

Ptr_nodo primoPari_ric(Ptr_nodo l){
	if(!l || l->val % 2 == 0){
		return l;
	}
	return primo_pari_ric(l->next);
}
