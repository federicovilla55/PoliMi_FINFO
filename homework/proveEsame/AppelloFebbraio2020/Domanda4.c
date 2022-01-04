#include<stdio.h>

#define FILENAME "input.txt"

int cifraComune(int n);

int main(){
    FILE * fp;
    int n, c;
    fp = fopen(FILENAME, "r");

    if(fp){
        while(fscanf(fp, "%d", &n) > 0){
            c = cifraComune(n);
            if(c != -1)
                printf("Numero %d \t Cifra piu' comune %d \n", n, c);
        }

        fclose(fp);
    }else{
        printf("Errore apertura file...\n");
    }
    return 0;
}

int cifraComune(int n){
    int i, max, ind, tmp, count;

    max = 0;
    ind = 0;
    for(i=0; i<10; i++){
        count = 0;
        tmp = n;
        while(tmp > 0){
            if((tmp - (tmp/10)*10) == i){
                count++;
            }
            tmp /= 10;
        }

        if(count > max){
            max = count;
            ind = i;
        }
        if(max == count && ind < i){
            ind = i;
        }

    }

    return ind;
}