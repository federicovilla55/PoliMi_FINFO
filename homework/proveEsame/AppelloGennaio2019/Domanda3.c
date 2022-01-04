#include<stdio.h>
#include<string.h>
#define MAX 100

void genera(char s[]);

int main(){
    char s[MAX+1];
    strcpy(s, "1x0xx1x");
    genera(s);

    return 0;
}

void genera(char s[]){
    int i, isX;
    isX = 0;
    for(i=0; s[i]!='\0' && !isX; i++){
        if(s[i]=='x'){
            isX = 1;
            s[i]='1';
            genera(s);
            s[i]='0';
            genera(s);
            s[i]='x';
        }
    }

    if(!isX)
        printf("%s \n", s);
}