#include<stdio.h>
int main(){
    char car;
    scanf(" %c", &car);
     while (car<='z' && car>='a'){
        if (car=='z')
            car='a';
        else
            car++;
        printf("Carattere successivo: %c\n", car);
        scanf(" %c", &car);        
    }
    return 0;
    
}