#include <stdio.h>
#include <stdlib.h>
#include "cudd.h"

int main(int argc, char* argv[])
{
    char filename[30];
    DdManager* gbm; /* Global BDD manager. */
    gbm = Cudd_Init(0, 0, CUDD_UNIQUE_SLOTS, CUDD_CACHE_SLOTS, 0); /* Initialize a new BDD manager. */
    DdNode* bdd0, * bdd1, * bdd2, * bdd3, * bdd4, * BDD, * var, * tmp;
    char const* const inames[] = { };
    int i;
    
    /* Long conjunctions*/
    
    bdd0 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
    Cudd_Ref(bdd0); /*Increases the reference count of a node*/

    for (i = 4; i >= 0; i--) {
        var = Cudd_bddIthVar(gbm, i); /*Create a new BDD variable*/
        tmp = Cudd_bddAnd(gbm, var, bdd0); /*Perform AND boolean operation*/
        Cudd_Ref(tmp);
        bdd0 = tmp;
        Cudd_RecursiveDeref(gbm, tmp);
        
    }
    bdd1= Cudd_ReadOne(gbm);
    Cudd_Ref(bdd1); /*Increases the reference count of a node*/

    for (i = 9; i >= 5; i--) {
        var = Cudd_bddIthVar(gbm, i); /*Create a new BDD variable*/
        tmp = Cudd_bddAnd(gbm, var, bdd1); /*Perform AND boolean operation*/
        Cudd_Ref(tmp);
        bdd1 = tmp;
        Cudd_RecursiveDeref(gbm, tmp);
    }
    
    bdd2 = Cudd_ReadOne(gbm);
    Cudd_Ref(bdd2); /*Increases the reference count of a node*/

    for (i = 14 ; i >= 10; i--) {
        var = Cudd_bddIthVar(gbm, i); /*Create a new BDD variable*/
        tmp = Cudd_bddAnd(gbm, var, bdd2); /*Perform AND boolean operation*/
        Cudd_Ref(tmp);
        bdd2 = tmp;
        Cudd_RecursiveDeref(gbm, tmp);
    }

    bdd3 = Cudd_ReadOne(gbm);
    Cudd_Ref(bdd3); /*Increases the reference count of a node*/

    for (i = 19; i >= 15; i--) {
        var = Cudd_bddIthVar(gbm, i); /*Create a new BDD variable*/
        tmp = Cudd_bddAnd(gbm, var, tmp); /*Perform AND boolean operation*/
        Cudd_Ref(tmp);
        bdd3 = tmp;
        Cudd_RecursiveDeref(gbm, tmp);
    }

    bdd4 = Cudd_ReadOne(gbm);
    Cudd_Ref(bdd4); /*Increases the reference count of a node*/

    for (i = 24; i >= 20; i--) {
        var = Cudd_bddIthVar(gbm, i); /*Create a new BDD variable*/
        tmp = Cudd_bddAnd(gbm, var, bdd4); /*Perform AND boolean operation*/
        Cudd_Ref(tmp);
        bdd4 = tmp;
        Cudd_RecursiveDeref(gbm, tmp);
    }

/*  DISjunction of the CONjunctions*/
    BDD = Cudd_ReadLogicZero(gbm);
    Cudd_Ref(BDD); /*Increases the reference count of a node*/

    tmp = Cudd_bddOr(gbm, bdd0, BDD); /*Perform OR boolean operation*/
    Cudd_Ref(tmp);
    BDD = tmp;
    Cudd_RecursiveDeref(gbm, tmp);

    tmp = Cudd_bddOr(gbm, bdd1, BDD); 
    Cudd_Ref(tmp);
    BDD = tmp;
    Cudd_RecursiveDeref(gbm, tmp);

    tmp = Cudd_bddOr(gbm, bdd2, BDD);
    Cudd_Ref(tmp);
    BDD = tmp;
    Cudd_RecursiveDeref(gbm, tmp);

    tmp = Cudd_bddOr(gbm, bdd3, BDD);
    Cudd_Ref(tmp);
    BDD = tmp;
    Cudd_RecursiveDeref(gbm, tmp);

    tmp = Cudd_bddOr(gbm, bdd4, BDD);
    Cudd_Ref(tmp);
    BDD = tmp;
    Cudd_RecursiveDeref(gbm, tmp);
    
    Cudd_PrintDebug(gbm, BDD, 2, 4); /*Print the dd to standard output*/
    printf("Number of paths to non-zero leaf: %lf", Cudd_CountPathsToNonZero(BDD));
    /*Cudd_PrintMinterm(gbm, BDD);*/
    Cudd_Quit(gbm);   
    return 0;
}
