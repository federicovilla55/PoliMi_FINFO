/* Sono sottointesi la definizione del tipo lista in C
 * e le funzione per inserire, eliminare, visualizzare... 
 * le liste */

Ptr_nodo lista_maggiori(Ptr_nodo l1){
	Ptr_nodo tmp, nl;
	int sum;

	nl = NULL;
	
	while(l1){
		sum = 0;
		tmp = l1->next;

		while(tmp){
			sum += tmp->dato;
			tmp = tmp->next;
		}

		if(sum < l1->dato){
			nl = inserisciCoda(nl, l1->dato);
		}

		l1 = l1->next;
	}

	return nl;
}

/* Errori:
 * - mancanza di inizializzazione a NULL;
 * - usare la malloc
 * - errori algoritmici sulla somma degli elementi sulla lista */
