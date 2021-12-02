#include<stdlib.h>

Ptr_nodo rimuoviDuplicati(Ptr_nodo l);

Ptr_nodo rimuoviDuplicati(Ptr_nodo l){
	Ptr_nodo tmp, head;
	if(!l)
		return NULL;
	
	head = l;
	
	while(l->next){
		if(l>val == l->next->val){
			tmp = l->next->next;
			free(l->next);
			l->next = tmp;
		}else{
			l = l->next;
		}
	}
	
	return head;
}
