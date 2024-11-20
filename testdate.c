#include "date.h"
#include <stdio.h>

int main(void) {
    struct sDate test;
    test.annee = 2024;
    test.mois = 06;
    test.heure = 14;
    test.jour = 28;
    test.minute = 14;

    struct sDate prout;
    prout.annee = 2023;
    prout.mois = 06;
    prout.heure = 14;
    prout.jour = 28;
    prout.minute = 14;
    
    struct sDate goulag;
    goulag.annee = 2023;
    goulag.mois = 11;
    goulag.heure = 14;
    goulag.jour = 28;
    goulag.minute = 14;

    struct sDate numan;
    numan.annee = 2024;
    numan.mois = 11;
    numan.heure = 20;
    numan.jour = 06;
    numan.minute = 14;

    char resultat[20];
    
    printf("%d\n", EstValide(test));
    
    printf("%d\n", Compare(test, prout));

    printf("%d\n", Appartient(goulag, prout, test)); // A tester touts les cas

    printf("%d\n", Chevauche(prout, test, goulag, numan)); //A tester touts les cas

    YYYYMMDDTHHMM(resultat, test);
    printf("YYYYMMDDTHHMM: %s\n", resultat);

    
    return 0;
}