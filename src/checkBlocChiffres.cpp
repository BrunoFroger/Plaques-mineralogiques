//****************************************
//
//              checkBlocChiffres.cpp
//
//****************************************


#include <stdio.h>
#include <cstring>

int checkBlocChiffres(char *item){
    int result = 0;
    // printf("checkBlocChiffres %s \n", item);
    if (strlen(item) != 3 ) result = -1;
    if (strcmp(item, "000") == 0) result = -1;
    // if ((item[0] == '0' || item[1] == '0')) result = -1;
    if ((item[0] < '0' || item[0] > '9')) result = -1;
    if ((item[1] < '0' || item[1] > '9')) result = -1;
    if ((item[2] < '0' || item[2] > '9')) result = -1;

    // printf("checkBlocChiffres : result = %d\n", result);
    return result;
}
