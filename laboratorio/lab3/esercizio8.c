#include<stdio.h>
#include<math.h>
#define N 3
typedef struct{
	int x, y;
}point_t;

int regolare(point_t matrice[][N], int dim);
int dist(point_t p1, point_t p2);

int main(){
	int ris, i, j;
	point_t m[N][N];

	printf("Riempi una matrice %dx%x\n: ", N, N);
	for(i=0; i<N; i++)
		for(j=0; j<N; j++){
			scanf("%d %d", &m[i][j].x, &m[i][j].y);
		}
	
	ris = regolare(m, N);
	printf("Risultato: %d\n", ris);
	return 0;
}

int dist(point_t p1, point_t p2){
	float dist;
	dist = (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);

	return sqrt(dist);
}

int regolare(point_t matrice[][N], int dim){
	float dist_rc, dist_diag;
	int flag, i, j;
	
	dist_diag = 0;
	for(i=0; i<N-1; i++)
		dist_diag += dist(matrice[i][i], matrice[i+1][i+1]);
	
	for(i=0, flag = 1; i <dim && flag; i++){
		dist_rc = 0;
		for(j=0; j<dim-1; j++){
			dist_rc = dist_rc + distanza(matrice[i][j], matrice[i][j+1]); 
		}
		if(dist_rc>=dist_diag){
			flag=0;
		}
	}

	for(j=0; j<dim && flag; j++){
		dist_rc = 0;
		for(i=0; i<dim -1; i++){
			dist_rc = dist_rc + distanza(matrice[i][j], matrice[i+1][j]);
		}
		if(dist_rc >=dist_diag){
			flag = 0;
		}
	}

	return flag;

}
