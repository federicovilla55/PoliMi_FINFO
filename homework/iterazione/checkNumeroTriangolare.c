#include<stdio.h>
int main(){
    int i, k, q;
    q=0;
    i=1;
    do{
        scanf("%d", &k);
    }while (k<=0);
    for (;q<k;)
    {
        q+=i;
        i++;
    }
    if (k==q)
    {
        printf("Il numero e' Triangolare");
    }else{
        printf("Il numero NON e' Triangolare");
    }
    return 0;
    
    
}