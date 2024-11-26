#include "date.h"

#include <stdio.h>

typedef unsigned long long tresLong;
typedef long long tresLongNormal;

int estBisextile(int annee) {
    if (annee % 400 == 0){
        return 1;
    }
    else if(annee % 100 == 0){
        return 0; 
    }
    else if(annee % 4 == 0){
        return 1;
    }

    return 0;
}

int EstValide(const struct sDate date) {
    unsigned char joursMois[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if (date.annee < 0) {
        return 0;
    }
    
    if (date.mois > 12 || date.mois == 0) {
        return 0;
    }
    
    if (estBisextile(date.annee)) {
        joursMois[1] = 29;
    }
    
    if (date.jour > joursMois[date.mois - 1]) {
        return 0;
    }

    if (date.heure >= 24) {
        return 0;
    }

    if (date.minute >= 60) {
        return 0;
    }
    
   return 1;
}

void convertisseur(const struct sDate dateToConv, tresLong * variable) {
    tresLong dateConv = 0;
    // Je met (tresLong) car sinon le resultat de la multiplication d'un int avec un int donne un int et non un long long.
    dateConv += dateToConv.annee * (tresLong) 100000000;
    dateConv += dateToConv.mois *  (tresLong) 1000000;
    dateConv += dateToConv.jour *  (tresLong) 10000;
    dateConv += dateToConv.heure * (tresLong) 100;
    dateConv += dateToConv.minute;
    *variable = dateConv;
}

int Compare(const struct sDate reference, const struct sDate autreDate){
    tresLong referenceConv = 0;
    tresLong autreDateConv = 0;

    convertisseur(reference, &referenceConv);
    convertisseur(autreDate, &autreDateConv);

    tresLongNormal totalConv = referenceConv - autreDateConv;

    if (totalConv > 0){
        return 1;
    } 
    else if (totalConv < 0){
        return -1;
    }
    else{
        return 0;
    }
}

int Appartient(const struct sDate date, const struct sDate debut, const struct sDate fin){
    if (Compare(debut, date) <= 0 && Compare(date, fin) <= 0){
        return 1;
    }
    else{
        return 0;
    }
}

int Chevauche(const struct sDate debut1, const struct sDate fin1, const struct sDate debut2, const struct sDate fin2){

    if (Appartient(debut2, debut1, fin1) || Appartient(fin2, debut1, fin1)){
        return 1;
    }
    else{
        return 0;
    }
}

void YYYYMMDDTHHMM(char* destination, const struct sDate date){
    sprintf(destination, "%04d%02d%02dT%02d%02d", date.annee, date.mois, date.jour, date.heure, date.minute);
    destination[15] = '\0';
}

