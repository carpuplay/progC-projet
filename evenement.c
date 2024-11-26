#include "date.h"
#include "evenement.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct sEvenement {
    char * titre ;
    struct sDate debut ;
    struct sDate fin ;
};


tEvenement CreerEvenement(const char* titre, struct sDate debut, struct sDate fin){
    if (!EstValide(debut) || !EstValide(fin) || Compare(debut, fin) > 0){
        return NULL;
    }

    tEvenement evenement = (tEvenement)malloc(sizeof(struct sEvenement));
    if (evenement == NULL){
        return NULL;
    }

    evenement->titre = (char*)malloc(sizeof(strlen(titre) + 1));
    if (titre == NULL){
        free(evenement);
        return NULL;
    }
    
    strcpy(evenement->titre, titre);
    evenement->debut = debut;
    evenement->fin = fin;

    return evenement;
}

char* Titre(tEvenement evenement){

    return evenement->titre;
}

struct sDate Debut(tEvenement evenement){

    return evenement->debut;
}

struct sDate Fin(tEvenement evenement){

    return evenement->fin;
}

void DetruitEvenement(tEvenement* pEvenement){
    free((*pEvenement)->titre);
    free(*pEvenement);
}

void AfficheEvenement(tEvenement evenement){
    char resultatD[15];
    char resultatF[15];
    printf("Titre: %s\n", evenement->titre);
    printf("Début: ");
    YYYYMMDDTHHMM(resultatD, evenement->debut);
    printf("Fin: ");
    YYYYMMDDTHHMM(resultatF, evenement->fin);
}