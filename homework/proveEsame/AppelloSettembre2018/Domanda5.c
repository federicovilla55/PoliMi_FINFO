/*Scrivere un programma che chiede all’utente una sequenza di lunghezza indefinita di numeri positivi
terminata da un valore non positivo (si garantisce che i valori sono inseriti correttamente) e un valore
intero m. Il programma calcola per ogni numero inserito il risultato della divisione intera per m e del
suo resto e salva nel file “risultati.txt” su ogni riga il valore dato, il risultato della divisone e il resto.
Ad esempio: se l’utente inserisce la sequenza 1 12 8 32 9 -1 e il valore m=3
Il programma salverà nel file risultati.txt il seguente contenuto:
1 0 1
12 4 0
8 2 2
32 10 2
9 3 0*/

#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int val;
    struct N* next;
}nodo_t;
typedef nodo_t* Ptr_nodo;

Ptr_nodo inserisciCoda(Ptr_nodo l, int n);
void visualizza(Ptr_nodo l);

int main(){
    Ptr_nodo head;
    FILE *fp;
    int n, m;
    head = NULL;
    fp = fopen("risultati.txt", "w");

    if(fp){
        printf("Dimmi dei valori numerici: ");
        scanf("%d", &n);
        while(n>0){
            head = inserisciCoda(head, n);
            scanf("%d", &n);
        }
        printf("Dimmi il valore m: ");
        scanf("%d", &m);
        while(head){
            fprintf(fp, "%d %d %d \n", head->val, head->val/m, head->val % m);
            head = head ->next;
        }
        fclose(fp);
    }else{
        printf("Errore apertura file...\n");
    }

    return 0;
}

Ptr_nodo inserisciCoda(Ptr_nodo l, int n){
    Ptr_nodo tmp, tail;
    tail = NULL;
    tmp = NULL;
    tail = malloc(sizeof(nodo_t));
    if(tail){
        tail->next = NULL;
        tail ->val = n;
        if(!l){
            l = tail;
        }else{
            for(tmp = l; tmp->next; tmp = tmp->next);
            tmp->next = tail;
        }
    }
    

    return l;
}

void visualizza(Ptr_nodo l){
    while(l){
        printf("%d -> ", l->val);
        l=l->next;
    }

    printf("\n");
}