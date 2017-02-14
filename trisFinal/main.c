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
#define TPS 7

int tableauTest[1000];

int tableau500[N] ;
int tableau1000[M] ;
int tableau10000[L] ;


float tempsTrie500 [TPS];
float tempsTrie1000 [TPS];
float tempsTrie10000 [TPS];


float tempsNonTrie500 [TPS];
float tempsNonTrie1000 [TPS];
float tempsNonTrie10000 [TPS];


void tableauComparatif() ;





int main(int argc, const char * argv[]) {
    
    
    int choix = 0;
    printf("Que voulez vous tester ?\n (0 = Tableau comparatif )\n (1 = Tri par insertion)\n (2 = Tri par sélection)\n (3 = Tri par échange)\n (4 = Shake sort)\n (5 = Shell sort)\n (6 = Heap sort)\n (7 = Quick sort)\n");
    scanf("%d", &choix);
    
    switch (choix) {
        case 0:
            printf("\n == Tableau comparatif == \n");
            tableauComparatif();
            break;
        case 1:
            printf("\n == tri par insertion == \n");
            
            
            remplissageTableau(tableauTest, M) ;
            
            printf(" Le temps  pour le tri par insertion est de : %f \n", triParInsertion ( tableauTest, M ));
            
            if ( isTrie(tableauTest, M))
                 printf( "\n Le tri s'est bien Déroulé ! \n  " ) ;
            break;
        case 2:
            printf(" == tri  selection == \n");
            
            remplissageTableau(tableauTest, M) ;
            
            printf(" Le temps  pour le tri par selection est de : %f \n", triParSelection ( tableauTest, M ));
            
            if ( isTrie(tableauTest, M))
                printf( "\n Le tri s'est bien Déroulé ! \n  " ) ;

            break;
        case 3:
            printf(" == tri à bulles == \n");
          
            remplissageTableau(tableauTest, M) ;
            
            printf(" Le temps  pour le tri à bulles  est de : %f \n", triABulle ( tableauTest, M ));
            
            if ( isTrie(tableauTest, M))
                printf( "\n Le tri s'est bien Déroulé ! \n  " ) ;
            break;
        case 4:
            
            printf(" == SHAKE SORT == \n");
            
            remplissageTableau(tableauTest, M) ;
            
            printf(" Le temps  pour le Shake Sort  est de : %f \n", shakeSort ( tableauTest, M ));
            
            if ( isTrie(tableauTest, M))
                printf( "\n Le tri s'est bien Déroulé ! \n  " ) ;

            break;
        case 5:
            printf(" == ShellSort == \n");
            
            remplissageTableau(tableauTest, M) ;
            
            printf(" Le temps  pour le shell sort est de : %f \n", shellSort (tableauTest, M, 3 ));
            
            if ( isTrie(tableauTest, M))
                printf( "\n Le tri s'est bien Déroulé ! \n  " ) ;

            break;
        case 6:
            printf(" == Heap Sort == \n");
            
            remplissageTableau(tableauTest, M) ;
            
            printf(" Le temps  pour le Heap Sort  est de : %f \n", heapSort ( tableauTest, M ));
            
            if ( isTrie(tableauTest, M))
                printf( "\n Le tri s'est bien Déroulé ! \n  " ) ;

            break;
        case 7:
            printf(" == QUICK SORT ==  \n");
            
            remplissageTableau(tableauTest, M) ;
            
            printf(" Le temps  pour le Quick Sort est de : %f \n", triRapide ( tableauTest, tableauTest[0], M ));
            if ( isTrie(tableauTest, M))
                printf( "\n Le tri s'est bien Déroulé ! \n  " ) ;

            break;
        default:
            printf("Tableau comparatif");
            tableauComparatif(-1);
    }
    
    

    
    
    
    
    
    

    
    
    
    
    return 0;
}



