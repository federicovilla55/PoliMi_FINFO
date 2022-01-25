/*(6 punti) Si scriva un programma che legge da un file, il cui nome chiesto all’utente ha lunghezza massima di 30 caratteri, una sequenza (di lunghezza
ignota, anche nulla) di valori interi separati da uno spazio. Il programma calcola per ciascun valore della sequenza tutti i numeri primi minori o
uguali al valore stesso e salva nel file primi.txt su ogni riga la coppia valore e numero dei numeri primi trovati. Ad esempio, se il contenuto
del file è il seguente:
1 12 33 7 9
il contenuto del file primi.txt sarà
1 0
12 5
33 11
7 4
9 4
(2 punti) Scrivere una variante del programma sopra richiesto, che acquisisca da riga di comando il nome del file sia il nome del file iniziale, sia quello
del file in cui salvare il risultato dell’elaborazione. Un’esecuzione, da riga di comando, di esempio è:
contaprimi ./dati.txt ./risultati.txt
Limitarsi alla parte di dichiarazione delle variabili e all’acquisizione dei dati per poter poi procedere nell’algoritmo.*/

#include<stdio.h>

int contaPrimi(int n);
int isPrime(int n);

int main(){
    FILE *in, *out;
    int n;
    char nome[31];

    scanf("%s", nome);
    in = fopen(nome, "r");
    out = fopen("primi.txt", "w");
    if(in && out){
        while(fscanf(in, "%d", &n) > 0){
            fprintf(out, "%d %d \n", n, contaPrimi(n));
            printf("%d %d \n", n, contaPrimi(n));
        }
        fclose(in);
        fclose(out);
    }else{
        printf("Errore apertura file...\n");
    }

    return 0;

}  

/* Variante del programma in cui i numeri sono presi da riga di comando:
int main(int argc, char *argv[]){
    FILE *in, *out;
    int n;
    if(argc == 3){
        in = fopen(argv[1], "r");
        out = fopen(argv[2], "w");
        if(in && out){
            while(fscanf(in, "%d", &n) > 0){
                fprintf(out, "%d %d \n", n, contaPrimi(n));
                printf("%d %d \n", n, contaPrimi(n));
            }
            fclose(in);
            fclose(out);
        }else{
            printf("Errore apertura file...\n");
        }
    }
    return 0;
}
*/

int contaPrimi(int n){
    int i, ris;
    ris = 0;

    for(i=1; i<=n; i++){
        if(isPrime(i))
            ris++;
    }

    return ris;
}

int isPrime(int n){
    int i, ris;
    ris = 1;
    if(n == 0 || n == 1)
        ris = 0;
    for(i=2; i<n && ris; i++){
        if(n%i == 0)
            ris = 0;

    }
    return ris;
}