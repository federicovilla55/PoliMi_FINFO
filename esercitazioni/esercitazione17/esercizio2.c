#include<stdio.h>

typedef struct N{
	int val;
	struct N *next;
} nodo_t;
typedef nodo_t* Pr_nodo;

int somma(Ptr_nodo l, int N, int M){
	int s;
	s = 0;
	while(l){ /* l != NULL */
		if(l->val > N && l->val < M){
			s+=l->val;
		}
		l = l->next;
	}

	return s;
}

int somma_ric(Ptr_nodo l, int N, int M){

	if(!l){
		return 0;
	}
	if(l->val > N && l->val < M){
		return (l->val + somma_ric(l->next, N, M));
	}
}

int main(){
	int arr[] = {5, 6, 42, 30, 10};
	Ptr_nodo l;
        l = array_to_list(arr, 5);
        n = nth_node(l, 2);
        printf("%d \n", n->val);
	printf(" somma = %d \n", somma(l, 4, 20));
	return 0;
}
