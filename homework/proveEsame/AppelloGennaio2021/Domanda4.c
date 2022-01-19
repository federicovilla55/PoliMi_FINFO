/*Scrivere un sottoprogramma che riceve in ingresso un array bidimensionale N x N di interi Mat, e
qualsiasi altro parametro ritenuto strettamente necessario e trasmette al chiamante un array
bidimensionale Med in cui ogni elemento Med[i][j] viene ottenuto come media dei valori che
circondano l’elemento Mat[i][j]. Nel contesto di utilizzo del sottoprogramma esiste una direttiva
#define N.
Esempio (con N uguale a 4):
Nella figura sono evidenziati due valori nella matrice Mat. L’elemento in blu si trova in posizione i=0,
j=0. L’elemento corrispondente nella matrice Med (sempre in blu) viene ottenuto come:
Med[0][0]=(Mat[0][1]+ Mat[1][1]+ Mat[1][0])/3.
L’elemento in rosso si trova nella posizione i=2,j=1. L’elemento corrispondente nella matrice Med
(sempre in rosso) viene ottenuto come:
Med[2][1]=(Mat[2][0]+Mat[2][2]+ Mat[1][0]+ Mat[1][1]+ Mat[1][2]+ Mat[3][0]+ Mat[3][1]+
Mat[3][2])/8.*/

#include<stdio.h>
#define N 4
void newMatrice(int Mat[][N], float Med[][N]);

int main(){
    int Mat[N][N], i, j;
    float Med[N][N];

    printf("Riempi una matrice %dx%d: \n", N, N);
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            scanf("%d", &Mat[i][j]);
        }
    }

    newMatrice(Mat, Med);

    printf("Risultato: \n");
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            printf("%f \t", Med[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    return 0;
}

void newMatrice(int Mat[][N], float Med[][N]){
    int i, j, n;
    float tmp;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            tmp = 0;
            n = 0;

            if(i!=0){
                n++;
                tmp+=Mat[i-1][j];
                if(j!=0){
                    n++;
                    tmp+=Mat[i-1][j-1];
                }
                if(j!=N-1){
                    n++;
                    tmp+=Mat[i-1][j+1];
                }
            }

            if(i!=N-1){
                n++;
                tmp+=Mat[i+1][j];
                if(j!=0){
                    n++;
                    tmp+=Mat[i+1][j-1];
                }
                if(j!=N-1){
                    n++;
                    tmp+=Mat[i+1][j+1];
                }
            }
            if(j!=0){
                n++;
                tmp += Mat[i][j-1];
            }
            if(j!=N-1){
                n++;
                tmp += Mat[i][j+1];
            }
            Med[i][j] = (float) tmp/n;
        }
    }
}