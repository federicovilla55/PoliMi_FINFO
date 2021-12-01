/* Scrivere un sottoprogramma che ricevuto in ingresso un array di interi a[], e qualsiasi altro parametro
ritenuto necessario, restituisce una lista (il tipo degli elementi della lista list_t va definito) che contiene
solamente gli elementi dell’array il cui valore è maggiore della media; tali valori devono comparire
nella lista nello stesso ordine in cui erano presenti dell’array.
Non è consentito usare funzioni predefinite sulla lista eccetto ListaVuota.
Ad esempio, se l’array in ingresso contiene,
2 4 6 8
la lista creata conterrà:
6-> 8 -|  */

#include<stdio.h>
#include<stdlib.h>
#define DIM 4

typedef struct N{
	int dato;
	struct N *next;
}lista_t;

typedef lista_t* ptr_lista;

float calcolaMedia(int a[]);
ptr_lista *sopraMedia(int a[], int dim);
void visualizza(ptr_lista l);

int main(){
	int a[DIM], i;
	ptr_lista head;
	printf("Riempi un array di %d elementi: ", DIM);
	for(i=0; i<DIM; i++){
		scanf("%d", &a[i]);
	}
	head= sopraMedia(a, DIM);
	visualizza(head);
	while(head){
		head = head->next;
	}
	free(head);
	return 0;
}

ptr_lista *sopraMedia(int a[], int dim){
	ptr_lista head, tmp;
	float media;
	int n, i;
	media = calcolaMedia(a);
	head=NULL;
	tmp = NULL;
	for(i=0; i<dim; i++){
		if(a[i]>media){
			tmp = malloc(sizeof(lista_t));
			if(tmp){
				tmp->dato = a[i];
				tmp->next = head;
				head = tmp;
			}
		}
	}
	return head;
}


float calcolaMedia(int a[]){
	float media;
	int i;
	media = 0;
	for(i=0; i<DIM; i++)
		media+=a[i];
	return (media/DIM);	
}

void visualizza(ptr_lista l){
	if(l){	
		visualizza(l->next);
		printf("%d ", l->dato);
	}else{
		printf("\n");
	}
}
