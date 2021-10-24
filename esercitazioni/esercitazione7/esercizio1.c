/*Si scriva un programma in linguaggio C che mostri
a video il nome dello studente che ha ottenuto il
punteggio più alto in un esame.
Il programma dovrà leggere il numero di studenti
iscritti N (con N < 100), il nome (con un numero di
caratteri < 20) e il voto di ciascuno studente.*/
#include<stdio.h>
#include<string.h>
#define M 20
typedef struct{
    char nome[M+1];
    int voto;
} registro_studenti_t;
int main(){
    registro_studenti_t studente, max;
    int N, i;
    do{
        printf("Dimmi il numero di studenti iscritti: ");
        scanf("%d", &N);
    }while(N>=100);
    printf("Dimmi ora il nome e il voto di ciascuno studente: \n");
    scanf("%s %d", max.nome, &max.voto);
    for (i = 1; i < N; i++)
    {
        do{
            scanf("%s %d", studente.nome, &studente.voto);
        }while(studente.voto>30 && studente.voto<0);
        if (studente.voto>max.voto){
            max.voto=studente.voto;
            /*max.nome=studente.nome;*/
            strcpy(max.nome, studente.nome);
        }
    }
    printf("Il miglior student e': %s - %d\n\n", max.nome, max.voto);
    return 0;
    
}