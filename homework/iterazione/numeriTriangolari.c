#include<stdio.h>
int main(){
    int i, k, q;
    q=0;
    do{
        scanf("%d", &k);
    }while (k<=0);
    for (i = 1; i <= k; i++)
    {
        q+=i;
        printf("Numero Triangolare: %d \n", q);
    }
    return 0;
    
    
}