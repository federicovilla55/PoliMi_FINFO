#include<stdio.h>
#include<string.h>
#define MAX 10

int isAnagramma(char s[], char t[]);

int main(){
    char s[MAX+1], t[MAX+1];
    
    /* Inizializzo le due stringhe con due anagrammi */
    strcpy(s, "calendario");
    strcpy(t, "locandiera");
    
    printf("Le due parole sono un anagramma? \t %d \n", isAnagramma(s, t));
    return 0;
}

int isAnagramma(char s[], char t[]){
    int i, j, ris, found;
    if(strlen(s)!=strlen(t))
        ris = 0;
    else{
        found = 1;
        for(i=0; s[i]!='\0' && found; i++){
            found = 0;
            for(j=0; s[j]!='\0' && !found; j++){
                if(s[i] == t[j]){
                    s[i]='-';
                    t[j]='-';
                    found = 1;
                }
            }
        }
        ris = (strcmp(s, t) == 0);
    }

    return ris;
}