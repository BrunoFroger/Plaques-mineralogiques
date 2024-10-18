//****************************************
//
//              tests.cpp
//
//****************************************

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include "../inc/checkValidite.hpp"
#include "../inc/decomposePlaque.hpp"
#include "../inc/plaque.hpp"
#include "../inc/checkBlocLettres.hpp"
#include "../inc/checkBlocChiffres.hpp"
#include "../inc/calculPlaque.hpp"


int nbTests=0;
int nbOK=0;

void testCheck(){
    // printf("resultat execution test %d : ", nbTests);
    // printf("comparaison nbTests = %d et nbOK = %d\n", nbTests, nbOK);
    if (nbTests > nbOK){
        printf("test %d KO\n", nbTests);
        exit(-1);
    } else {
        printf("Test %d OK\n", nbTests);
    }
}

int tests(void){

    //--------------------------------------------------------------
    printf("test de la fonction decomposePlaque()\n");
    Plaque plaque;
    nbTests++; 
    decomposePlaque((char *)"AB-123-CD", &plaque);
    if ((strcmp(plaque.debut,"AB") == 0 ) &&
        (strcmp(plaque.milieu,"123") == 0 ) &&
        (strcmp(plaque.fin,"CD") == 0 ) ){
            nbOK++;
        } 
    testCheck();
    nbTests++; 
    decomposePlaque((char *)"ABC-1234-DEF", &plaque);
    if ((strcmp(plaque.debut,"ABC") == 0 ) &&
        (strcmp(plaque.milieu,"1234") == 0 ) &&
        (strcmp(plaque.fin,"DEF") == 0 ) ){
            nbOK++;
        } 
    testCheck();
    nbTests++; 
    decomposePlaque((char *)"", &plaque);
    if ((strcmp(plaque.debut,"") == 0 ) &&
        (strcmp(plaque.milieu,"") == 0 ) &&
        (strcmp(plaque.fin,"") == 0 ) ){
            nbOK++;
        } 
    testCheck();
    nbTests++; 
    decomposePlaque((char *)"AA-123", &plaque);
    if ((strcmp(plaque.debut,"AA") == 0 ) &&
        (strcmp(plaque.milieu,"123") == 0 ) &&
        (strcmp(plaque.fin,"") == 0 ) ){
            nbOK++;
        } 
    testCheck();
    //--------------------------------------------------------------
    printf("test de la fonction checkBlocLettres()\n");
    nbTests++; if (checkBlocLettres((char *)"A", BLOC_DROIT) != 0) nbOK++; testCheck();
    nbTests++; if (checkBlocLettres((char *)"A", BLOC_GAUCHE) != 0) nbOK++; testCheck();
    nbTests++; if (checkBlocLettres((char *)"AA", BLOC_DROIT) == 0) nbOK++; testCheck();
    nbTests++; if (checkBlocLettres((char *)"AA", BLOC_GAUCHE) == 0) nbOK++; testCheck();
    nbTests++; if (checkBlocLettres((char *)"WW", BLOC_GAUCHE) == 0) nbOK++; testCheck();
    nbTests++; if (checkBlocLettres((char *)"WW", BLOC_DROIT) != 0) nbOK++; testCheck();
    nbTests++; if (checkBlocLettres((char *)"AO", BLOC_DROIT) != 0) nbOK++; testCheck();
    nbTests++; if (checkBlocLettres((char *)"IB", BLOC_DROIT) != 0) nbOK++; testCheck();
    nbTests++; if (checkBlocLettres((char *)"UW", BLOC_DROIT) != 0) nbOK++; testCheck();
    nbTests++; if (checkBlocLettres((char *)"W", BLOC_GAUCHE) == 0) nbOK++; testCheck();
    nbTests++; if (checkBlocLettres((char *)"ABC", BLOC_GAUCHE) != 0) nbOK++; testCheck();
    nbTests++; if (checkBlocLettres((char *)"ABC", BLOC_DROIT) != 0) nbOK++; testCheck();

    //--------------------------------------------------------------
    printf("test de la fonction checkBlocChiffres()\n");
    nbTests++; if (checkBlocChiffres((char *)"12") != 0) nbOK++; testCheck();
    nbTests++; if (checkBlocChiffres((char *)"123") == 0) nbOK++; testCheck();
    nbTests++; if (checkBlocChiffres((char *)"999") == 0) nbOK++; testCheck();
    nbTests++; if (checkBlocChiffres((char *)"000") != 0) nbOK++; testCheck();
    nbTests++; if (checkBlocChiffres((char *)"012") == 0) nbOK++; testCheck();
    nbTests++; if (checkBlocChiffres((char *)"002") == 0) nbOK++; testCheck();
    nbTests++; if (checkBlocChiffres((char *)"A00") != 0) nbOK++; testCheck();
    nbTests++; if (checkBlocChiffres((char *)"1A0") != 0) nbOK++; testCheck();

    //--------------------------------------------------------------
    printf("test de la fonction checkValidite()\n");
    nbTests++; if (checkValidite((char *)"AEF-326-ZL") != 0) nbOK++; testCheck();
    nbTests++; if (checkValidite((char *)"Ab-326-ZL") != 0) nbOK++; testCheck();
    nbTests++; if (checkValidite((char *)"aB-326-ZL") != 0) nbOK++; testCheck();
    nbTests++; if (checkValidite((char *)"AE-326-ZL") == 0) nbOK++; testCheck();
    nbTests++; if (checkValidite((char *)"SS-326-ZL") != 0) nbOK++; testCheck();
    nbTests++; if (checkValidite((char *)"WW-326-ZL") == 0) nbOK++; testCheck();
    nbTests++; if (checkValidite((char *)"W-326-ZL") == 0) nbOK++; testCheck();
    nbTests++; if (checkValidite((char *)"SS-326-WW") != 0) nbOK++; testCheck();

    //--------------------------------------------------------------
    printf("test de la fonction calculPlaque()\n");
    nbTests++; if (strcmp((calculPlaque((char *)"AE-326-JK", '+', 1)), "AE-327-JK") == 0) nbOK++; testCheck();
    nbTests++; if (strcmp((calculPlaque((char *)"AE-999-JK", '+', 1)), "AE-001-JL") == 0) nbOK++; testCheck();
    nbTests++; if (strcmp((calculPlaque((char *)"AE-999-JZ", '+', 1)), "AE-001-KA") == 0) nbOK++; testCheck();
    nbTests++; if (strcmp((calculPlaque((char *)"AE-999-ZZ", '+', 1)), "AF-001-AA") == 0) nbOK++; testCheck();
    nbTests++; if (strcmp((calculPlaque((char *)"AZ-999-ZZ", '+', 1)), "BA-001-AA") == 0) nbOK++; testCheck();
    nbTests++; if (strcmp((calculPlaque((char *)"AZ-999-ZZ", '+', 1)), "BA-001-AA") == 0) nbOK++; testCheck();
    nbTests++; if (strcmp((calculPlaque((char *)"AA-999-BH", '+', 1)), "AA-001-BJ") == 0) nbOK++; testCheck();
    nbTests++; if (strcmp((calculPlaque((char *)"AA-999-HZ", '+', 1)), "AA-001-JA") == 0) nbOK++; testCheck();
    nbTests++; if (strcmp((calculPlaque((char *)"AH-999-ZZ", '+', 1)), "AJ-001-AA") == 0) nbOK++; testCheck();
    nbTests++; if (strcmp((calculPlaque((char *)"HZ-999-ZZ", '+', 1)), "JA-001-AA") == 0) nbOK++; testCheck();
    nbTests++; if (strcmp((calculPlaque((char *)"AA-999-BN", '+', 1)), "AA-001-BP") == 0) nbOK++; testCheck();
    nbTests++; if (strcmp((calculPlaque((char *)"AA-999-BT", '+', 1)), "AA-001-BV") == 0) nbOK++; testCheck();
    nbTests++; if (strcmp((calculPlaque((char *)"AA-001-AA", '+', 10)), "AA-011-AA") == 0) nbOK++; testCheck();
    nbTests++; if (strcmp((calculPlaque((char *)"AA-990-AA", '+', 10)), "AA-001-AB") == 0) nbOK++; testCheck();
    nbTests++; if (strcmp((calculPlaque((char *)"AA-001-AA", '+', 999)), "AA-001-AB") == 0) nbOK++; testCheck();
    nbTests++; if (strcmp((calculPlaque((char *)"AA-001-AH", '+', 1998)), "AA-001-AK") == 0) nbOK++; testCheck();
    // //--------------------------------------------------------------
    int nbKO = nbTests - nbOK;
    printf("Bilan des tests\n");
    printf("nb tests executés  : %d\n", nbTests);
    printf("nb tests OK        : %d\n", nbOK);
    printf("nb tests KO        : %d\n", nbKO);
    return nbKO;
}