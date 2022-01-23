/* Le strutture e le funzioni implicitamente usata sono quelle definite a lezione e
 * ne e' consentito l'uso anche senza esplicita dichiarazione */

Ptr_nodo listaValoreSoglia(Ptr_nodo seq, int soglia){
	Ptr_nodo ris;
	ris = NULL;

	while(seq){
		if((soglia*soglia) < seq->val)
			ris = inserisci_in_coda(ris, seq->val);

		seq = seq -> next;
	}


	return Ptr_nodo
}
