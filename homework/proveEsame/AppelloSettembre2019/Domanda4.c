/*Scrivere un programma C che apre un file di testo “ingredienti.txt” contenente gli ingredienti di una
ricetta, in particolare ogni riga contiene il nome dell’ingrediente e la quantità necessaria per una
persona. Il programma chiede all’utente il numero di persone per cui vuole cucinare e il nome
dell’ingrediente richiesto, e stampa a video il nome dell’ingrediente e la quantità richiesta.

Se ad esempio, il file “ingredienti.txt” contiene:
uova 1
zucchero 20
farina 20
il numero di persone è 4 e l’ingrediente è lo zucchero, a video verrà stampato:
zucchero 80*/

#include<stdio.h>
#include<string.h>

#define FILENAME "ingredienti.txt"
#define LEN 30

int main(){
    char ingrediente[LEN+1], s[LEN+1];
    int numP, quant, found;
    FILE *fp;
    fp = fopen(FILENAME, "r");
    printf("Per quante persone? \t");
    scanf("%d", &numP);
    printf("Che ingrediente? \t");
    scanf("%s", ingrediente);

    if(fp){
        found = 0;
        while(!found && fscanf(fp, "%s %d", s, &quant)>0){
            if(strcmp(s, ingrediente) == 0){
                found = 1;
                printf("Ingrediente %s, Quantita': %d \n", ingrediente, quant*numP);
            }
        }
        fclose(fp);
    }else{
        printf("Errore apertura file...\n");
    }
    return 0;
}