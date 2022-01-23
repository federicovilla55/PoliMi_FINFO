/*Una applicazionerichiede di scegliere il proprio nome utente nelrispetto di alcuneregole e si vuolerealizzare un programma che acquisisca e verifichi
il nome scelto.
(5 pti) Scrivere il sottoprogramma valido che ricevuti in ingresso il nome scelto (usrname), due interi (min e max) e una stringa (speciali)
verifica che esso rispetti le seguenti regole:
• deve essere di almeno min caratteri,
• non deve superare la lunghezza di max caratteri,
• deve contenere almeno un carattere appartenente ai caratteri presenti nella stringa speciali.
Nel caso in cuitutte leregole sianorispettate, il nome utente scelto è valido e il sottoprogrammarestituisce1, in caso contrario il sottoprogramma
restituisce 0.
Nota: non effettuare elaborazioni inutili e/o inefficienti: la soluzione proposta verrà valutata anche in relazione a questo aspetto.
(4 pti) Scrivere un programma che acquisisce dall’utente una stringa di al più 20 caratteri e verifica che questa contenga un nome utente valido (avvalendosi del sottoprogramma valido), e fino a che non è tale continua a richiederla. Quando le regole sono rispettate il programma chiama il
sottoprogramma StartApp che riceve in ingresso il nome utente (il prototipo è riportato di seguito) e realizza la funzionalità desiderata.
int StartApp(char []);
I vincoli per la validità del nome utente sono una lunghezza compresa nell’intervallo [8, 15] e un insieme dei caratteri speciali costituito da: {’$’,
’#’, ’%’ , ’&’}*/

#include<stdio.h>
#include<string.h>

int valido(char username[], int min, int max, char speciali[]);
int StartApp(char []);

int main(){
    int ris;
    char nome[21];

    do{
        printf("Dimmi uno username: \t");
        scanf("%s", nome);
    }while(!valido(nome, 8, 15, "$#%&"));

    //ris = StartApp(nome);

    return 0;
}

int valido(char username[], int min, int max, char speciali[]){
    int ris, i, j;
    ris = strlen(username)>=min && strlen(username)<=max;

    if(ris){
        ris = 0;
        for(i=0; username[i]!=0 && !ris; i++){
            for(j=0; speciali[j]!='\0' && !ris; j++)
                if(speciali[j] == username[i])
                    ris = 1;
        }
    }

    return ris;

}