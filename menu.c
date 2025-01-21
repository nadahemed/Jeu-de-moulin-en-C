    #include <stdio.h>
    #include <stdlib.h>
    #include "grille.h"

     


    void menu(){
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
    printf(rouge);
    printf("                        ---------------------------------------------------------------\n");
    printf(reset);
    printf(bleu);
    printf(" _________________________________________________________________________________________________________________\n");
    printf(reset);
    printf(bleu);
    for (i=0;i<4;i++){
        printf("|                                                                                                                 |\n");

    }
    printf(reset);
    printf(rouge);
    printf("|                                       -------                      -------                                      |\n");
    printf("|                                               Effectuez vos choix!!!                                            |\n");
    printf("|                                       -------                      -------                                      |\n");
    printf(reset);
    printf(bleu);
    printf("|                                                                                                                 |\n");
    printf("|                                                                                                                 |\n");
    printf("|                                                                                                                 |\n");
    printf("|                                                                                                                 |\n");
    printf(reset);
    printf(rouge);
    printf("|                                                    1-Jouer                                                      |\n");
    printf(reset);
    printf(rouge);
    printf("|                                                    2-Quitter                                                    |\n");
    printf(reset);
    printf(rouge);
    printf("|                                                    3-Afficher les regles du jeu                                 |           \n");
    printf(reset);
    printf(bleu);
    for (i=0;i<4;i++){
        printf("|                                                                                                                 |\n");

    }
    printf(reset);
    printf(bleu);
    printf(" _________________________________________________________________________________________________________________\n");
    printf(reset);
    }

