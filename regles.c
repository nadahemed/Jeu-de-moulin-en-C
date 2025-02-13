#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "grille.h"

#include <stdio.h>
#include <unistd.h> // Pour sleep()

void regles() {
    int j;
    const char *rouge = "\033[1;31m"; 
    const char *vert = "\033[1;32m";
    const char *bleu = "\033[1;34m";  
    const char *reset = "\033[0m"; 
    const char *rose = "\033[1;35m";    
    const char *violet = "\033[0;35m"; 

    printf(bleu);
printf(" .______       _______   _______  __       _______     _______.   \n");
printf("|   _  \\     |   ____| /  _____||  |     |   ____|   /       |   \n");
printf("|  |_)  |    |  |__   |  |  __  |  |     |  |__     |   (----`   \n");
printf(reset);
printf(rouge);
printf("|      /     |   __|  |  | |_ | |  |     |   __|     \\   \\       \n");
printf("|  |\\  \\----.|  |____ |  |__| | |  `----.|  |____.----)   |      \n");
printf("| _| `._____||_______| \\______| |_______||_______|_______/       \n");
printf(reset);


    printf(rouge);
    printf(" ____________________________________________________________________________\n");
    for (j = 0; j < 6; j++) {
        printf("|                                                                           |\n");
    }
    printf("|                          RÈGLES DU JEU DU MOULIN                          |\n");
    sleep(1);
    printf("|                                                                           |\n");
    
    // Titre en bleu, texte en couleur précédente
    printf("| %s1- OBJECTIF :%s                                                             |\n", bleu, reset);
    printf("|    Aligner trois pions pour former un 'Moulin' et retirer un pion adverse.|\n");
    
    sleep(1);
    printf("|                                                                           |\n");

    // Titre en rouge, texte en couleur précédente
    printf("| %s2- PHASE DE POSE :%s                                                        |\n", rouge, reset);
    printf("|    - Chaque joueur place à tour de rôle un pion sur une case vide.        |\n");
    printf("|    - Lorsqu'un 'Moulin' est formé (3 pions alignés),                      |\n");
    printf("|      le joueur peut retirer un pion adverse qui n'est pas dans un Moulin. |\n");
    sleep(1);
    printf("|                                                                           |\n");

    // Titre en bleu, texte en couleur précédente
    printf("| %s3- PHASE DE DÉPLACEMENT :%s                                                 |\n", bleu, reset);
    printf("|    - Une fois tous les pions placés,chaque joueur peut déplacer ses pions.|\n");
    printf("|    - Un pion ne peut se déplacer que vers une case adjacente libre.       |\n");
    printf("|    - Si un 'Moulin' est formé après un déplacement,                       |\n");
    printf("|      un pion adverse peut être retiré.                                    |\n");
    sleep(1);
    printf("|                                                                           |\n");

    // Titre en rouge, texte en couleur précédente
    printf("| %s4- PHASE DE VOL :%s                                                         |\n", rouge, reset);
    printf("|    - Si un joueur ne possède plus que 3 pions, il peut 'voler'.           |\n");
    printf("|    - Il peut déplacer ses pions n'importe où sur le plateau.              |\n");
    printf("|    - Cette règle permet un dernier espoir avant la défaite.               |\n");
    sleep(1);
    printf("|                                                                           |\n");

    // Titre en bleu, texte en couleur précédente
    printf("| %s5- CONDITION DE VICTOIRE :%s                                                |\n", bleu, reset);
    printf("|    - Un joueur perd s'il ne peut plus bouger ses pions.                   |\n");
    printf("|    - Un joueur perd s'il lui reste seulement 2 pions.                     |\n");
    sleep(1);
    printf("|                                                                           |\n");

    // Titre en rouge, texte en couleur précédente
    printf("| %s6- RÈGLE DU DOUBLE MOULIN :%s                                               |\n", rouge, reset);
    printf("|    - Si un joueur forme deux Moulins en un seul mouvement,                |\n");
    printf("|      il peut retirer deux pions adverses.                                 |\n");
    sleep(1);
    printf("|                                                                           |\n");

    printf("|___________________________________________________________________________|\n");
    printf(reset);
}

