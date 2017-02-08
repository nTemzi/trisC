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
    
    
    return 1 ;
    
}






























#endif /* lancementTableau_h */
