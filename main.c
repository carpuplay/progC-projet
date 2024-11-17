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
    
    
    printf("%d\n", EstValide(test));
    
    printf("%d\n", Compare(test, prout));
    return 0;
}