#include<stdio.h>
#include<math.h>
#define N 4

typedef struct{
    int x, y;
} Punto_t;

float distanza( Punto_t a, Punto_t b);
int regolare(Punto_t p[][N]);

int main(){
    Punto_t p[N][N];
    int i, j;

    printf("Riempi una matrice %dx%d di punti: \n", N, N);
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            scanf("%d %d", &p[i][j].x, &p[i][j].y);
        }
    }

    printf("La matrice e' regolare? \t %d\n", regolare(p));

    return 0;
}

float distanza( Punto_t a, Punto_t b){
    float d;
    d = sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
    return d;
}

int regolare(Punto_t p[][N]){
    int i, j, ris;
    float diag, lin, col;
    ris = 1;
    diag = 0;
    for(i=0; i<N-1; i++)
        diag += distanza(p[i][i], p[i+1][i+1]);

    for(i=0; i<N-1 && ris; i++){
        lin = 0;
        col = 0;
        for(j=0; j<N-1; j++){
            lin += distanza(p[i][j], p[i][j+1]);
            col += distanza(p[j][i], p[j+1][i]);
        }

        if(lin >= diag || col >= diag)
            ris = 0;
    }

    return ris;

}