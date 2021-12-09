typedef struct nodo{
	int val;
	struct nodo *next;
}nodo_t;

typedef nodo_t *Ptr_nodo;

Ptr_nodo k_dalla_fine(Ptr_nodo l, int k){
	int idx;

	idx = lunghezza_lista(l) - k;

	if(idx<0)
		return NULL;

	while(idx > 0){
		l=l->next;
		idx--;
	}

	return l;
}

Ptr_nodo k_dalla_fine2(Ptr_nodo l, int k){
	Ptr_nodo first_k = l;
	
	while(first_k>0){
		first_k = first_k->next;
		k--;
	}
	while(first_k){
		l=l->next;
		first_k = first_k->next;
	}

	return l;
}

int main(){
	Ptr_nodo l;
	l = inserisci_in_testa(1,l);
	l = inserisci_in_testa(5, l);
	l = inserisci_in_testa(42, l);
	l = inserisci_in_testa(3, l);
	printf("%d\n", k_dalla_fine(l,2)->dato);
	free_list(l);
	return 0;

}
