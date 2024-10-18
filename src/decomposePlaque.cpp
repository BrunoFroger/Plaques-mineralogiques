//****************************************
//
//              checkValidite.cpp
//
//****************************************


#include <stdio.h>
#include <cstring>

#include "../inc/plaque.hpp"
#include "../inc/affichePlaque.hpp"

void decomposePlaque(char *plaqueImmat, Plaque *plaque){
    // printf("decomposePlaque %s => debut\n", plaqueImmat);
    strcpy(plaque->debut, "");
    strcpy(plaque->milieu, "");
    strcpy(plaque->fin, "");
    int element=0;
    for (int i = 0 ; i < strlen(plaqueImmat) ; i++){
        char car = plaqueImmat[i];
        if (car == '-'){
            element ++;
        } 
        else {
          switch(element){
            case 0:
                // printf("ajout de %c a debut en position %d\n", car, (int)strlen(plaque->debut));
                plaque->debut[strlen(plaque->debut)+1]='\0';
                plaque->debut[strlen(plaque->debut)]=car;
                //printf("ajout de %c a debut\n", car);
                break;
            case 1:
                // printf("ajout de %c a milieu en position %d\n", car, (int)strlen(plaque->milieu));
                plaque->milieu[strlen(plaque->milieu)+1]='\0';
                plaque->milieu[strlen(plaque->milieu)]=car;
                //printf("ajout de %c a milieu\n", car);
                break;
            case 2:
                // printf("ajout de %c a fin en position %d\n", car, (int)strlen(plaque->fin));
                plaque->fin[strlen(plaque->fin)+1]='\0';
                plaque->fin[strlen(plaque->fin)]=car;
                //printf("ajout de %c a fin\n", car);
                break;
          }
        }
    }
    // affichePlaque(plaque);
    // printf("decomposePlaque => fin\n");
}