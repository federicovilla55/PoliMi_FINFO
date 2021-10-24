/*Dichiarare un tipo di dato per rappresentare una località sulla cartina con 
* latitudine e longitudine e nome (float, float e stringa di massimo trenta caratteri
* inserire 10 diverse località e vedere la distanza massima*/
#include<stdio.h>
#include<math.h>
#define N 30
#define M 10
typedef struct{
    float lat;
    float lon;
    char nome[N+1];
}localita_t;

int main(){
    localita_t locs[M];
    float distanza, max_dist, dist;
    int i, j, indiciMassimaDistanza[2];

    for(i=0; i<M; i++){
        printf("Dimmi il nome della località, la latitudine e la longitudine: ", i+1);
        scanf("%s %f %f", locs[i].nome, &locs[i].lat, &locs[i].lon);
    }

    max_dist=0;

    for(i=0; i<M; i++){
        for (j = i; j < M; j++)
        {
            dist=(locs[i].lat-locs[j].lat)*(locs[i].lat-locs[j].lat) + (locs[i].lon-locs[j].lon)*(locs[i].lon-locs[j].lon);
            dist=sqrt(dist);
            if(dist>max_dist){
                max_dist=dist;
                indiciMassimaDistanza[0]=i;
                indiciMassimaDistanza[1]=j;
            }
        }
        
    }

    printf("\n La distanza massima e' di %f\n", max_dist);
    printf("Le due localita' piu' distanti sono: %s %f %f e %s %f %f\n\n", locs[indiciMassimaDistanza[0]].nome, locs[indiciMassimaDistanza[0]].lat, locs[indiciMassimaDistanza[0]].lon, locs[indiciMassimaDistanza[1]].nome, locs[indiciMassimaDistanza[1]].lat, locs[indiciMassimaDistanza[1]].lon);
    return 0;
}

/* Data:

Concorezzo 1.7665 1.26589
Monza 1.936 1.659
Milano 1.569 2.359
Catanzaro 99.99 99.99
MuskHouse 999.999 999.999
SES 5.698 6.3569
SOS 12.23 98.368
SAS 6.090 8.2146
SUS 4.265 8.568 
SIS 2.665 5.6891


*/