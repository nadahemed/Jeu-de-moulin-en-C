#include "grille.h"
#include <stdio.h>
void AfficheGrille(){
    int i;
    const char *rouge = "\033[1;31m"; 
    const char *vert = "\033[1;32m";
    const char *bleu = "\033[1;34m";  
    const char *reset = "\033[0m"; 
    const char *rose = "\033[1;35m";    
    const char *violet = "\033[0;35m"; 
    



    printf("%s .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------. \n", rouge);
    printf("| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |\n");
    printf("| |    %s______%s    | || |  %s_______%s     | || |     %s_____%s    | || |   %s_____%s      | || |   %s_____%s      | || |  %s_________%s   | |\n", bleu, rouge, bleu, rouge, bleu, rouge, bleu, rouge, bleu, rouge, bleu, rouge);
    printf("| |  .' %s___%s  |   | || | |_   %s__%s \\    | || |    |_   %s_%s|   | || |  |_   %s_%s|     | || |  |_   %s_%s|     | || | |_   %s___%s  |  | |\n", bleu, rouge, bleu, rouge, bleu, rouge, bleu, rouge, bleu, rouge, bleu, rouge);
    printf("| | / .'   %s\\_|%s   | || |   | |%s__)%s |   | || |      | |     | || |    | |       | || |    | |       | || |   | %s|_%s  \\_|  | |\n", bleu, rouge, bleu, rouge, bleu, rouge);
    printf("| | | |    %s____%s  | || |   |  %s__%s /    | || |      | |     | || |    | |   _   | || |    | |   _   | || |   |  %s_|%s  _   | |\n", bleu, rouge, bleu, rouge, bleu, rouge);
    printf("| | \\ `.___]  %s_|%s | || |  _| |  %s\\_%s  | || |     _| |_    | || |   _| |__/ |  | || |   _| |__/ |  | || |  _| |%s___%s/ |  | |\n", bleu, rouge, bleu, rouge, bleu, rouge);
    printf("| |  `._____%s.'%s   | || | |____| |___| | || |    |_____|   | || |  |________|  | || |  |________|  | || | |_________|  | |\n", bleu, rouge);
    printf("| |              | || |              | || |              | || |              | || |              | || |              | |\n");
    printf("| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |\n");
    printf(" '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' %s\n", reset);




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
        printf(rouge);
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
        printf(rouge);
        printf("*-----------------------------*--------*                        *-----------*---------------------------*\n");
        printf(reset);
        printf(bleu);
        for(i=0;i<4;i++){
            printf("|                             |        |                        |           |                           |\n");

        }
        printf(reset);
        printf(rouge);
        printf("|                             |        *------------*-----------*           |                           |\n");
        printf(reset);
        printf(bleu);
        for(i=0;i<2;i++){
            printf("|                             |                     |                       |                           |\n");

        }
        printf(reset);
        printf(rouge);
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

}