void tableauComparatif()
{
    int i = 0 ;
    
    
    remplissageTableau(tableau500, N);
    
    remplissageTableau(tableau1000, M);
    
    remplissageTableau(tableau10000, L);
    
    
    i+= tempsTableauxTries(tableau500, tempsTrie500, N) ;
    
    i+= tempsTableauxTries(tableau1000, tempsTrie1000, M) ;
    
    i+= tempsTableauxTries(tableau10000, tempsTrie10000, L) ;
    
    
    remplissageTableau(tableau500, N);
    
    remplissageTableau(tableau1000, M);
    
    remplissageTableau(tableau10000, L);
    
    
    i+=  moyenneSurDixTableaux (tableau500, tempsNonTrie500, N) ;
    
    i+= moyenneSurDixTableaux (tableau1000, tempsNonTrie1000,N) ;
    
    i+= moyenneSurDixTableaux (tableau10000, tempsNonTrie10000,N) ;
    
    
    //////////////////////////////////-------------AFFICHAGE ---------------------------/////////////
    
    
    printf("\n");
    printf("                           ____________________________________________________________\n");
    printf("                          |                             |   Tableaux désordonnés       |\n");
    printf("                          |    Tableaux déjà triés      | (moyenne sur 10 tableaux)    |\n");
    printf("                          |_____________________________|______________________________|\n");
    printf("                          |                             |                              |\n");
    printf("                          |   500      1000     10000   |   500      1000     10000    |\n");
    printf(" _________________________|_____________________________|______________________________|\n");
    printf("|            |            |                             |                              |\n");
    printf("| Tri par    | O(n²)      |%5f    %5f    %5f  | %5f    %5f    %5f             |\n",tempsTrie500 [0],tempsTrie1000 [0],tempsTrie10000 [0],tempsNonTrie500 [0],tempsNonTrie1000 [0],tempsNonTrie10000 [0]);
    printf("| Insertion  |            |                             |                              |\n");
    printf("|____________|____________|_____________________________|______________________________|\n");
    printf("|            |            |                             |                              |\n");
    printf("| Tri par    | O(n²)      |%5f    %5f    %5f  | %5f    %5f    %5f               |\n", tempsTrie500 [1],tempsTrie1000 [1],tempsTrie10000 [1],tempsNonTrie500 [1],tempsNonTrie1000 [1],tempsNonTrie10000 [1]);
    printf("| Séléction  |            |                             |                              |\n");
    printf("|____________|____________|_____________________________|______________________________|\n");
    printf("|            |            |                             |                              |\n");
    printf("| Tri par    | O(n²)      |%5f    %5f    %5f  | %5f    %5f    %5f      |\n", tempsTrie500 [2],tempsTrie1000 [2],tempsTrie10000 [2],tempsNonTrie500 [2],tempsNonTrie1000 [2],tempsNonTrie10000 [2]);
    printf("| échange    |            |                             |                              |\n");
    printf("|____________|____________|_____________________________|______________________________|\n");
    printf("|            |            |                             |                              |\n");
    printf("| Shake Sort | O(n²)      |%5f    %5f    %5f  | %5f    %5f    %5f      |\n", tempsTrie500 [3],tempsTrie1000 [3],tempsTrie10000 [3],tempsNonTrie500 [3],tempsNonTrie1000 [3],tempsNonTrie10000 [3]);
    printf("|____________|____________|_____________________________|______________________________|\n");
    printf("|            |            |                             |                              |\n");
    printf("| Shell Sort | O(n¹.²)    |%6lf    %6lf    %6lf   |%6lf    %6lf    %6lf    |\n", tempsTrie500 [4],tempsTrie1000 [4],tempsTrie10000 [4],tempsNonTrie500 [4],tempsNonTrie1000 [4],tempsNonTrie10000 [4]);
    printf("|____________|____________|_____________________________|______________________________|\n");
    printf("|            |            |                             |                              |\n");
    printf("| Heap Sort  | O(n log n) |%6lf    %6lf    %6lf   |%6lf    %6lf    %6lf      |\n", tempsTrie500 [5],tempsTrie1000 [5],tempsTrie10000 [5],tempsNonTrie500 [5],tempsNonTrie1000 [5],tempsNonTrie10000 [5]);
    printf("|____________|____________|_____________________________|______________________________|\n");
    printf("|            |            |                             |                              |\n");
    printf("| Quick Sort | O(n log n) |%6lf    %6lf    %6lf   |%6lf    %6lf    %6lf      |\n", tempsTrie500 [6],tempsTrie1000 [6],tempsTrie10000 [6],tempsNonTrie500 [6],tempsNonTrie1000 [6],tempsNonTrie10000 [6]);
    printf("|____________|____________|_____________________________|______________________________|\n");
    

    
    
    
    if ( i == 6 )
        printf( "\n TOUS LES TRIS SE SONT BIEN Déroulés ! \n  " ) ; 
    
    
    
    
}










