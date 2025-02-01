#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include "protomove.h"
#include "grille.h"
#include <stdbool.h>
#include "sauvmch1.c"
#include <time.h>
#define FICHIER_SAUVEGARDE2 "fichiermch.txt"
#define taille 24
#define MAX_PIONS 9

int getmachine() {
    int position;
    char board[taille];
    const char *rouge = "\033[1;31m"; 
    const char *vert = "\033[1;32m";
    const char *bleu = "\033[1;34m";   
    const char *reset = "\033[0m"; 
    const char *rose = "\033[1;35m";    
    const char *violet = "\033[0;35m"; 
    int joueurActuel = 1; // 1 pour le joueur humain, 2 pour la machine
    int PionRestX = MAX_PIONS;
    int PionRestO = MAX_PIONS;
    int movesX = 0;
    int movesO = 0;
    int moulinsX = 0;
    int moulinsO = 0;
    char nomJoueur[50]; // Nom du joueur humain
    bool quitter = false; // Drapeau pour indiquer si le joueur a quitté

    // Initialisation du plateau
    for (int i = 0; i < taille; i++) {
        board[i] = '*';
    }

    // Demander le nom du joueur
    printf(bleu);
    printf("Entrez votre nom : ");
    scanf("%s", nomJoueur);
    printf(reset);

    // Afficher la grille initiale
    printf("La grille initiale est : \n");
    Board(board);
    printf("\n");

    while (!quitter) {
        char pionActuel = (joueurActuel == 1) ? 'X' : 'O';
        char pionAdverse = (joueurActuel == 1) ? 'O' : 'X';
        int *PionRestAdverse = (joueurActuel == 1) ? &PionRestO : &PionRestX;
        int *currentMoves = (joueurActuel == 1) ? &movesX : &movesO;

        // Vérifier si le joueur actuel est en phase de vol
        bool isFlyingPhase = (joueurActuel == 1 && PionRestX == 3) || (joueurActuel == 2 && PionRestO == 3);

        // Tour du joueur humain
        if (joueurActuel == 1) {
            if (isFlyingPhase) {
                printf("%s (%c), vous êtes en phase de vol. Vous pouvez déplacer n'importe quel pion.\n", nomJoueur, pionActuel);
                printf("Entrez la position actuelle du pion à déplacer (0-%d) ou -1 pour quitter : ", taille - 1);
                if (scanf("%d", &position) != 1 || position < -1 || position >= taille) {
                    printf("Position invalide. Veuillez entrer un nombre entre 0 et %d, ou -1 pour quitter.\n", taille - 1);
                    while (getchar() != '\n');
                    continue;
                }

                if (position == -1) {
                    printf("%s (%c) a décidé de quitter le jeu. Merci d'avoir joué !\n", nomJoueur, pionActuel);
                    quitter = true;
                    break;
                }

                // Vérifier si la position actuelle contient un pion du joueur
                if (board[position] != pionActuel) {
                    printf("La position actuelle ne contient pas votre pion. Veuillez réessayer.\n");
                    continue;
                }

                // Demander la nouvelle position
                printf("Entrez la nouvelle position (0-%d) : ", taille - 1);
                if (scanf("%d", &position) != 1 || position < 0 || position >= taille) {
                    printf("Position invalide. Veuillez entrer un nombre entre 0 et %d.\n", taille - 1);
                    while (getchar() != '\n');
                    continue;
                }

                // Vérifier si la nouvelle position est vide
                if (board[position] != '*') {
                    printf("La nouvelle position est déjà occupée. Veuillez choisir une autre position.\n");
                    continue;
                }

                // Déplacer le pion
                board[position] = pionActuel;
            } else {
                printf("%s (%c), entrez une position (0-%d) ou -1 pour quitter : ", nomJoueur, pionActuel, taille - 1);
                if (scanf("%d", &position) != 1 || position < -1 || position >= taille) {
                    printf("Position invalide. Veuillez entrer un nombre entre 0 et %d, ou -1 pour quitter.\n", taille - 1);
                    while (getchar() != '\n');
                    continue;
                }

                if (position == -1) {
                    printf("%s (%c) a décidé de quitter le jeu. Merci d'avoir joué !\n", nomJoueur, pionActuel);
                    quitter = true;
                    break;
                }

                // Vérifier si la position est libre
                if (board[position] != '*') {
                    printf("La position est déjà occupée. Veuillez choisir une autre position.\n");
                    continue;
                }

                // Placer le pion
                board[position] = pionActuel;
                (*currentMoves)++;
            }
        }
        // Tour de la machine (joueur 2)
        else {
            if (isFlyingPhase) {
                // Phase de vol : déplacer un pion existant
                do {
                    position = rand() % taille; // Choisir une position aléatoire
                } while (board[position] != pionActuel); // Trouver un pion de la machine
                printf("La machine (%c) déplace un pion de la position %d.\n", pionActuel, position);

                int nouvellePosition;
                do {
                    nouvellePosition = rand() % taille; // Choisir une nouvelle position aléatoire
                } while (board[nouvellePosition] != '*'); // Trouver une position vide
                printf("La machine (%c) déplace le pion vers la position %d.\n", pionActuel, nouvellePosition);

                // Déplacer le pion
                board[position] = '*';
                board[nouvellePosition] = pionActuel;
            } else {
                // Phase normale : placer un nouveau pion
                do {
                    position = rand() % taille; // Choisir une position aléatoire
                } while (board[position] != '*'); // Trouver une position vide
                printf("La machine (%c) choisit la position %d.\n", pionActuel, position);

                // Placer le pion
                board[position] = pionActuel;
                (*currentMoves)++;
            }
        }

        // Afficher le plateau après chaque tour
        Board(board);
        printf("\n");

        // Vérifier si un moulin est formé
        if (estMoulin(board, position, pionActuel)) {
            printf("Moulin formé par %s (%c) !\n", (joueurActuel == 1) ? nomJoueur : "La machine", pionActuel);

            // Mettre à jour le compteur de moulins
            if (joueurActuel == 1) {
                moulinsX++;
            } else {
                moulinsO++;
            }

            // Retirer un pion adverse
            if (joueurActuel == 1) {
                int posAdverse;
                while (true) {
                    printf("Choisissez une position de la machine (%c) à retirer : ", pionAdverse);
                    if (scanf("%d", &posAdverse) != 1 || posAdverse < 0 || posAdverse >= taille) {
                        printf("Position invalide. Veuillez entrer un nombre entre 0 et %d.\n", taille - 1);
                        while (getchar() != '\n');
                        continue;
                    }

                    if (board[posAdverse] == pionAdverse) {
                        board[posAdverse] = '*';
                        printf("Pion de la machine retiré à la position %d.\n", posAdverse);
                        (*PionRestAdverse)--;
                        break;
                    } else {
                        printf("La position choisie n'est pas occupée par un pion adverse.\n");
                    }
                }
            } else {
                // La machine retire un pion adverse aléatoirement
                int posAdverse;
                do {
                    posAdverse = rand() % taille; // Choisir une position aléatoire
                } while (board[posAdverse] != pionAdverse); // Trouver un pion adverse
                printf("La machine (%c) retire un pion adverse à la position %d.\n", pionActuel, posAdverse);
                board[posAdverse] = '*';
                (*PionRestAdverse)--;
            }

            // Vérifier si l'adversaire a moins de 3 pions
            if (*PionRestAdverse < 3) {
                printf("%s (%c) a gagné !\n", (joueurActuel == 1) ? nomJoueur : "La machine", pionActuel);
                return 0;
            }
        }

        // Vérifier si les deux joueurs ont épuisé leurs mouvements
        if (movesX >= MAX_PIONS && movesO >= MAX_PIONS) {
            printf("Les deux joueurs ont épuisé leurs mouvements.\n");

            if (moulinsX > moulinsO) {
                printf("%s (X) a gagné avec %d moulins contre %d moulins pour O.\n", nomJoueur, moulinsX, moulinsO);
            } else if (moulinsO > moulinsX) {
                printf("La machine (O) a gagné avec %d moulins contre %d moulins pour X.\n", moulinsO, moulinsX);
            } else {
                printf("Match nul ! Les deux joueurs ont formé %d moulins.\n", moulinsX);
            }

            return 0;
        }

        // Passer au joueur suivant
        joueurActuel = 3 - joueurActuel;
    }

    return 0;
}






