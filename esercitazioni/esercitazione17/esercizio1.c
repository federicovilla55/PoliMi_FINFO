#include<stdlib.h>
#include<stdio.h>

typedef struct N{
	int val;
	struct N *next;
} nodo_t;

typedef nodo_t* Ptr_nodo;

Ptr_nodo list_create(int v, Ptr_nodo n){
	Ptr_nodo r;
	r = malloc(sizeof(sizeof(nodo_t)));
	if(!r){
		return NULL;
	}

	r->val = v;
	r->next = n;
	return r;
}


Ptr_nodo nth_node(Ptr_nodo lista, int n){
	Ptr_nodo p;
	p = lista;
	while(n>0 && p!=NULL){  /* for(p=lista; n>0 && p; --N){ */
		p = p->next;
		--n;
	}
	return p;
}

Ptr_nodo array_to_list(int v[], int n){
	Ptr_nodo r;
	r = NULL;
	while(n>0){
		n--;
		r = list_create(v[n], r);
	}

	return r;

}

Ptr_nodo concat(Ptr_nodo L1, Ptr_nodo L2){
	Ptr_nodo p;
	if(!L1){
		return L2;
	}
	p = L1;
	while(p->next != NULL){
		p = p->next;
	}
	p->next = L2;

	return L1;
}

Ptr_nodo concat_ric{
	if(!L1){
		return L2;
	}
	L1->next = concat_ric(L1->next, L2);
	return L1;

}

void free_list(Ptr_nodo l){
	Ptr_nodo succ;
	while(l){
		succ = l->next;	
		free(l);
		l = succ;
	}
}

int main(){
	int arr[] = {5, 6, 42, 30, 10};
	Ptr_nodo l, n;
	l = array_to_list(arr, 5); /* sizeof(arr[])*/
	n = nth_node(l, 2);
	printf("%d \n", n->val);
	
	return 0;
}
