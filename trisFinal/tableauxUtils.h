//
//  tableauxUtils.h
//  trisFinal
//
//  Created by Noureddine TEMZI on 22/01/2017.
//  Copyright © 2017 Noureddine TEMZI. All rights reserved.
//

#ifndef tableauxUtils_h
#define tableauxUtils_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void remplissageTableau ( int* tableau, int taille);
void affichageTableau ( int* tableau, int taille);
void copieTableau ( int *tableauOriginal, int *tableauCopie, int tailleTableau);
int isTrie ( int* tableau, int taille);







int isTrie ( int* tableau, int taille)
{
    for ( int i = 0 ; (i < taille - 1) ; i++)
        if (tableau[i+1] < tableau[i])
            return 0 ;
    return 1 ;
}


void remplissageTableau ( int* tableau, int taille)
{
    int i ;
    
    srand(time(NULL));
    
    for (i = 0 ; i < taille; i++)
        tableau[i] = rand() % 101 + 1 ;
}


void affichageTableau ( int* tableau, int taille)
{
    int i ;
    
    printf(" Tableau : [ ");
    for ( i = 0 ; i < taille ; i++)
        printf("%d ", tableau[i]);
    
    printf(" ]\n");
    
}


void affichageTableauTemps ( float* tableau, int taille)
{
    int i ;
    
    printf(" Tableau : [ ");
    for ( i = 0 ; i < taille ; i++)
        printf("%16f ", tableau[i]);
    
    printf(" ]\n");
    
}







void copieTableau ( int *tableauOriginal, int *tableauCopie, int tailleTableau)
{
    int i = 0 ;
    
    for ( i = 0 ; i < tailleTableau; i++)
    {
        
        tableauCopie[i] = tableauOriginal[i];
    }
    
}






















#endif /* tableauxUtils_h */
