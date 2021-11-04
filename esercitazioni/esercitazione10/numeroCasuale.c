#include<stdio.h>
#include<stdlib.h> 
#include<time.h>

int main(){
    int x, y, z;
    time_t t;

    t=time(NULL);
    printf("%ld\n", t);

    /*srand(42);*/
    
    srand(t);

    /* srand inizializza il generatore di numeri pseudocasuali del c con un numero che gli forniamo
    * La generazione di numeri casuali vera e propria avviene con la funzione rand() 
    * Sono numeri causali che vanno da 0 a RAND_MAX, costante definita nella libreria stdio.h
    * Sono pseudocasuali poiché dipendono dal seme, che in questo caso è 42
    * Per avere una maggiore casualità bisogna cambiare il seme ogni volta, ed un modo per 
    * farlo è usare la libreria time.h che permette di avere molte funzioni sulle date e il tempo
    * time_t è una typedef della libreria e la funzione time da i secondi passati dal 1/1/1970, 
    * l'inizio dell'epoca UNIX*/

    x = rand();
    y= rand();
    z= rand() % 10 + 1;

    /*Per avere dei numeri casuali da 1 a 10 devo fare: rand() % 10 + 1*/
    printf("%d %d %d \n", x, y, z);
    printf("RAND_MAX = %d\n", RAND_MAX);
    return 0;
}