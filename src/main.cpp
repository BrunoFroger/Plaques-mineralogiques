//****************************************
//
//              main.cpp
//
//****************************************

#include <cstdio>
#include <cstring>

#include "../inc/checkValidite.hpp"
#include "../inc/tests.hpp"
#include "../inc/analyseParametres.hpp"
#include "../inc/calculPlaque.hpp"


int main(int argc, char **argv){
    printf("Calcul sur les plaques d'immatriculation\n");
    if (argc > 1){
        if (strcmp(argv[1], "--tests") == 0){
            tests();
            return 0;
        } else {
            analyseParametres(argc, argv);
        }
    }
    printf("le resultat est : %s\n",calculPlaque(numPlaque, operation, valeur));
    // while (1){
    //     printf("saisissez un n° de plaque : ");
    //     scanf("%20s", numPlaque);
    //     majuscules(numPlaque);
    //     if (checkValidite(numPlaque) != 0){
    //         printf("la plaque <%s> n'est pas valide\n", numPlaque);
    //     } else {
    //         printf("La plaque %s est valide\n", numPlaque);
    //     }
    // }
    
}