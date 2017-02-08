//
//  main.c
//  trisFinal
//
//  Created by Noureddine TEMZI on 22/01/2017.
//  Copyright © 2017 Noureddine TEMZI. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "lancementTableau.h"
#define N 500
#define M 1000
#define L 10000
#define TPS 6


int main(int argc, const char * argv[]) {
    
    
    int tableau500[N] ;
    int tableau1000[M] ;
    int tableau10000[L] ;
    
    
    float tempsTrie500 [TPS];
    float tempsTrie1000 [TPS];
    float tempsTrie10000 [TPS];
    
    
    
    
    remplissageTableau(tableau500, N);
    
    remplissageTableau(tableau1000, M);
    
    remplissageTableau(tableau10000, L);
 
  
    
    
    
    

    
   
    
    printf ( "  le numéro est %d \n", tempsTableauxTries(tableau500, tempsTrie500, N) );
    
    printf ( "  le numéro est %d \n",tempsTableauxTries(tableau1000, tempsTrie1000, M) );
    
    printf ( "  le numéro est %d \n",tempsTableauxTries(tableau10000, tempsTrie10000, L) );
    
    
    affichageTableauTemps(tempsTrie500, TPS);
   
    
    affichageTableauTemps(tempsTrie1000, TPS);
    
    affichageTableauTemps(tempsTrie10000, TPS);
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}
