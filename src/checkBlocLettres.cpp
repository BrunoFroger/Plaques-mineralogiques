//****************************************
//
//              checkBlocLettres.cpp
//
//****************************************


#include <stdio.h>
#include <cstring>

#include "../inc/checkBlocLettres.hpp"


int checkBlocLettres(char *item, int bloc){
    int result = 0;
    char strBloc[20];
    int casWseul=0;
    if (bloc == BLOC_DROIT) strcpy(strBloc,"droit"); else strcpy(strBloc, "gauche");
    // printf("test bloc %s lettres %s \n", strBloc, item);
    if (strlen(item) != 2 ){
        if (!((bloc == BLOC_GAUCHE) && (strlen(item) == 1) && (item[0] == 'W'))){
            // printf("longeur != 2\n");
            result = -1;
        } else {
            // printf("lng != 2 mais bloc gauche = 'W'\n");
            casWseul=1;
        }
    } 
    if (strcmp(item, "SS") == 0) result = -1;
    if ((bloc == BLOC_DROIT) && (strcmp(item, "WW") == 0)) result = -1;
    if ((item[0] == 'I' || item[1] == 'I')) result = -1;
    if ((item[0] == 'O' || item[1] == 'O')) result = -1;
    if ((item[0] == 'U' || item[1] == 'U')) result = -1;
    if ((item[0] < 'A' || item[0] > 'Z')) result = -1;
    if (casWseul == 0) if ((item[1] < 'A' || item[1] > 'Z')) result = -1;

    // printf("checkBlocLettre : result = %d\n", result);
    return result;
}
