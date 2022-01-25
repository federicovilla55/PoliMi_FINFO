/*(a) Data una matrice di interi N x M chiamiamo fascia di k una sequenza di valori tutti uguali a k che si 
trovano in posizioni consecutive sulla riga e che si può estendere anche su più righe. 
Si scriva un sottoprogramma che riceve in ingresso un array bidimensionale N x N di interi Mat, un 
intero k e qualsiasi altro parametro ritenuto strettamente necessario. La funzione deve restituire la 
lunghezza della prima fascia di k nella matrice (che può essere anche pari a 0, elemento non presente o 
pari a uno).
3
Nel contesto di utilizzo del sottoprogramma esistono le direttive #define N…. e #define M…
Ad esempio, data la seguente matrice Mat e il valore k ==4, i valori evidenziati in grassetto 
costituiscono due fasce di 4. Viene restituita la lunghezza della prima fascia che è 3.
Mat
3 5 2 4
4 4 2 3
1 4 4 4
4 4 4 6
7 3 1 2
(b) A partire dal sottoprogramma precedente, si scriva un nuovo sottoprogramma modificato in 
modo da restituire la fascia di k di lunghezza massima
Facendo riferimento all’esempio precedente, stessa matrice e k ==4 viene restituito il valore 6.*/

#include<stdio.h>

#define N 4
#define M 5

int contaFascia(int mat[][N], int k);
int maxFascia(int mat[][N], int k);

int main(){
    int a[M][N], i, j;
    printf("Inserisci una matrice %dx%d: \n", M, N);
    for(i=0; i<M; i++)
        for(j=0; j<N; j++)
            scanf("%d", &a[i][j]);
    
    printf("La prima fascia trovata e' di %d elementi\n", contaFascia(a, 4));
    printf("La fascia massima e' di %d elementi\n", maxFascia(a, 4));

    return 0;
}

int contaFascia(int mat[][N], int k){
    int i, j, isFascia, ris;
    ris = 0;
    isFascia = 0;
    for(i=0; i<M && !(ris!=0 && isFascia==0); i++){
        for(j=0; j<N && !(ris!=0 && isFascia==0); j++){
            if(mat[i][j] == k){
                if(!isFascia){
                    isFascia = 1;
                }
                ris++;
            }else{
                if(isFascia){
                    isFascia = 0;
                }
            }
        }
    }
    return ris;
}

int maxFascia(int mat[][N], int k){
    int i, j, tmp, ris;
    
    ris = 0;

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if(mat[i][j] == k){
                tmp++;
            }else{
                if(tmp){
                    if(tmp > ris)
                        ris = tmp;                
                    tmp = 0;
                }
            }
        }
    }
    if(tmp > ris)
        ris = tmp;
    return ris;
}