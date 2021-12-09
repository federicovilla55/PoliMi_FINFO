typedef struct N{
	int val;
	struct N *next;
}nodo_t;

typedef nodo_t *Ptr_nodo;

Ptr_nodo inserisci_in_testa(int v, Ptr_nodo n);
void free_list(Ptr_nodo l);
int lunghezza_lista(Ptr_nodo l);
