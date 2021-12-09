typedef struct N{
	int dato;
	struct N *next;
}nodo_t;

typedef nodo_t *Ptr_nodo;

Ptr_nodo rovescia_lista(Ptr_nodo l){
	Ptr_nodo head, succ;
	head = NULL;
	
	while(l){
		succ = l->next;
		l->next = head;
		head = l;
		l = succ;
	}

	return head;
}
