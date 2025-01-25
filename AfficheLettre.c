#include <stdio.h>
#include <stdlib.h>
#include "grille.h"

 void AfficheLettres(){
    int i;
    const char *rouge = "\033[1;31m"; 
    const char *vert = "\033[1;32m";
    const char *bleu = "\033[1;34m";  
    const char *reset = "\033[0m"; 
    const char *rose = "\033[1;35m";    
    const char *violet = "\033[0;35m"; 
    printf(rouge);
    printf("00");
    printf(reset);
    printf(bleu);
    for(i=0;i<3;i++){
        
        printf("-----------------");
        
        
        
    }
    printf(reset);
    printf(rouge);
    printf("01");
    printf(reset);
    printf(bleu);
    for(i=0;i<3;i++){
        
         printf("----------------");
        
    }
    printf(reset);
    printf(rouge);
    printf("02");
    printf(reset);
    printf("\n");
    printf(bleu);
    for (i=0;i<4;i++){
        printf("|                                                   |                                                   |\n");
        

    }
    printf(reset);
        printf(rouge);
        printf("|                             03--------------------04----------------------05                          |\n");
        printf(reset);
        printf(bleu);
        for(i=0;i<2;i++){
            printf("|                             |                     |                       |                           |\n");

        }
        printf(rouge);
        printf("|                             |        06-----------07----------08          |                           |\n");
        printf(reset);
        printf(bleu);
        for(i=0;i<4;i++){
            printf("|                             |        |                        |           |                           |\n");

        }
        printf(rouge);
        printf("09----------------------------10-------11                     12-----------13--------------------------14\n");
        printf(reset);
        printf(bleu);
        for(i=0;i<4;i++){
            printf("|                             |        |                        |           |                           |\n");

        }
        printf(reset);
        printf(rouge);
        printf("|                             |        15------------16---------17          |                           |\n");
        printf(reset);
        printf(bleu);
        for(i=0;i<2;i++){
            printf("|                             |                     |                       |                           |\n");

        }
        printf(reset);
        printf(rouge);
         printf("|                             18--------------------19----------------------20                          |\n");
        printf(reset);
        printf(bleu);
         for (i=0;i<4;i++){
        printf("|                                                   |                                                   |\n");
        

    }
    printf(reset);
    printf(rouge);
    printf("21");
    printf(reset);
    printf(bleu);
    for(i=0;i<3;i++){
        
        printf("-----------------");
        
        
        
    }
    printf(rouge);
    printf("22");
    printf(reset);
    printf(bleu);
    for(i=0;i<3;i++){
        
         printf("----------------");
        
    }
    printf(reset);
    printf(rouge);
    printf("23");
    printf(reset);



    

}