#include<stdio.h>
int main(){
    int a, b, j, i;
    do{
        scanf("%d %d", &a, &b); //b lato corto e a lungo
    } while (a<0 && b<0);
    for(i=0; i<b; i++){
        for(j=0; j<a; j++){
            if(i==0 || i==b-1 || j==0 || j==a-1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
    
}