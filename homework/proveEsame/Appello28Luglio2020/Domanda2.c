/*Si realizzi un sottoprogramma che riceve in ingresso una stringa s di lunghezza indefinita (0 o più
caratteri) e contenente soltanto sequenze delle lettere 'a' e 'b' minuscole.
Senza modificare la stringa s, il sottoprogramma deve restituire una NUOVA stringa r, costruita come
segue. Si legge la stringa s da sinistra verso destra, e per ogni carattere in s si inseriscono uno o due
caratteri in r secondo le regole seguenti:
- Quando in s compare una lettera 'a', in r si inserisce il carattere 'b'
- Quando in s compare la lettera 'b', in r si inserisce la coppia di caratteri 'ab'
Ad esempio, se s = "a", allora r = "b"; se s ="ab", allora r = "bab"; se s = "abaab", allora r = "babbbab",
se s="", allora r="".*/

#include<stdio.h>
#include<stdlib.h>

char *newStringa(char s[]);

int main(){
    printf("Ecco la nuova stringa: %s \n", newStringa("abaab"));

    return 0;
}

char *newStringa(char s[]){
    char *r;
    int i, j, tmp;
    tmp = 0;

    for(i=0; s[i]!='\0'; i++){
        if(s[i] == 'b')
            tmp++;
    }

    r = (char *) malloc(i + tmp + 1);
    j = 0;

    for(i=0; s[i]!='\0'; i++){
        if(s[i]=='a'){
            r[i+j] = 'b';
        }else{
            r[i+j] = 'a';
            j++;
            r[i+j]='b';
        }
    }
    r[i+j]='\0';

    return r;

}