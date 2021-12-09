/* Viene sottointesa la presenza del main che passa le due liste, così come
 * la definizione dei tipi, le funzioni, le librerie...  */

typedef struct N{
	int dato;
	struct N *next;
}nodo_t;

typedef nodo_t *Ptr_nodo;


Ptr_nodo inserisci_in_coda(Ptr_nodo l, int v){
	/* ... */
	return l;
}

Ptr_nodo alternata(Ptr_nodo l1, Ptr_nodo l2){
	Ptr_nodo alt = NULL;
	while(l1 || l2){
		if(l1){
			alt = inserisci_in_coda(alt, l1->dato);
			l1 = l1->next;
		}
		if(l2){
			alt = inserisci_in_coda(alt, l2->dato);
			l2 = l2->next;	
		}
	}

	return alt;
}

