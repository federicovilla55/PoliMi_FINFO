/*Duplica stringa
 * Si scriva una funzione dup_string in grado di duplicare una stringa. Data una
 * stringa qualsiasi come input, dup_string crea dinamicamente una nuova
 * stringa il cui contenuto è identico a quello della stringa in input e ritorna un
 * puntatore alla copia creata in output.*/

#include<stdio.h>
#include<string.h>

char *dup_string(char *s){
	char *d = malloc((strlen(s) + 1) * sizeof(char));
	if(!d){
		return NULL;	
	}
	

}
