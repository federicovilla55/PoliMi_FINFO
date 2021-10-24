/*Durata CD
Specificare le strutture dati C necessarie ad un programma per la gestione di
un archivio di CD musicali (al massimo 100). Ogni CD è caratterizzato da:
• un titolo (stringa di al massimo 30 caratteri),
• un autore (stringa di al massimo 30 caratteri),
• un anno di pubblicazione,
• il numero di tracce,
• la durata complessiva (rappresentata in termini di ore, minuti e secondi).
Inoltre, si vuole memorizzare anche il prezzo del disco ed il numero di copie
disponibili per la vendita.
Scrivere poi un programma che acquisisce un numero n di CD e visualizza il
CD con durata massima.*/
#include<stdio.h>
#include<string.h>
#define MAX 30
typedef struct
{
    int ore;
    int minuti;
    int secondi;
} tempo_t;

typedef struct
{
    char titolo[MAX+1];
    char autore[MAX+1];
    int anno;
    int numeroTracce;
    tempo_t durata;
    int prezzo;
    int copie;

} gestione_CD_t;

int main(){
    gestione_CD_t disco, massimo;
    int n, i, durataMax, durataDisco;
    do{
        scanf("%d", &n);
    }while(n<=0);
    scanf("%s %s %d %d %d %d %d %d %d", massimo.titolo, massimo.autore, &massimo.anno, &massimo.numeroTracce, &massimo.durata.ore, &massimo.durata.minuti,
                                            &massimo.durata.secondi, &massimo.prezzo, &massimo.copie);
    durataMax=massimo.durata.secondi+60*(massimo.durata.minuti+60*massimo.durata.ore);
    for(i=1; i<n; i++){
        scanf("%s %s %d %d %d %d %d %d %d", disco.titolo, disco.autore, &disco.anno, &disco.numeroTracce, &disco.durata.ore, &disco.durata.minuti,
                                                &disco.durata.secondi, &disco.prezzo, &disco.copie);
        durataDisco=disco.durata.secondi+60*(disco.durata.minuti+60*disco.durata.ore);
        if(durataDisco>durataMax){
            massimo=disco;
        }
    }
    printf("Disco con durata massima: %s \n", massimo.titolo);
    return 0;
}