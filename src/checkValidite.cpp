//****************************************
//
//              checkValidite.cpp
//
//****************************************


#include <stdio.h>

#include "../inc/plaque.hpp"
#include "../inc/decomposePlaque.hpp"
#include "../inc/checkBlocLettres.hpp"
#include "../inc/checkBlocChiffres.hpp"

int checkValidite(char *plaqueImmat){
    int resultBlocDroit = -1;
    int resultBlocMilieu = -1;
    int resultBlocGauche = -1;
    Plaque plaque;
    decomposePlaque(plaqueImmat, &plaque);
    // test validaite debut plaque
    // printf("test bloc debut \n");
    resultBlocGauche = checkBlocLettres(plaque.debut, BLOC_GAUCHE);
    // printf("test bloc milieu \n");
    resultBlocMilieu = checkBlocChiffres(plaque.milieu);
    // printf("test bloc fin \n");
    resultBlocDroit = checkBlocLettres(plaque.fin, BLOC_DROIT);
    if ((resultBlocDroit == 0) && (resultBlocMilieu == 0) && (resultBlocGauche == 0)){
        return 0;
    }
    return -1;
}
