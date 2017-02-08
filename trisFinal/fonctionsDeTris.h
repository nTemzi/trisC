//
//  fonctionsDeTris.h
//  trisFinal
//
//  Created by Noureddine TEMZI on 22/01/2017.
//  Copyright © 2017 Noureddine TEMZI. All rights reserved.
//

#ifndef fonctionsDeTris_h
#define fonctionsDeTris_h

#include "tableauxUtils.h"




void echange ( int* tableau, int m, int n);
float triParInsertion( int* tableau, int taille);
float triParSelection( int* tableau, int taille);
float triABulle (int* tableau, int taille);
float triABulleAmeliore (int* tableau, int taille);
float shakeSort (int* tableau, int taille);
float shellSort ( int* tableau, int taille, int pas);
void placer (int g, int d, int* T);
float heapSort (int* tableau, int taille);
void quickSort ( int* tableau, int premier, int taille);




void echange ( int* tableau, int m , int n)
{
    int tmp ;
    
    tmp = tableau[m];
    tableau[m] = tableau[n];
    tableau[n]= tmp ;
    
}


float triParInsertion( int* tableau, int taille)
{
    clock_t tDebut, tFin ;
    tDebut = clock() ;
    
    
    
    int i, j, tmp ;
    for ( i = 1 ; i < taille; i++)
    {
        tmp = tableau[i];
        j = i - 1 ;
        
        while( j >= 0 && tmp < tableau[j] )
        {
            tableau [j+1] = tableau[j];
            j--;
        }
        
        tableau[j+1] = tmp ;
        
    }
    
    tFin = clock() ;
    
    
    return (float) (tFin - tDebut)/CLOCKS_PER_SEC;
}

float triParSelection( int* tableau, int taille)
{
    int i, j, indice =0 ;
    clock_t tDebut, tFin ;
    
    
    tDebut = clock();
    
    for ( i = (taille - 1)  ; i > 0 ; i --)
    {
        indice = i;
        for ( j = 0 ; j < i ; j++ )
            if ( tableau[j] > tableau[indice])
                indice = j ;
        echange(tableau, indice, i);
    }
    
    tFin = clock() ;
    return (float) (tFin - tDebut)/CLOCKS_PER_SEC;
}


float triABulle (int* tableau, int taille)
{
    int i,j;
    clock_t tDebut, tFin ;
    
    tDebut = clock();
    
    for ( i = 0 ; i < taille ; i++)
        for ( j =0 ; j < (taille-1); j++)
            if ( tableau[j+1] < tableau[j])
                echange(tableau, j+1, j);
    
    tFin = clock() ;
   
    return (float) (tFin - tDebut)/CLOCKS_PER_SEC;
}




float triABulleAmeliore (int* tableau, int taille)
{
    clock_t tDebut, tFin ;
    tDebut = clock();
    
    
    int i;
    int booleenTableauTrie = 0 ;
    int lenght = taille - 1 ;
    
    
    
    
    while (! booleenTableauTrie)
    {
        booleenTableauTrie = 1 ;
        for ( i = 0 ; i < lenght ; i++ )
            if (tableau[i+1] < tableau[i])
            {
                echange(tableau, i+1, i);
                booleenTableauTrie = 0 ;
            }
        
        lenght-- ;
    }
    
    tFin = clock() ;
   
    return (float) (tFin - tDebut)/CLOCKS_PER_SEC;
}


float shakeSort (int* tableau, int taille)
{
    
    
    clock_t tDebut, tFin ;
    
    
    tDebut = clock();
    int i ;
    int booleenTableauTrie = 0 ;
    int debut = 0 ;
    int fin = taille - 1 ;
    
    
    
    while (!booleenTableauTrie)
    {
        booleenTableauTrie = 1 ;
        
        for ( i = debut ; i < fin ; i++)
            if (tableau[i+1] < tableau[i])
            {
                echange(tableau, i+1, i);
                booleenTableauTrie = 0 ;
            }
        
        fin-- ;
        
        for ( i = fin ; i > debut ; i--)
            if (tableau[i] < tableau[i-1])
            {
                echange(tableau, i, i-1);
                booleenTableauTrie = 0 ;
            }
        
        debut++ ;
        
    }
    
    tFin = clock() ;
  
    return (float) (tFin - tDebut)/CLOCKS_PER_SEC;
}


float shellSort ( int* tableau, int taille, int pas)
{
    clock_t tDebut, tFin ;
    
    int i , j , iteration, tmp ;
    int k = 0 ;
    
    
    while ( k < taille/2)
        k = pas * k + 1;
    
    k/=pas ;
    
    tDebut = clock() ;
    
    do
    {
        for ( iteration = 0 ; iteration < k; iteration++)
            
            for ( i = iteration + k ; i < taille; i+=k)
            {
                j = i - k ;
                tmp = tableau[i];
                
                while( j >= iteration && tmp < tableau[j] )
                {
                    tableau [j+k] = tableau[j];
                    j-=k;
                }
                
                tableau[j+k] = tmp ;
                
            }
        k/= pas ;
    }
    while (k > 0);
    
    tFin = clock();

    return (float) (tFin - tDebut)/CLOCKS_PER_SEC;
}


void placer (int g, int d, int* T)
{
    
    int i, j, x, place_trouvee ;
    
    x = T[g];
    i = g ;
    j = 2*g + 1;
    place_trouvee = 0 ;
    
    
    while ( j<=d && !(place_trouvee))
    {
        if (j < d)
            if ( T[j+1] > T[j])
                j = j+1 ;
        
        if ( x > T[j] )
            place_trouvee = 1 ;
        else
        {
            T[i] = T[j];
            i=j;
            j = 2 * i +1 ;
        }
        
        T[i] = x;
        
    }
    
}


float heapSort (int* tableau, int taille)
{
    clock_t tDebut, tFin ;
    tDebut = clock() ;

    int i ;
    
    
    for ( i = taille/2 ; i >= 0 ; i--)
        placer(i, taille-1, tableau);
    
    for ( i = (taille - 1); i > 0 ; i--)
    {
        echange(tableau, 0, i);
        placer(0, i-1, tableau);
    }
    
    tFin = clock();
    
    return (float) (tFin - tDebut)/CLOCKS_PER_SEC;
}

void quickSort (int* tableau, int premier, int taille)
{
    int debut = premier, booleenTrie = 0;
    int fin = taille - 1;
    int pivot ;
    
    pivot = tableau[debut];
    
    
    //   clock_t tDebut, tFin ;
    
    
    
    
    //  tDebut = clock() ;
    
    
    
    
    if (debut >=fin )
        return ;
    
    while ( !booleenTrie)
    {
        
        
        
        while ( tableau[fin] > pivot )
            fin--;
        while ( tableau[debut] < pivot)
            debut++;
        
        if (debut < fin)
        {
            echange(tableau, debut, fin);
            booleenTrie = 0;
        }
        else
            booleenTrie = 1 ;
    }
    
    quickSort( tableau, premier, fin);
    quickSort(tableau, (fin+1), taille);
    
    
    
    
    //  tFin = clock();
    
}


























#endif /* fonctionsDeTris_h */
