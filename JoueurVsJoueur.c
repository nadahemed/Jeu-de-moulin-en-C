#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include "grille.h"
#include "protomove.h"
#include "estbloque.h"
#include "estmoulin.c"
#include "retirerpion.c"
#include "estbloque.c"
#include <stdbool.h>
#include <time.h>
#define taille 24
#define MAX_PIONS 9
#define TIME_LIMIT 30



void Board(char board[]){
    const char *rouge = "\033[1;31m"; 
    const char *vert = "\033[1;32m";
    const char *bleu = "\033[1;34m";   
    const char *reset = "\033[0m"; 
    const char *rose = "\033[1;35m";    
    const char *violet = "\033[0;35m"; 
    int i;
    printf(rouge);
    printf("%c",board[0]);
    printf(reset);
    printf(bleu);
    for(i=0;i<3;i++){
        
        printf("-----------------");
        
        
        
    }
    printf(reset);
    printf(rouge);
    printf("%c",board[1]);
    printf(reset);
    printf(bleu);
    for(i=0;i<3;i++){
        
         printf("-----------------");
        
    }
    printf(reset);
    printf(rouge);
    printf("%c",board[2]);
    printf(reset);
    printf("\n");
    printf(bleu);
    for (i=0;i<4;i++){
        printf("|                                                   |                                                   |\n");
        

    }
    printf(reset);
        printf(rouge);
        printf("|                             %c---------------------%c-----------------------%c                           |\n",board[3],board[4],board[5]);
        printf(reset);
        printf(bleu);
        for(i=0;i<2;i++){
            printf("|                             |                     |                       |                           |\n");

        }
        printf(rouge);
        printf("|                             |        %c------------%c-----------%c           |                           |\n",board[6],board[7],board[8]);
        printf(reset);
        printf(bleu);
        for(i=0;i<4;i++){
            printf("|                             |        |                        |           |                           |\n");

        }
        printf(rouge);
        printf("%c-----------------------------%c--------%c                        %c-----------%c---------------------------%c\n",board[9],board[10],board[11],board[12],board[13],board[14]);
        printf(reset);
        printf(bleu);
        for(i=0;i<4;i++){
            printf("|                             |        |                        |           |                           |\n");

        }
        printf(reset);
        printf(rouge);
        printf("|                             |        %c------------%c-----------%c           |                           |\n",board[15],board[16],board[17]);
        printf(reset);
        printf(bleu);
        for(i=0;i<2;i++){
            printf("|                             |                     |                       |                           |\n");

        }
        printf(reset);
        printf(rouge);
         printf("|                             %c---------------------%c-----------------------%c                           |\n",board[18],board[19],board[20]);
        printf(reset);
        printf(bleu);
         for (i=0;i<4;i++){
        printf("|                                                   |                                                   |\n");
        

    }
    printf(reset);
    printf(rouge);
    printf("%c",board[21]);
    printf(reset);
    printf(bleu);
    for(i=0;i<3;i++){
        
        printf("-----------------");
        
        
        
    }
    printf(rouge);
    printf("%c",board[22]);
    printf(reset);
    printf(bleu);
    for(i=0;i<3;i++){
        
         printf("-----------------");
        
    }
    printf(reset);
    printf(rouge);
    printf("%c",board[23]);

}


int getposition() {
    int position;
    char board[taille]; 
    int joueurActuel = 1; // 1 pour Joueur 1, 2 pour Joueur 2
    int PionRestX = MAX_PIONS;
    int PionRestO = MAX_PIONS;
    int movesX = 0; // Nombre de positions saisies par Joueur 1
    int movesO = 0; // Nombre de positions saisies par Joueur 2

    // Initialisation de la grille
    for (int i = 0; i < taille; i++) {
        board[i] = '*';
    }

    printf("La grille initiale est : \n");
    Board(board);
    printf("\n");

    // Boucle principale du jeu
    while (true) {
        char pionActuel = (joueurActuel == 1) ? 'X' : 'O';
        char pionAdverse = (joueurActuel == 1) ? 'O' : 'X';
        int *PionRestAdverse = (joueurActuel == 1) ? &PionRestO : &PionRestX;
        int *currentMoves = (joueurActuel == 1) ? &movesX : &movesO;

        // Vérifier si le joueur a atteint la limite de 9 mouvements
        if (*currentMoves >= 9) {
            printf("Joueur %d (%c) ne peut plus placer de pions.\n", joueurActuel, pionActuel);
            joueurActuel = (joueurActuel == 1) ? 2 : 1; // Passer au joueur suivant
            continue;
        }

        printf("Joueur %d (%c), entrez une position (0-23) : ", joueurActuel, pionActuel);
        if (scanf("%d", &position) != 1 || position < 0 || position >= taille) {
            printf("Position invalide. Veuillez entrer un nombre entre 0 et 23.\n");
            while (getchar() != '\n'); // Vider le tampon
            continue;
        }

        if (board[position] != '*') {
            printf("La position est déjà occupée. Veuillez choisir une autre position.\n");
            continue;
        }

        // Placer le pion sur la grille
        board[position] = pionActuel;
        (*currentMoves)++; // Incrémenter le compteur de mouvements du joueur
        Board(board);
        printf("\n");

        // Vérifier si un moulin est formé
        if (estMoulin(board, position, pionActuel)) {
            printf("Moulin formé par Joueur %d (%c) !\n", joueurActuel, pionActuel);

            // Retirer un pion adverse
            retirePion(board, pionAdverse);
            (*PionRestAdverse)--; // Décrémenter le nombre de pions adverses

            // Vérifier si l'adversaire a moins de 3 pions
            if (*PionRestAdverse < 3) {
                printf("Joueur %d (%c) a gagné ! Joueur %d (%c) n'a plus que %d pions.\n",
                       joueurActuel, pionActuel, (joueurActuel == 1) ? 2 : 1, pionAdverse, *PionRestAdverse);
                return 0; // Fin du jeu
            }
        }

        // Vérifier si les deux joueurs ont utilisé leurs 9 positions
        if (movesX >= 9 && movesO >= 9) {
            printf("Le jeu est terminé. Aucune victoire déterminée après 9 tours pour chaque joueur.\n");
            return 0; // Fin du jeu
        }

        // Passer au joueur suivant
        joueurActuel = (joueurActuel == 1) ? 2 : 1;
    }

    return 0;
}

