#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "grille.h"

void regles(){
    int j;
    const char *rouge = "\033[1;31m"; 
    const char *vert = "\033[1;32m";
    const char *bleu = "\033[1;34m";  
    const char *reset = "\033[0m"; 
    const char *rose = "\033[1;35m";    
    const char *violet = "\033[0;35m"; 
    printf(bleu);
    printf(" ____________________________________________________________________________\n");
    for (j=0;j<6;j++){
        printf("|                                                                           | \n");
    }
    printf(reset);
    printf(rouge);
    printf("|                1-La pose puis le mouvememt                                |\n");
    sleep(1);
    printf("|                2-Choisir l'un des lettres pour poser le pion              |\n");
    sleep(1);
    printf("|                3-Une fois sorti de jeu ,un pion n'est plus disponible     |\n");
    sleep(1);
    printf("|                4-La perte si tu n'as plus que deux pions,ou bloque        |\n");
    sleep(1);
    printf("|                5-Le double_moulin                                         |\n");
    sleep(1);
    printf("|                                                                           |\n");
    sleep(1);
    printf(reset);
    printf(bleu);
    for (j=0;j<6;j++){
        printf("|                                                                           | \n");
    }
    printf("|___________________________________________________________________________|\n");
    printf(reset);


}