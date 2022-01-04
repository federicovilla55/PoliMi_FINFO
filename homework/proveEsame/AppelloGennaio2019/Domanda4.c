#include<stdio.h>
#define FILENAME "numero.txt"

int valoriRipetuti(FILE *fp);

int main(){
    FILE *fp;
    fp = fopen(FILENAME, "r");

    if(fp){
        printf("La cifra più comune e': %d \n", valoriRipetuti(fp));
        fclose(fp);
    }else{
        printf("Errore apertura file...\n");
    }
    return 0;
}

int valoriRipetuti(FILE *fp){
    int i, n, max, val, tmp, count;
    if(fscanf(fp, "%d", &n) > 0){
        max = 0;
        val = 0;
        for(i=0; i<10; i++){
            tmp = n;
            count = 0;
            while(tmp > 0){
                if((tmp - (tmp/10)*10) == i)
                    count++;
                
                tmp /= 10;
            }
            if(count > max){
                max = count;
                val = i;
            }
            if(count == max && i > val){
                val = i;
            }
        }
    }else{
        val = -1;
    }
    return val;
}