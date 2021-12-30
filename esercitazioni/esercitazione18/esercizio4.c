typedef struct N{
	int dato;
	struct N *next;
}nodo_t;

typedef nodo_t * Ptr_nodo;

Ptr_nodo ordina_lista(Ptr_nodo l){
	Ptr_nodo list_ord, tmp, prec_tmp;

	if(l==NULL || l-> next==NULL){
		return l;
	}
	list_ord = ordina_lista(l->next);
	tmp = list_ord;
	while(tmp && tmp->dato < l->dato){
		prec_tmp = tmp;
		tmp = tmp->next;
	}
	if(tmp == list_ord){  /* Inserimento in testa */
		l->next = list_ord;
		return l;
	} else{
		l -> next = tmp;
		prec_tmp->next = l;
		return list_ord;
	}

}
