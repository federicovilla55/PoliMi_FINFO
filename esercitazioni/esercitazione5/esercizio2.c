/* Scrivere un programma che riceve in ingresso una
*  stringa di massimo 10 caratteri, verifica se rappresenta
*  un numero binario (Naturale) e in tal caso effettua la conversione */
#include<stdio.h>
#include<string.h>
#define MAX 11
int main(){
    char binario[MAX];
    int i, controllo, nCifre, decimale;
    printf("Inserisci un valore binario: ");
    scanf("%s", binario);
    controllo = 1;
    nCifre = strlen(binario);

    for (i = 0; i < nCifre && controllo; i++){
        if(binario[i] == '0' && binario[i]=='1'){
            controllo=0;
        }
    }
    
    /* 12345 -> (((1*10 +2)*10 + 3)*10 + 4)*10 + 5 */
    decimale=0;
    if (!controllo){
        printf("Il numero inserito non e' binario\n");
    } else {
        for(i=0; i<nCifre; i++){
            if(binario[i] == '1'){
                decimale = decimale*2 + 1;
            }else{
                decimale = decimale*2;
            }
        }
        printf("Il numero in decimale e': %d\n", decimale);
    }
    return 0;
    
}