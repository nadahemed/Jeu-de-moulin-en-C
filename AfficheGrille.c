#include "grille.h"
void AfficheGrille(){
    int i;
    const char *rouge = "\033[1;31m"; 
    const char *vert = "\033[1;32m";
    const char *bleu = "\033[1;34m";  
    const char *reset = "\033[0m"; 
    const char *rose = "\033[1;35m";    
    const char *violet = "\033[0;35m"; 
    printf(rouge);
    printf("                        ---------------------------------------------------------------\n");
    printf(reset);
    printf(bleu);
    printf("                        <><><><><><><> Bienvenue dans le jeu de moulin  <><><><><><><>\n");
    printf(reset);
    printf(reset);
    printf(rouge);
    printf("                        ---------------------------------------------------------------\n");
    printf(reset);
    printf(rouge);
    printf("*");
    printf(reset);
    printf(bleu);
    for(i=0;i<3;i++){
        
        printf("-----------------");
        
        
        
    }
    printf(reset);
    printf(rouge);
    printf("*");
    printf(reset);
    printf(bleu);
    for(i=0;i<3;i++){
        
         printf("-----------------");
        
    }
    printf(reset);
    printf(rouge);
    printf("*");
    printf(reset);
    printf("\n");
    printf(bleu);
    for (i=0;i<4;i++){
        printf("|                                                   |                                                   |\n");
        

    }
    printf(reset);
        printf(rose);
        printf("|                             *---------------------*-----------------------*                           |\n");
        printf(reset);
        printf(bleu);
        for(i=0;i<2;i++){
            printf("|                             |                     |                       |                           |\n");

        }
        printf("|                             |        *------------*-----------*           |                           |\n");
        printf(reset);
        printf(bleu);
        for(i=0;i<4;i++){
            printf("|                             |        |                        |           |                           |\n");

        }
        printf(violet);
        printf("*-----------------------------*--------*                        *-----------*---------------------------*\n");
        printf(reset);
        printf(bleu);
        for(i=0;i<4;i++){
            printf("|                             |        |                        |           |                           |\n");

        }
        printf(reset);
        printf(rose);
        printf("|                             |        *------------*-----------*           |                           |\n");
        printf(reset);
        printf(bleu);
        for(i=0;i<2;i++){
            printf("|                             |                     |                       |                           |\n");

        }
        printf(reset);
        printf(rose);
         printf("|                             *---------------------*-----------------------*                           |\n");
        printf(reset);
        printf(bleu);
         for (i=0;i<4;i++){
        printf("|                                                   |                                                   |\n");
        

    }
    printf(reset);
    printf(rouge);
    printf("*");
    printf(reset);
    printf(bleu);
    for(i=0;i<3;i++){
        
        printf("-----------------");
        
        
        
    }
    printf(rouge);
    printf("*");
    printf(reset);
    printf(bleu);
    for(i=0;i<3;i++){
        
         printf("-----------------");
        
    }
    printf(reset);
    printf(rouge);
    printf("*");
    printf(reset);
    printf("\n");
    return 0;

}