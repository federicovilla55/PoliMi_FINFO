Ptr_nodo inserisci_in_coda(Ptr_nodo l, int v){
	Ptr_nodo tmp, prec;
	tmp=malloc(sizeof(nodo_t));
	if(tmp){
		tmp->val=v;
		tmp->next=NULL;
		if(l==NULL)
			l=tmp;
		else{
			for(prec=l; prec->next!=NULL; prec=prec->next);

			prec->next=tmp;
		}
	}
    return l;
}


Ptr_nodo selezione(Ptr_nodo l, int sel[]){
    Ptr_nodo ris;
    int i;
    ris = NULL;
    i = 0;

    while(l){
        if(sel[i]){
            ris = inserisci_in_coda(ris, l->val);
        }

        i++;
        l = l->next;
    }

    return ris;
}