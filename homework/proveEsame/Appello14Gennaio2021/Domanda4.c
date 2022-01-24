/*La cerniera è uno schema enigmistico che segue una formula del tipo ZX / YZ = XY, ossia date due stringhe s1 e s2 cerca una sottostringa Z pre-
sente in entrambe, in s1 all’inizio, in s2 alla fine, e se esiste crea una nuova stringa concatenando ciò che avanza da s1 e s2. Per esempio, se s1

= mare e s2 = tema, la sottostringa ma rispetta i vincoli e viene creata la stringa rete; se s1 = flauto e s2 = golf, la sottostringa
t rispetta i vincoli e viene creata la stringa lautogol. Non consideriamo valide soluzioni in cui Y non esista, ossia s2 è una sottostringa di s1,
come per esempio in s1 = autoscuola e s2 = auto.
(5 pti) Scrivere un sottoprogramma cercacerniera che riceve in ingresso due stringhe e restituisce l’indice della posizione in cui comincia in s2
la sottostringa Z, se esiste, -1 se non esiste. Con questa informazione il chiamante potrà creare la stringa risultante. Con riferimento agli esempi
precedenti, se s1 = mare e s2 = tema il sottoprogramma cercacerniera restituisce 2. Naturalmente non è importante in questo
frangente che il vocabolo che risulterebbe dalla cerniera abbia senso in italiano.
(4 pti) Scrivere un sottoprogramma cerniera che riceve in ingresso due stringhe s1 e s2 ed un valore intero inizio. Il sottoprogramma crea e
restituisce una nuova stringa che si ottiene concatenando i caratteri di s1 che seguono la sottostringa di s2 a partire dalla posizione inizio,
ai caratteri di s2 che precedono inizio. Senz’altro il valore di inizio è compatibile con le dimensioni di s1 e s2.

(2 pti) Scrivere un programma che acquisisce da riga di comando due stringhe e calcola, se esiste, la cerniera visualizzandola (chiamando i sotto-
programmi di cui sono state indicate le funzionalità precedentemente). Nel caso in cui la cerniera non esista, il programma non visualizza

nulla.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cercaCerniera(char s1[], char s2[]);
char *cerniera(char s1[], char s2[], int inizio);

int main(int argv, char argc[]){
    int l;

    if(argv == 3){
        l = cercaCerniera(argc[1], argc[2]);
        if(l != -1)
            printf("Cerniera: %s \n", cerniera(argc[1], argc[2], l));
    }else{
        printf("Incorretto numero di argomenti...\n");
    }

    return 0;
}

char *cerniera(char s1[], char s2[], int inizio){
    int i, j, len1, len2;
    char *ris;

    len1 = strlen(s1);
    len2 = strlen(s2);

    ris = (char *) malloc( (len1 + len2) - 2*(len2 - inizio) + 1);

    for(i=(len2-inizio); i<len1; i++){
        ris[i-(len2-inizio)] = s1[i];
    }
    for(j=0; j<inizio; j++){
        ris[j + len1 - (len2 - inizio)] = s2[j];
    }
    ris[(len1 + len2) - 2*(len2 - inizio)] = '\0';

    return ris;
}

int cercaCerniera(char s1[], char s2[]){
    int ris, i, j, len1, len2, valid;

    ris = -1;
    len1 = strlen(s1);
    len2 = strlen(s2);
    valid = 0;

    for(j=0; j<len2 && !valid; j++){
        if(s2[j] == s1[0]){
            valid = 1;
            for(i=0; i<(len2-j-1) && valid; i++){
                if(s2[j+i] != s1[i])
                    valid = 0;
            }
        }
        if(valid)
            ris = j;
    }

    return ris;
}