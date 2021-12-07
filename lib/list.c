#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
	Ptr_nodo head;
	head = NULL;

	visualizza(head);

	return 0;
}

void visualizza(Ptr_nodo l){
	while(l){
		printf("%d ", l->dato);
		l = l->next;
	}
}
