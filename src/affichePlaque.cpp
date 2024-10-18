//****************************************
//
//              affichePlaque.cpp
//
//****************************************


#include <stdio.h>
#include <cstring>

#include "../inc/plaque.hpp"

void affichePlaque(Plaque *plaque){
    printf("%s-%s-%s\n", plaque->debut, plaque->milieu, plaque->fin);
}
