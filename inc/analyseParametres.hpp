//****************************************
//
//              analyseParametres.hpp
//
//****************************************

#include <cstdio>

#ifndef __ANALYSEPARAMETRES__
#define __ANALYSEPARAMETRES__

    extern char numPlaque[20];
    extern char operation;
    extern int valeur;
    void analyseParametres(int argc, char **argv);
    void majuscules(char *item);
#endif
