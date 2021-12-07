#ifndef LISTA_H
#define LISTA_H

typedef struct nodo_{
	int dato;
	struct nodo_ *next;
} nodo_t;

typedef nodo_t * Ptr_nodo;

void visualizza(Ptr_nodo);

#endif
