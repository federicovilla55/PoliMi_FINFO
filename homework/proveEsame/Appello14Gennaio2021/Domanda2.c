/*Scrivere un sottoprogramma che ricevuto in ingresso un array di valori interi e qualsiasi altro parametro ritenuto strettamente necessario trasmette
al chiamante i) il primo quartile q1, ii) la mediana (o secondo quartile, q2), iii) il terzo quartile q3. I quartili si ottengono dividendo l’insieme di dati
ordinati in 4 parti uguali ed esattamente: a) il primo quartile è il valore che lascia alla sua sinistra il 25% degli elementi; b) il secondo quartile coincide
con la mediana dato che è quello che lascia alla sua sinistra il 50% dei dati, c) il terzo quartile è il valore che lascia il 75% degli elementi a sinistra e
il 25% a destra.*/

void analizzaArray(int a[], int dim, float *d1, float *d2, float *d3){
    int i, j, tmp;

    for(i=0; i<dim; i++){
        for(j=0; j<dim-1; j++){
            if(a[j] > a[j+1]){
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
    if(dim%2 == 0)
        *d2 = (float) (a[dim/2] + a[dim/2 +1]) / 2;
    else
        *d2 = a[dim/2 + 1];
    *d3 = (float) (dim+1)*3/4;
    *d1 = (dim+1)/4;
}