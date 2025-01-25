#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "grille.h"


int menu_jeu() {
    const char *bleu = "\033[1;34m";   
    const char *reset = "\033[0m"; 
    const char *rouge = "\033[1;31m"; 
    printf(bleu);
    printf("                                  _           _            \n");
    printf("                                 | |         (_)           \n");
    printf(" _ __ ___   ___ _ __  _   _    __| |_   _     _  ___ _   _ \n");
    printf("| '_ ` _ \\ / _ \\ '_ \\| | | |  / _` | | | |   | |/ _ \\ | | |\n");
    printf(reset);
    printf(rouge);
    printf("| | | | | |  __/ | | | |_| | | (_| | |_| |   | |  __/ |_| |\n");
    printf("|_| |_| |_|\\___|_| |_|\\__,_|  \\__,_|\\__,_|   | |\\___|\\__,_|\n");
    printf("                                            _/ |           \n");
    printf("                                           |__/            \n");
    printf(reset);
    printf(bleu);
    printf("Entrez votre choix :\n");
    
    
}
