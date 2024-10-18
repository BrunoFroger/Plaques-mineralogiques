//****************************************
//
//              analyseParametres.cpp
//
//****************************************

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include "../inc/checkValidite.hpp"

char numPlaque[20];
char operation;
int valeur;

void majuscules(char *item){
    for (int i = 0 ; i < strlen(item) ; i++){
        if ((item[i] >= 'a') && (item[i] <= 'z')){
            item[i] += 'A' - 'a';
        }
    }
}

void analyseParametres(int argc, char **argv){
    strcpy(numPlaque, "");
    operation=' ';
    if (argc < 4) {
        printf("manque parametres : \n");
        printf("syntaxe %s plaque 'operation' valeur\n", argv[0]);
        printf("             plaque    : AA-999-BB\n");
        printf("             operation : + - \n");
        printf("             valeur    : valeur pour l'operation \n");
        exit(-1);
    }
    strcpy(numPlaque, argv[1]);
    majuscules(numPlaque);
    if (checkValidite(numPlaque) != 0){
        printf("la plaque %s n'est pas valide\n", numPlaque);
        exit(-1);
    }
    operation=argv[2][0];
    valeur=atoi(argv[3]);
}
