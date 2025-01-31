#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include "protomove.h"
#include "grille.h"
#include <stdbool.h>
#include <time.h>
#define taille 24
#define MAX_PIONS 9





int getmachine() {
    int position;
    char board[taille];
    char carac[24][3] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", 
                         "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", 
                         "21", "22", "23"};
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
            if (position == -1) {  
                               printf("Joueur %d (%c) a décidé de quitter le jeu. Merci d'avoir joué !\n", joueurActuel, pionActuel);
                               exit(0);  
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
                break;
            } else if (moulinsO > moulinsX) {
                printf("Le joueur O a gagné avec %d moulins contre %d moulins pour X.\n", moulinsO, moulinsX);
                break;
            } else {
                printf("Match nul ! Les deux joueurs ont formé %d moulins.\n", moulinsX);
                break;
            }

            return 0;
        }

        
        joueurActuel = 3 - joueurActuel; 
    }

    return 0;
}
