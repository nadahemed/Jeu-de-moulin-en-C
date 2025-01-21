#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include "grille.h"
#include "protomove.h"
#include "estbloque.h"
#include "estmoulin.c"
#include "retirerpion.c"
#include "estbloque.c"
#include "jeutermine.c"
#include <stdbool.h>
#include <time.h>
#define taille 24
#define MAX_PIONS 9


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


int getmachine() {
    int position;
    char board[taille];
    int joueurActuel = 1;  
    int PionRestX = MAX_PIONS;
    int PionRestO = MAX_PIONS;
    int movesX = 0;
    int movesO = 0;
    int moulinsX = 0; 
    int moulinsO=0;

    
    for (int i = 0; i < taille; i++) {
        board[i] = '*';
    }

    printf("La grille initiale est : \n");
    Board(board);
    printf("\n");

    while (true) {
        char pionActuel = (joueurActuel == 1) ? 'X' : 'O';
        char pionAdverse = (joueurActuel == 1) ? 'O' : 'X';
        int *PionRestAdverse = (joueurActuel == 1) ? &PionRestO : &PionRestX;
        int *currentMoves = (joueurActuel == 1) ? &movesX : &movesO;

       
        if (*currentMoves >= MAX_PIONS) {
            printf("Joueur %d (%c) ne peut plus placer de pions.\n", joueurActuel, pionActuel);
            joueurActuel = 3 - joueurActuel; 
            continue;
        }

        
        if (joueurActuel == 1) {  
            printf("Joueur %d (%c), entrez une position (0-%d) : ", joueurActuel, pionActuel, taille - 1);
            if (scanf("%d", &position) != 1 || position < 0 || position >= taille) {
                printf("Position invalide. Veuillez entrer un nombre entre 0 et %d.\n", taille - 1);
                while (getchar() != '\n');
                continue;
            }

            
            if (board[position] != '*') {
                printf("La position est déjà occupée. Veuillez choisir une autre position.\n");
                continue;
            }
        } else {  
            srand(time(NULL));  
            
            do {
                position = rand() % taille;
            } while (board[position] != '*');  
            printf("La machine (%c) choisit la position %d.\n", pionActuel, position);
        }

        
        board[position] = pionActuel;
        (*currentMoves)++;
        Board(board);  
        printf("\n");

        
        if (estMoulin(board, position, pionActuel)) {
            printf("Moulin formé par Joueur %d (%c) !\n", joueurActuel, pionActuel);

            
            if (joueurActuel == 1) {
                moulinsX++;
            } else {
                moulinsO++;
            }

            
            retirePion(board, pionAdverse);
            (*PionRestAdverse)--;

            
            if (*PionRestAdverse < 3) {
                printf("Joueur %d (%c) a gagné !\n", joueurActuel, pionActuel);
                return 0;
            }
        }

        
        if (movesX >= MAX_PIONS && movesO >= MAX_PIONS) {
            printf("Les deux joueurs ont épuisé leurs mouvements.\n");

            if (moulinsX > moulinsO) {
                printf("Le joueur X a gagné avec %d moulins contre %d moulins pour O.\n", moulinsX, moulinsO);
            } else if (moulinsO > moulinsX) {
                printf("Le joueur O a gagné avec %d moulins contre %d moulins pour X.\n", moulinsO, moulinsX);
            } else {
                printf("Match nul ! Les deux joueurs ont formé %d moulins.\n", moulinsX);
            }

            return 0;
        }

        // Changement de joueur
        joueurActuel = 3 - joueurActuel; 
    }

    return 0;
}
