//****************************************
//
//              calculPlaque.cpp
//
//****************************************

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include "../inc/plaque.hpp"
#include "../inc/decomposePlaque.hpp"
#include "../inc/affichePlaque.hpp"

char resultatCalcul[25];
char lettres[23]={'A','B','C','D','E','F','G','H','J','K','L','M','N','P','Q','R','S','T','V','W','X','Y','Z'};

char *calculPlaque(char *numPlaque, char operation, int valeur){
    strcpy(resultatCalcul, "");
    Plaque plaque;
    decomposePlaque(numPlaque, &plaque);
    printf("calcul de <%s> <%c> <%d>\n", numPlaque, operation, valeur);
    if (operation == '+'){
        int val = atoi(plaque.milieu);
        while (valeur-- > 0){
            val += 1;
            if (val >= 1000){
                plaque.fin[1]+=1;
                if ((plaque.fin[1] == 'I') || (plaque.fin[1] == 'O') || (plaque.fin[1] == 'U')) plaque.fin[1] += 1;
                val=001;
                if (plaque.fin[1] > 'Z'){
                    plaque.fin[0] += 1;
                    if ((plaque.fin[0] == 'I') || (plaque.fin[0] == '0') || (plaque.fin[0] == 'U')) plaque.fin[0] += 1;
                    plaque.fin[1] = 'A';
                }
                if (plaque.fin[0] > 'Z'){
                    plaque.debut[1] += 1;
                    if ((plaque.debut[1] == 'I') || (plaque.debut[1] == 'O') || (plaque.debut[1] == 'U')) plaque.debut[1] += 1;
                    plaque.fin[0] = 'A';
                }
                if (plaque.debut[1] > 'Z'){
                    plaque.debut[0] += 1;
                    if ((plaque.debut[0] == 'I') || (plaque.debut[0] == 'O') || (plaque.debut[0] == 'U')) plaque.debut[0] += 1;
                    plaque.debut[1] = 'A';
                }
            }
            sprintf(plaque.milieu, "%03d", val);
        }
    }
    affichePlaque(&plaque);
    sprintf(resultatCalcul, "%s-%s-%s", plaque.debut, plaque.milieu, plaque.fin);
    return resultatCalcul;
}

