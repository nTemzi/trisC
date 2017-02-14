//
//  lancementTableau.h
//  trisFinal
//
//  Created by Noureddine TEMZI on 22/01/2017.
//  Copyright © 2017 Noureddine TEMZI. All rights reserved.
//

#ifndef lancementTableau_h
#define lancementTableau_h

#include "fonctionsDeTris.h"





int tempsTableauxTries ( int *tableau, float *tableauTemps, int taille )
{
    
    heapSort(tableau, taille);
    
    if (!isTrie(tableau, taille) )
        return 0 ;
    
    
    tableauTemps[0] = triParInsertion ( tableau, taille );
    
    tableauTemps[1] = triParSelection ( tableau, taille );
    
    tableauTemps[2] = triABulleAmeliore ( tableau, taille );
    
    tableauTemps[3] = shakeSort ( tableau, taille );
    
    tableauTemps[4] = shellSort ( tableau, taille,3 );
    
    tableauTemps[5] = heapSort ( tableau, taille );
    
    tableauTemps[6] = triRapide(tableau, tableau[0], taille);
    
    return 1 ;
    
}

int tempsTableauxNonTries ( int *tableau, float *tableauTemps, int taille )
{
    int tableauCopie [ taille] ;
    
    copieTableau(tableau, tableauCopie, taille);
    
    
    tableauTemps[0] = triParInsertion ( tableauCopie, taille );
    
    if (!isTrie(tableauCopie, taille) )
        return 0 ;
    
    copieTableau(tableau, tableauCopie, taille);
    
    
    tableauTemps[1] = triParSelection ( tableauCopie, taille );
    
    if (!isTrie(tableauCopie, taille) )
        return 0 ;
    
    copieTableau(tableau, tableauCopie, taille);
    
    
    tableauTemps[2] = triABulleAmeliore ( tableauCopie, taille );
    
    if (!isTrie(tableauCopie, taille) )
        return 0 ;
    
    copieTableau(tableau, tableauCopie, taille);
    
    
    tableauTemps[3] = shakeSort ( tableauCopie, taille );
    
    if (!isTrie(tableauCopie, taille) )
        return 0 ;
    
    copieTableau(tableau, tableauCopie, taille);
    
    
    tableauTemps[4] = shellSort ( tableauCopie, taille,3 );
    
    if (!isTrie(tableauCopie, taille) )
        return 0 ;
    
    copieTableau(tableau, tableauCopie, taille);
    
    tableauTemps[5] = heapSort ( tableauCopie, taille );
    
    if (!isTrie(tableauCopie, taille) )
        return 0 ;
    
    
    copieTableau(tableau, tableauCopie, taille);
    
    tableauTemps[6] = triRapide(tableauCopie, tableauCopie[0], taille);

    if (!isTrie(tableauCopie, taille) )
        return 0 ;
    
    return 1; 
}



int moyenneSurDixTableaux ( int *tableau, float *tableauTemps, int taille )

{
    int i ;
    int  tableauCopie [taille] ;
    
    remplissageTableau(tableau, taille);
    
    
    tempsTableauxNonTries ( tableau,  tableauTemps,  taille);
    
    for  ( i = 0 ; i < 9; i++)
    {
        
        remplissageTableau(tableau, taille);

        
        copieTableau(tableau, tableauCopie, taille);
        
        
        tableauTemps[0] += triParInsertion ( tableauCopie, taille );
        
        if (!isTrie(tableauCopie, taille) )
            return 0 ;
        
        
        copieTableau(tableau, tableauCopie, taille);
        
        
        tableauTemps[1] += triParSelection ( tableauCopie, taille );
        
        if (!isTrie(tableauCopie, taille) )
            return 0 ;
        
        
        copieTableau(tableau, tableauCopie, taille);
        
        
        tableauTemps[2] += triABulleAmeliore ( tableauCopie, taille );
        
        if (!isTrie(tableauCopie, taille) )
            return 0 ;
        
        
        
        copieTableau(tableau, tableauCopie, taille);
        
        
        tableauTemps[3] += shakeSort ( tableauCopie, taille );
        
        if (!isTrie(tableauCopie, taille) )
            return 0 ;
        
        
        copieTableau(tableau, tableauCopie, taille);
        
        
        tableauTemps[4] += shellSort ( tableauCopie, taille,3 );
        
        if (!isTrie(tableauCopie, taille) )
            return 0 ;
        
        
        copieTableau(tableau, tableauCopie, taille);
        
        tableauTemps[5] += heapSort ( tableauCopie, taille );
        
        if (!isTrie(tableauCopie, taille) )
            return 0 ;
        
        
        copieTableau(tableau, tableauCopie, taille);
        
        tableauTemps[6] += triRapide(tableauCopie, 0, taille);
        
        if (!isTrie(tableauCopie, taille) )
            return 0 ;
        
        
       
        
    }
    
    for  ( i = 0 ; i < 7; i++)
    {
        
        tableauTemps[i]/=10;
        
    }
    
     return 1; 
}






















#endif /* lancementTableau_h */
