/*Scrivere un programma che date due parole da tastiera di massimo 30 caratteri, 
verificare se la seconda parola e' una sottostringa (ossia e' presente all'interno) della prima*/
#include<stdio.h>
#include<string.h>
#define MAX 30
int main(){
    char s1[MAX], s2[MAX];
    int lung1, lung2, i, commonWords;
    printf("Dimmi due parole: ");
    scanf("%s", s1);
    scanf("%s", s2);
    lung1=strlen(s1);
    lung2=strlen(s2);
    commonWords=0;
    for(i=0; i<lung1 && commonWords<lung2; i++){
        if(s1[i]==s2[commonWords]){
            commonWords++;
        }else{
            commonWords=0;
        }
    }
    if(commonWords==lung2)
        printf("La seconda parola e' sottostringa della prima\n");
    else
        printf("La seconda parola non e' sottostringa\n");
    return 0;
}
